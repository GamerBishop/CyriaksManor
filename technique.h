#ifndef TECHNIQUE_H
#define TECHNIQUE_H

#include <iostream>


class Technique
{
    std::string sonNom;
    int saPuisMagique,
           saPuisPhysique,
           saProba;

/*
      saPuisMagique     -> Facteur Magique de la puissance de la technique.
      saPuisPhysique    -> Facteur Physique de la puissance de la technique.
      saProba           -> Nombre (au max 100) qui sera testé pour la précision de l'attaque.
*/

public:
    Technique(std::string unNom, int unePuisMagique, int unePuisPhysique, int uneProba);


    //Accesseurs
    std::string getNom();
    int getMagique();
    int getPhysique();
    int getProba();
};

#endif // TECHNIQUE_H
