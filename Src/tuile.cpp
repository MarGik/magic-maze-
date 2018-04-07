#include "tuile.hpp"
#include "couleurs.hpp"

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <cstring>



namespace MMaze {

    /*
+---+---+---+---+
| 0 | 1 | 2 | 3 |
+---+---+---+---+
| 4 | 5 | 6 | 7 |
+---+---+---+---+
| 8 | 9 | 10| 11|
+---+---+---+---+
| 12| 13| 14| 15|
+---+---+---+---+

     */
Tuile::Tuile() {

    tuile_tab=(char*) (malloc(16 * sizeof(case_tuile)));
    mur_tab  =(char*) (malloc(24* sizeof(Mur)));
}





void Tuile::generateTuileDepart()   {

    for (int i = 0; i <16; ++i) {
        case_tuile c_t;
        c_t.ca  = new Case(i);
            switch (i) {
                case 2 :{
                    c_t.f=porte;
                    c_t.color=ORANGE;
                    break;
                }
                case 4 :{
                    c_t.f=porte;

                    c_t.color=VIOLET;
                    break;
                }
                case 11 :{
                    c_t.f=porte;
                    c_t.color=VERT;
                    break;
                }
                case 13 :{
                    c_t.f=porte;
                    c_t.color=JAUNE;
                    break;
                }
                default : {
                    c_t.f = norm;
                    c_t.color=AUCUNE;
                    break;
                }

            }

        c_t.index_=i;


        memcpy(tuile_tab+i* sizeof(case_tuile),&c_t,sizeof(case_tuile));
        delete c_t.ca;
    }


/*        for (int j = 0; j <4; ++j) {
            for (int i = 1; i < 4; ++i) {

                Mur * mV = new Mur(*(Case*)(tuile_tab+(i-1)+(j*4)),*(Case*)(tuile_tab+(i)+(j*4)));//case c0,c1
                memcpy(mur_tab+(12+j+(i-1)*4)* sizeof(Mur),mV, sizeof(Mur));
               //1-5 2-6 5-9 6-10 9-13 10-14
            }
        }
*/
}





void Tuile::generateTuileClasique() {
    Melangeur * m = new Melangeur (sizeof(Case));
    //insertion dans un melangeur touts les endroit ou on peut placer des portes
    //  //0 1 2 3 4 7 8 11 12 13 14 15
    unsigned int array[] = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};

    Melangeur * mP = new Melangeur(sizeof(unsigned int));
    for (int j = 0; j <12; ++j) {
        mP->inserer(&array[j]);
    }

    mP->afficher();

    //insertion des cases dans melangeur
    for (int i = 0; i <16; ++i) {
        case_tuile c_t;
        int nb_portes = (rand()%4)+1;
        while(nb_portes >0){
            if(nb_portes==1){
                c_t.f=porte;
                c_t.color=AUCUNE;
            }
            if(mP->taille_reelle>0){
                void * elem = malloc(sizeof(unsigned int));
                mP->retirer(elem); //de corectat
                c_t.index_=*((unsigned int *) elem);
                free(elem);
            }
            c_t.color=Couleur(rand()%4 +1);
            nb_portes--;
        }
        m->inserer(&c_t);
  //      m->afficher();
    }

    //generation de la tuile
    for (int j = 0; j <16; ++j) {
        //Case * c;
        std::cout << "stoped\n";
        case_tuile c_t;
        m->retirer(&c_t);
        memcpy(tuile_tab+j* sizeof(case_tuile),&c_t,sizeof(case_tuile));
    }



}

bool Tuile::mur(Mur m) const {
  /* remplacez ce code */


  return 1 ;
}

bool Tuile::accessible(Case c) const {
  /* remplacez ce code */
  return false ;
}

void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
  assert(i < 5) ;
  if(i == 0 || i == 4) {
    out << "+---+---+---+---+" ;

  } else {
    out << "+" ;
    for(unsigned int m = 0; m < 4; ++m) {
      Case up = Case(i-1, m) ;
      Case down = Case(i, m) ;
      if(mur(Mur(up, down))) {
        out << "---+" ;
      } else {
          out << "   +";
      }
    }
  }

}

void Tuile::afficher_vertical(std::ostream& out, unsigned int i) const {
  assert(i < 4) ;
  out << "|" ;
  for(unsigned int m = 0; m < 4; ++m) {
    out << "   " ;
    if(m < 3) {
      Case left = Case(i, m) ;
      Case right = Case(i, m+1) ;
      if(m < 3 && mur(Mur(left, right))) {
        out << "|" ;
      } else {
        out << " " ;
      }
    }
  }
  out << "|" ;
}

std::ostream& operator<< (std::ostream& out, const Tuile& t) {
  for(unsigned int i = 0; i < 4; ++i) {
    t.afficher_horizontal(out, i) ;
    out << std::endl ;
    t.afficher_vertical(out, i) ;
    out << std::endl ;
  }
  t.afficher_horizontal(out, 4) ;
  return out ;
}

    Tuile::~Tuile() {
        free(mur_tab);
        free(tuile_tab);
    }

    void Tuile::generateMur(bool b) {
        if(b){//tuile depart
            
        }else{//tuile clasique

        }
    }

} //end of namespace MMaze
