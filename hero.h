#ifndef HERO_H
#define HERO_H

#include <list>

#include "equipe.h"
#include "personnage.h"


class Equipe;
class Monstre; // D�finition du type pouvant etre ainsi utilis� dans la d�claration.

class Hero : public Personnage
{
protected:
    int sonNiveau, sesPointsdExperiences, saConstanteXP, sonNiveauSuivant;
    Equipe* sonEquipe;

    /*

      constanteXP   -> Constante utilis�e pour le calcul de Niveaux
      NiveauSuivant -> Points d'XP n�cessaires pour passer au niveau suivant

    */

public:
    //Initialisation
    int calcNivSuivant();
    Hero(std::string unNom, int uneForce, int uneVitalite, int uneMagie, int unEsprit,
                int uneDexterite, int uneChance, int desPointsDeVie, int desPdVMax,
                int desPointsDeMagie,  int desPMMax, int unNiveau, int desPointsdExperiences,
                int uneConstanteXP, int unNiveauSuivant, QImage uneImage);


     //Modifications
    void passerNiveau();
    void modifierNiveauSuivant(int desXP);
    void modifierPDV(int);
    void ajouterXP(int desXP);
    void recalcNivSuivant();

     //Accesseurs
    int getNiveauSuivant();



     //Combat
    void Attaquer(Monstre*);
    void UtiliserTechnique(Monstre *, Technique*);
    void tentativeFuite(std::list <Monstre*>*, std::list <Hero*>*);



};

#endif // HERO_H
