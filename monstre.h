#ifndef MONSTRE_H
#define MONSTRE_H

#include "personnage.h"
#include <QImage>

class Hero;  // Définition du type pouvant etre ainsi utilisé dans la déclaration.

class Monstre : public Personnage
{

private:
    int sonGainXP;  // Nombre de points d'Expériences donnés à chacun des héros à la fin du combat.

public:
    Monstre(std::string unNom, int uneForce, int uneVitalite, int uneMagie,
                        int unEsprit, int uneDexterite, int uneChance, int desPointsDeVie,
                        int desPdVMax, int desPointsDeMagie,  int desPMMax, QImage uneImage);
    //Modifications
    void modifierPDV(int);

    //Combat
    void Attaquer(Hero*);
    void UtiliserTechnique(Hero*, Technique*);



};

#endif // MONSTRE_H
