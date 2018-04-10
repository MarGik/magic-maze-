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
        tab_mur  =(int*) (malloc(24* sizeof(int)));
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
            c_t.ca = new Case(i);


            memcpy(tuile_tab+i* sizeof(case_tuile),&c_t,sizeof(case_tuile));
            delete c_t.ca;
        }

    }





    void Tuile::generateTuileClasique() {
         unsigned int array[] = {2, 4, 13};

        Melangeur * mP = new Melangeur(sizeof(unsigned int));
        for (int j = 0; j <3; ++j) {
            mP->inserer(&array[j]);
        }
        //on peux avoir de 1 a 3 portes
        int nb_portes = (rand() % 2) +1  ;

        for (int i = 0; i <16; ++i) {

            case_tuile c_t;
            // creation des portes avec couuleurs
            cout << "norm\n";
            c_t.f=norm;
            c_t.color=AUCUNE;
            c_t.index_=i;
            c_t.ca = new Case(i);
            memcpy(tuile_tab + i * sizeof(case_tuile), &c_t, sizeof(case_tuile));

            }

        for (int i = 0; i <nb_portes; ++i) {
            c_t.f = porte;
            mP->retirer(&c_t.index_);
            cout << c_t.index_ << "index \n ";//de corectat
            c_t.color = Couleur(rand() % 4 + 1);
            c_t.ca = new Case(c_t.index_);
            memcpy(tuile_tab + c_t.index_ * sizeof(case_tuile), &c_t, sizeof(case_tuile));
        }
       // c_t.color = AUCUNE;
        c_t.color =LIGHTGREY;
        c_t.f = entree;
        c_t.ca = new Case(11);
        memcpy(tuile_tab + 11 * sizeof(case_tuile), &c_t, sizeof(case_tuile));
    }

    bool Tuile::mur(Mur m) const {
      /* remplacez ce code */


      return 1 ;
    }

    bool Tuile::accessible(Case c) const {
      /* remplacez ce code */
      return false ;
    }


    void Tuile::backgroundcolor(std::ostream& out, Couleur c) const {

        switch(c){
            case(JAUNE): out<<BG_JAUNE;
                break;
            case(VERT): out<<BG_VERT;
                break;
            case(ORANGE):out<<BG_ORANGE;
                break;
            case(VIOLET): out<<BG_VIOLET;
                break;
            case(LIGHTGREY): out<<BG_LIGHTGREY;
                break;
            case(AUCUNE):out<<BG_DEFAULT;
                break;
        }

    }



    void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
        assert(i < 5) ;

        case_tuile c_t;
        out << "+";
       for (int j = 0; j <4; ++j)
       {     memcpy(&c_t, tuile_tab + ((j+i*4) * sizeof(case_tuile)), sizeof(case_tuile));


            if(i==0 || i==4) {

                if(i==4){
                    memcpy(&c_t, tuile_tab + ((j+3*4)* sizeof(case_tuile)), sizeof(case_tuile));
                }

                if (c_t.f == porte) {

                    backgroundcolor(out, c_t.color);
                    out << "---";
                    out << BG_DEFAULT << "+";
                } else {
                    out << "---+";
                }
            }


            else {

                int m=j;
                Case up = Case(i - 1, m);
                Case down = Case(i, m);
                if (mur(Mur(up, down))) {
                    out << "---+";
                } else {
                    out << "   +";
                }

            }
        }
    }



    void Tuile::afficher_vertical(std::ostream& out, unsigned int i) const {
      assert(i < 4) ;

        case_tuile c_t;
        memcpy(&c_t, tuile_tab + ((0+i*4) * sizeof(case_tuile)), sizeof(case_tuile));
        if (c_t.f == porte) {

            backgroundcolor(out, c_t.color);
            out << "|";
            out << BG_DEFAULT ;
        }
        else{
            out << "|" ;
        }


        for (int j = 0; j <4; ++j) {
            memcpy(&c_t, tuile_tab + ((j+i*4) * sizeof(case_tuile)), sizeof(case_tuile));





            int m=j;
            out << "   " ;
            if(m < 3) {
              Case left = Case(i, m) ;
              Case right = Case(i, m+1) ;
              if(m < 3 && mur(Mur(left, right))) {



                      out << "|" ;
                  }



               else {
                out << " " ;
              }
            }
      }
      //out << "|" ;

        memcpy(&c_t, tuile_tab + ((3+i*4) * sizeof(case_tuile)), sizeof(case_tuile));
        if (c_t.f == porte || c_t.f==entree ) {

            backgroundcolor(out, c_t.color);
            out << "|";
            out << BG_DEFAULT;
        }

        else{
            out << "|" ;
        }
    }




    std::ostream& operator<< (std::ostream& out, const Tuile& t) {
        for (unsigned int i = 0; i < 4; ++i) {
            t.afficher_horizontal(out, i);
            out << std::endl;

            for (int k = 0; k < 4; ++k) {
                case_tuile c_t;
                memcpy(&c_t, (t.tuile_tab + (k + i * 4) * sizeof(case_tuile)), sizeof(case_tuile));
                //std::cout << c_t.f << "+";
            }
            t.afficher_vertical(out, i);
            std::cout<<endl;

        }
        t.afficher_horizontal(out, 4);
        std::cout<<endl;


        //affichage de fonction d'une case
        std::cout<<"affichage de fonction de chaque case"<<endl;

        for (unsigned int i = 0; i < 4; ++i) {

            for (int k = 0; k < 4; ++k) {
                case_tuile c_t;
                memcpy(&c_t, (t.tuile_tab + (k + i * 4) * sizeof(case_tuile)), sizeof(case_tuile));
                std::cout << c_t.f << "   ";
            }
            std::cout<<endl;

        }
            return out;

    }

    Tuile::~Tuile() {
        free(tab_mur);
        free(tuile_tab);
    }

    void Tuile::generateMur() {

//
//
//
//    Melangeur * m = new Melangeur (sizeof(Case));
//
//        for (int i=0 ; i<24; i++){
//            tab_mur[i]=1;
//            cout<<tab_mur[i]<<" ";
//
//        }
//        std::cout<<endl;
//
//        for(int i=0; i<24; i++){
//            Mur mur(i); //construction d'un mur
//            m-> inserer(&mur); //ajout de mur en melangeur
//        }
//
//        bool arreter = false;
//
//        //il faut casser les murs jusqu'a la chemin est bon
//
//        while(arreter==false) {
//            case_tuile c_t;
//
//            arreter=true;
//            Mur mur(0);
//            m->retirer(&mur);
//            tab_mur[mur.index()]==0;
//            int case1= mur[0].index();
//            int case2 = mur[1].index();
//
//            case1=find(case1, tuile_tab);
//            case2=find(case2, tuile_tab);
//            c_t[case1]=c_t[case2];
//
//            int var=-1;
//
//            for (int i=0; i<16; i++){
//
//                if (site[i]!=0)
//                {
//                    if (var <0)
//                        var=find (i, c_t);
//
//
//
//                    if (find (i, c_t)!=var);
//                        arreter=false;
//                    break;
//                }
//        }
//
//
//

    }


    /*UNION FIND*/
    // union - connects two objects - https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
    // find - is there a path to get from 1 to 2?



    int Tuile:: find(int classe_equiv[], int case_equiv)
    {
        if (classe_equiv[case_equiv] != case_equiv)
            classe_equiv[case_equiv] = find(classe_equiv,classe_equiv[case_equiv] );

        return classe_equiv[case_equiv];
    }



    void Tuile::ecrireDansFichier() {
        //verification de non existance du fichier
        std::string fileName="";
        std::cout << "Give a name to your file .txt\n";
        std::cin >> fileName;
        std::ifstream test(fileName);
         while(test.good()){
             std::cout << "File exists, give another name  \n";
             std::cin >> fileName;
             std::ifstream test(fileName.c_str());

         };
        std::ofstream myFile;
        myFile.open(fileName,ios::out);
        myFile<<"tuile\n";
        for (int i = 0; i <24; ++i) {
            if (tab_mur[i]) {
                myFile << "mur " << i << "\n";
            }
        }
        for (int i = 0; i < 16; ++i) {

            case_tuile c_t;
            c_t =*(case_tuile*) (tuile_tab + (i* sizeof(case_tuile)));
            myFile<<"site "<< c_t.index_ <<" ";
            switch (c_t.f){
                case entree:{
                    myFile<<"entree ";
                    break;
                }
                case norm:{
                    myFile<<"case vide ";
                    break;
                }
                case porte:{
                    myFile<<"port ";
                    break;
                }
                case point_depart:{
                    myFile<<"point_depart ";
                    break;
                }
                case teleport:{
                    myFile<<"teleport ";
                    break;
                }
                case sortie:{
                    myFile<<"sortie ";
                    break;
                }
                default: break;
            }
            myFile<<c_t.color<<"\n";
        }

        myFile<<"fin\n";
        myFile.close();
    }


} //end of namespace MMaze
