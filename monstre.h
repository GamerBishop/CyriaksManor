#ifndef MONSTRE_H
#define MONSTRE_H

#include "personnage.h"
#include <QImage>

class Hero;  // D�finition du type pouvant etre ainsi utilis� dans la d�claration.

class Monstre : public Personnage
{

private:
    int sonGainXP;  // Nombre de points d'Exp�riences donn�s � chacun des h�ros � la fin du combat.

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
