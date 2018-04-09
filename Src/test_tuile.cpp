#include "tuile.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"

#include <iostream>
#include <cstdlib>
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

 t.generateMur();
    depart.generateMur();
    depart.ecrireDansFichier();
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
    << TXT_CLEAR
    << std::endl ;

  return 0 ;
}

