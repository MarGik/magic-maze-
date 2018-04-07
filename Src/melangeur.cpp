#include "melangeur.hpp"

namespace MMaze {

Melangeur::Melangeur(int _octets) {
    tab_melange=(char *)malloc(_octets);
    octets=_octets;
    capacite=1;
    taille_reelle=0;
}

Melangeur::~Melangeur() {

        free(tab_melange );

}

void Melangeur::inserer(const void* elem) {
    if(capacite == taille_reelle){
        //grandir la capacite
        capacite*=2;
        //allouer assez de memoire
        tab_melange=(char *)realloc(tab_melange, capacite*octets);

    }
    //add element
    memcpy(tab_melange + (taille_reelle*octets), elem, octets);
    taille_reelle++;
}



void Melangeur::retirer(void* elem) {


     //  srand(time(NULL));
       int r = rand() % taille_reelle;


       cout << " i've chosen " << r << "to remove" << endl;

       //on prend la valeure d'une case aleatoirement choisi et le met dans elem
       memcpy(elem, tab_melange + r * octets, octets);


       //on copie la valeur de la derniere case de tableau dans une case "vide(retiree)"
    if(r!=taille_reelle-1 && taille_reelle>0)
       memcpy(tab_melange + r * octets, tab_melange + (taille_reelle -1 ) * octets, octets);



       taille_reelle--;

}



void Melangeur::vider() {
    tab_melange=(char *)realloc(tab_melange,octets);
    taille_reelle=0;
    capacite=1;
}

void Melangeur::afficher() {

    for (int i=0; i<taille_reelle; i++){
        cout<<*(int *)(tab_melange+octets*i)<<endl;
    }

}

//erreur dans taille
int Melangeur::taille() {

    return taille_reelle;

}

} //end of namespace MMaze



