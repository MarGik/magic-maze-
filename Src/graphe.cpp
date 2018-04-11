#include "graphe.hpp"
#include "tuile.hpp"
#include "case.hpp"
#include "mur.hpp"

#include <vector>
#include <iostream>
#include "melangeur.hpp"
#include <fstream>
#include <string>
#include <iomanip>


class c_g;
namespace MMaze {



     Graphe:: Graphe (Tuile &tuile) {


         for (int i = 0; i < 16; i++) {
             cases_graphe_gauche[i] = *(new std::vector<int>());
             cases_graphe_droite[i] = *(new std::vector<int>());
             cases_graphe_haut[i] = *(new std::vector<int>());
             cases_graphe_bas[i] = *(new std::vector<int>());
         }




         //int j = 0;
         for (int i = 0; i < 16; i++) {

             cout<<"-----------"<<endl;
             Case ca = Case(i); //on copie une case de tuile  ds  case


             //il faut compter les coup de gauche a partir de chaque case jusqu'au mur
             //tels que
             //pour case , notre vector va avoir : toutes  les cases joignables jusqu'au mur dans une direction



             //pour bien verifier, que la fonction renvoie error, il faut utiliser try.....catch
             //comme expliquee ici : https://msdn.microsoft.com/en-us/library/hh279678.aspx

             //pour gauche:
             //jusqua le mur n'est pas atteint
             // on fait
             // try
             //extraire indice (coup de chemin)
             //if error - catch
             //faire rien - finir




             //coup de gauche

//          -----------GAUCHE-------------


             cout << "GAUCHE" << endl;

             try {

                 while (!tuile.mur(Mur(ca, ca.gauche()))) {
                     cases_graphe_gauche[i].push_back(ca.gauche().index());
                     cout << "CAS : pas de mur " << ca.gauche().index() << endl;
                     ca = ca.gauche();

                 }
                 if (tuile.mur(Mur(ca, ca.gauche())) == 1) {
                     cout << "CAS : mur a cote " << endl;
                 }

             }
             catch (std::domain_error err) {
                 cout << "CAS : domaine error" << endl;
             }



//          -----------DROITE-------------
             //indice de tab de coups
             cout << "DROITE" << endl;
             ca = Case(i);

             try {

                 while (tuile.mur(Mur(ca, ca.droite())) != 1) {
                     cases_graphe_droite[i].push_back(ca.droite().index());
                     cout << "CAS : pas de mur " << ca.droite().index() << endl;
                     ca = ca.droite();

                 }
                 if (tuile.mur(Mur(ca, ca.droite())) == 1) {
                     cout << "CAS : mur a cote " << endl;
                 }

             }
             catch (std::domain_error err) {
                 cout << "CAS : domaine error" << endl;
             }




//          -----------HAUT-------------
             //indice de tab de coups
             cout << "HAUT" << endl;
             ca = Case(i);

             try {

                 while (tuile.mur(Mur(ca, ca.haut())) != 1) {
                     cases_graphe_haut[i].push_back(ca.haut().index());
                     cout << "CAS : pas de mur " << ca.haut().index() << endl;
                     ca = ca.haut();

                 }
                 if (tuile.mur(Mur(ca, ca.haut())) == 1) {
                     cout << "CAS : mur a cote " << endl;
                 }

             }
             catch (std::domain_error err) {
                 cout << "CAS : domaine error" << endl;
             }


//          -----------BAS-------------
             //indice de tab de coups
             cout << "BAS" << endl;
             ca = Case(i);

             try {

                 while (!tuile.mur(Mur(ca, ca.bas()))) {
                     cases_graphe_bas[i].push_back(ca.bas().index());
                     cout << "CAS : pas de mur " << ca.bas().index() << endl;
                     ca = ca.bas();

                 }
                 if (tuile.mur(Mur(ca, ca.bas())) == 1) {
                     cout << "CAS : mur a cote " << endl;
                 }

             }
             catch (std::domain_error err) {
                 cout << "CAS : domaine error" << endl;
             }


         }
    }


    void Graphe::afficher(){
        std::cout<<setw(8)<<"case"<<setw(20)<<"voisins gauche"<<setw(20)<<" voisins droites"<<setw(20)<<"voisins du haut"<<setw(20)<<"voisins du bas"<<endl;
        for(int i=0;i<16;i++){
            cout<<"--------------------------------------------------------------------------------------"<<endl;

            cout<<setw(5)<<"case"<<setw(3)<<i;


            int count=0;
            std::cout<<setw(6)<<" ";
            for(unsigned int j=0;j<cases_graphe_gauche[i].size();j++){
                std::cout<<cases_graphe_gauche[i][j]<<", ";
                count++;
            }
            std::cout<<setw(14-count*3)<<" ";

            count=0;
            std::cout<<setw(6)<<" ";
            for(unsigned int j=0;j<cases_graphe_droite[i].size();j++){
                std::cout<<cases_graphe_droite[i][j]<<", ";
                count++;
            }
            std::cout<<setw(14-count*3)<<" ";

            count=0;
            std::cout<<setw(6)<<" ";
            for(unsigned int j=0;j<cases_graphe_haut[i].size();j++){
                std::cout<<cases_graphe_haut[i][j]<<",";
                count++;
            }
            std::cout<<setw(14-count*3)<<" ";

            count=0;
            std::cout<<setw(6)<<" ";
            for(unsigned int j=0;j<cases_graphe_bas[i].size();j++){
                std::cout<<cases_graphe_bas[i][j]<<",";
                count++;
            }
            std::cout<<setw(14-count*3)<<" ";

            std::cout<<std::endl;
        }



    }





}  //end of namespace MMaze
