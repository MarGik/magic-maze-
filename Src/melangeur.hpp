#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

namespace MMaze {

class Melangeur {

  public :

    Melangeur(int octets) ;

    ~Melangeur() ;

    void inserer(const void* elem) ;

    void retirer(void* elem) ;
    void afficher();

    void vider() ;

    int taille() ;

  /* vos membres ici */

    char *tab_melange;
    int octets;
    int capacite;
    int taille_reelle;

} ;

} //end of namespace MMaze

#endif
