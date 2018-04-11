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
            //c_t.ca  = new Case(i);
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

        Melangeur * mP = new Melangeur(sizeof(unsigned int));   //pour definir les places pour les portes
        for (int j = 0; j <3; ++j) {
            mP->inserer(&array[j]);
        }


        Melangeur *mC= new Melangeur(sizeof(unsigned int));
        for (int j = 1; j <5; ++j) {    //1 2 3 4 sont les couleurs pour les portes
            mC->inserer(&j);
        }


        //on peux avoir de 1 a 3 portes

        case_tuile c_t;

        int nb_portes = (rand() % 3) +1  ;
        cout<<"NB PORTES"<<nb_portes<<endl;

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
         //   cout << c_t.index_ << "index \n ";


          //  c_t.color = Couleur(rand() % 4 + 1);
            int index_color;
            mC->retirer(&index_color);
           // cout<<"TAILLE EST"<<mC->taille()<<endl;
            c_t.color=Couleur (index_color);
           // mC->retirer(&index_color);


            c_t.ca = new Case(c_t.index_);
            memcpy(tuile_tab + c_t.index_ * sizeof(case_tuile), &c_t, sizeof(case_tuile));
        }

       // c_t.color = AUCUNE;
        c_t.color =LIGHTGREY;
        c_t.f = entree;
        c_t.ca = new Case(11);
        memcpy(tuile_tab + 11 * sizeof(case_tuile), &c_t, sizeof(case_tuile));

        delete c_t.ca;


        int * gen=(int*)malloc(16* sizeof(int));
        for (int k = 0; k <16; ++k) {
            gen[k]=k;
        }

        generateMur(gen);
 //       generateMur(gen);
        free(gen);

        free(mP);
        free(mC);
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

                if (c_t.f == porte || c_t.f==entree) {


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

   /* c_t.color = AUCUNE;
    c_t.f = entree;
    c_t.ca = new Case(11);
    memcpy(tuile_tab + 11 * sizeof(case_tuile), &c_t, sizeof(case_tuile));*/
}

bool Tuile::mur(Mur m) const {
if(m.index()==12 ||m.index()==20 || m.index()==8){
    return 1;
}
  return 0;     //tous les murs existent
}



bool Tuile::accessible(Case c) const {

  /* remplacez ce code */
  return false ;
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

    void Tuile::generateMur(int * tabCase) {

        Melangeur * mMur = new Melangeur (sizeof(Case));




        for (int i = 0; i <16; ++i) {
           // mur[i]=Mur(i);

          tabCase[i]=i;
        }


        case_tuile c_t_depart;
        int arr [] = {2,4,11,13};
        for (int i = 0; i <4; ++i) {

            for (int j = 0; j <16; ++j) {

                case_tuile c_t_arrive;

                memcpy(&c_t_depart,tuile_tab+arr[i]* sizeof(case_tuile), sizeof(case_tuile));

                memcpy(&c_t_arrive,tuile_tab+(j)* sizeof(case_tuile), sizeof(case_tuile));
                std::cout << c_t_depart.index_ << "xa,ya " << c_t_arrive.index_ << std::endl;

                //if(c_t_depart.f==porte || c_t_depart.f==entree) {
                        int x = find(tabCase, c_t_depart.index_);
                        int y = find(tabCase, c_t_arrive.index_ % 4);
                        std::cout << x << "x,y " << y << std::endl;
                      //  if (x == y) break;
                        Union(tabCase, x, y);
                  //  }
            }
        }


       Mur mur(0);
        for (int j = 0; j <16; ++j) {
            //for (int i = 0; i <4; ++i) {
               /* std::cout<<tabCase[j]<<" ";
                Case c1=Case(j);
                Case c2=Case(k);
                mur[i]=Mur()
*/
            }
            std::cout<<std::endl;
        }
    }

    int Tuile::find(int *classe_equiv, int case_equiv) {
        if (classe_equiv[case_equiv] != case_equiv)
            classe_equiv[case_equiv] = find(classe_equiv,classe_equiv[case_equiv]);

        return classe_equiv[case_equiv];



    }


    void Tuile::Union(int * tabCase,int x , int y ){
        int start  = find(tabCase,x);
        int finish = find(tabCase,y);
        if(tabCase[start]<tabCase[finish])
            tabCase[start]=finish;
        else if (tabCase[start]>=tabCase[finish])
            tabCase[finish]=start;

      /*  for (int i = 0; i <4; ++i) {
            for (int j = 0; j <4; ++j) {
                std::cout << tabCase[j+i*4] << " ";
            }
            std::cout << "\n";
        }
        */
    }

    /*UNION FIND*/
    // union - connects two objects - https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
    // find - is there a path to get from 1 to 2?






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

    void Tuile::rotationDroite() {

        int SIZE=4;
        char * nw = (char*) (malloc(16 * sizeof(case_tuile)));
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                memcpy(nw+(((SIZE-row-1) + col*SIZE)*sizeof(case_tuile)),tuile_tab+((col+row*SIZE)* sizeof(case_tuile)),
                       sizeof(case_tuile) );
            }
        }
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                memcpy(tuile_tab+((col+row*SIZE)* sizeof(case_tuile)),nw+((col + row*SIZE)*sizeof(case_tuile)), sizeof(case_tuile));
            }
        }

        bool isMur[24];
        for (int i=0 ; i<24 ; i++) {
            isMur[i] = tab_mur[i];
        }
        for (int i=0 ; i<24 ; i++){
            int add=0;
            if(i<12) {
                if(i%4==0)
                    add=15;
                else if(i%4==1)
                    add=13;
                else if(i%4==2)
                    add=11;
                else if(i%4==3)
                    add=9;
            }
            else if(i<16)
                add=-4;
            else if(i<20)
                add=-12;
            else if(i<24)
                add=-20;

            if(isMur[(i+add)%24])
                tab_mur[i]=1;
            else
                tab_mur[i]=0;
        }

    }

    void Tuile::rotationGauche() {

        int SIZE=4;
        char * nw = (char*) (malloc(16 * sizeof(case_tuile)));
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                memcpy(nw+((col + row * SIZE)*sizeof(case_tuile)),tuile_tab+((SIZE-row-1+col*SIZE)* sizeof(case_tuile)),
                       sizeof(case_tuile) );
            }
        }
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                memcpy(tuile_tab+((col+row*SIZE)* sizeof(case_tuile)),nw+((col + row*SIZE)*sizeof(case_tuile)), sizeof(case_tuile));
            }
        }
        bool isMur[24];
        for (int i=0 ; i<24 ; i++)
        {
            isMur[i] = tab_mur[i];
        }
        for (int i=0 ; i<24 ; i++){
            int add=0;
            if(i<4)
                add=20;
            else if(i<8)
                add=12;
            else if(i<12)
                add=4;
            else if(i%4==0)
                add=-9;
            else if(i%4==1)
                add=-11;
            else if(i%4==2)
                add=-13;
            else if(i%4==3)
                add=-15;

            if(isMur[i+add])
                tab_mur[i]=1;
            else
                tab_mur[i]=0;
        }

    }



} //end of namespace MMaze
