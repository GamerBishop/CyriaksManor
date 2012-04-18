#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <QImage>
#include <QPoint>

#include "technique.h"
#include <QImage>


class Personnage
{
protected:
    std::string sonNom;
    int saForce, saVitalite, saMagie, sonEsprit, saDexterite, saChance, sesPointsDeVie,
    sesPdVMax, sesPointsDeMagie, sesPMMax;
    QImage *sonImage;
    QPoint *saPosition;

    /*

    Force       -> Attaque Physique
    Vitalité    -> Défense Physique
    Magie       -> Attaque Magique
    Esprit      -> Défense Magique
    Dextérité   -> Vitesse
    Chance      -> Pour le calcul de Coups Critiques et Fuite

    */

public:


    Personnage(std::string unNom, int uneForce, int uneVitalite, int uneMagie, int unEsprit,
               int uneDexterite, int uneChance, int desPointsDeVie, int desPdVMax,
               int desPointsDeMagie,  int desPMMax, QPoint *unePosition, QImage uneImage);

    //Accesseurs
    int getChance();
    int getDexterite();
    std::string getNom();
    int getVitalite();
    int getEsprit();

    //Combat
    bool calcProba(int uneDexterite);
    bool testMort();
    void mort();


};

#endif // PERSONNAGE_H
