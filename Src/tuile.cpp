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

    tuile_tab=(char*) (malloc(16 * sizeof(Case)));
    mur_tab  =(char*) (malloc(24* sizeof(Mur)));
}





void Tuile::generateTuileDepart()   {

    for (int i = 0; i <16; ++i) {
        Case * c = new Case(i);
        memcpy(tuile_tab+i* sizeof(Case),c,sizeof(Case));
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
    //insertion des cases dans melangeur
    for (int i = 0; i <16; ++i) {
        Case * c = new Case(i);
        m->inserer(&c);
        delete c;
    }

    for (int j = 0; j <16; ++j) {
        Case * c;
        m->retirer(&c);
        memcpy(tuile_tab+j* sizeof(Case),c,sizeof(Case));
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
        out << "   +" ;
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


}

} //end of namespace MMaze
