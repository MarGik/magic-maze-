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


<<<<<<< HEAD
||||||| merged common ancestors
  /*
=======

>>>>>>> f34f63f40f70ed97d5fff36ba60b91bca86d0bc5



    std::cout << t << std::endl ;
    std::cout << "-----------------" << std::endl;
    std::cout << depart << std::endl;

    t.rotationDroite();
    std::cout << t << std::endl ;

    t.rotationGauche();

    std::cout << t << std::endl ;


<<<<<<< HEAD
    //depart.generateMur(&depart);
    depart.ecrireDansFichier();

||||||| merged common ancestors
    depart.generateMur();
    depart.ecrireDansFichier();
    */
=======
    depart.generateMur();
  //  depart.ecrireDansFichier();


  Graphe g(t);
  g.afficher();
>>>>>>> f34f63f40f70ed97d5fff36ba60b91bca86d0bc5

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

