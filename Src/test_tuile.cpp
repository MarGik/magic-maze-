#include "tuile.hpp"
#include "graphe.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <time.h>
using namespace MMaze ;

int main() {
  srand(time(NULL));




  Tuile t ;
  t.generateTuileClasique();



  Tuile depart;
  depart.generateTuileDepart();


    std::cout << t << std::endl ;
    std::cout << "-----------------" << std::endl;
    std::cout << depart << std::endl;

    t.rotationDroite();
    std::cout << t << std::endl ;

    t.rotationGauche();

    std::cout << t << std::endl ;



    //depart.generateMur(&depart);
    //    depart.ecrireDansFichier();


//  Graphe g(t);
 // g.afficher();


  t.parcours_largeur(Case(0));

  //utilisation des couleurs
  std::cout
    << TXT_JAUNE << "&"
    << TXT_ORANGE << "&"
    << TXT_VERT << "&"
    << TXT_VIOLET << "&"
    << TXT_CLEAR
    << BG_JAUNE << "&"
    << BG_ORANGE << "&"
    << BG_VERT << "&"
    << BG_VIOLET << "&"
    << BG_LIGHTGREY << "&"
    << TXT_CLEAR
    << std::endl ;

  return 0 ;
}

