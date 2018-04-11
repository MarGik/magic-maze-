#ifndef MMAZE_GRAPHE_HPP
#define MMAZE_GRAPHE_HPP

#include "case.hpp"
#include "graphe.hpp"
#include "tuile.hpp"
#include "case.hpp"
#include "mur.hpp"

#include <vector>
#include <iostream>
#include "melangeur.hpp"
#include <fstream>
#include <string>
#include <cassert>

namespace MMaze {

    class Graphe {


        public :

        Graphe(Tuile &tuile);

        std::vector <int>cases_graphe_gauche[16];
        std::vector <int>cases_graphe_droite[16];
        std::vector <int>cases_graphe_haut[16];
        std::vector <int>cases_graphe_bas[16];


        void afficher();




    private :



        };

} //end of namespace MMaze

#endif