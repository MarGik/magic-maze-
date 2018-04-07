#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "mur.hpp"

#include <vector>
#include <iostream>
#include "melangeur.hpp"

namespace MMaze {

class Tuile {

  public :

    Tuile() ;

    //indique si deux cases voisines sont separees par un mur
    bool mur(Mur m) const ;

    //indique si une case est accessible depuis les portes ou non
    bool accessible(Case c) const ;

    //affichage
    friend std::ostream& operator<<(std::ostream& out, const Tuile& t) ;

    //genere la tuile de depart
    void generateTuileDepart();
    // genere les autre tuiles clasiques
    void generateTuileClasique();
    //b=true Tuile Depart
    //b=false Tuile Clasique
    void generateMur(bool b);

    void UnionFind();

    ~Tuile();

  private :

    //affichage
    void afficher_horizontal(std::ostream& out, unsigned int i) const ;
    void afficher_vertical(std::ostream& out, unsigned int i) const ;


    char * tuile_tab;
    char * mur_tab;




    } ;

} //end of namespace MMaze

#endif
