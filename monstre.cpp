#include "monstre.h"
#include "hero.h"

Monstre::Monstre(std::string unNom, int uneForce, int uneVitalite, int uneMagie, int unEsprit, int uneDexterite, int uneChance, int desPointsDeVie, int desPdVMax, int desPointsDeMagie,  int desPMMax, QImage uneImage)
    : Personnage(unNom, uneForce, uneVitalite, uneMagie, unEsprit, uneDexterite, uneChance, desPointsDeVie, desPdVMax, desPointsDeMagie, desPMMax, QPoint(), uneImage)
{
}




void Monstre::modifierPDV(int desDegats)
{
    sesPointsDeVie -= desDegats;

    std::cout << sonNom << " a maintenant " << sesPointsDeVie << "PdV." << std::endl;
}




void Monstre::Attaquer(Hero* unHero)
{


    int lesDegats;
    std::cout << sonNom << " attaque " << unHero->getNom() << ". " << std::endl;
    lesDegats= ( (saForce + rand()%20 ) - ( unHero->getVitalite() + rand()%10 )/10 ) ;

    if (lesDegats <=0)
        lesDegats=0;

    std::cout << sonNom << " inflige " << lesDegats << " points de dégats à " << unHero->getNom() << ". " << std::endl;
    unHero->modifierPDV(lesDegats);
    if (unHero->testMort())
        unHero->mort();

}

void Monstre::UtiliserTechnique(Hero* unHero, Technique* uneTechnique)
{
    int lesDegats;
    std::cout << sonNom << " utilise " << uneTechnique->getNom() << "sur " << unHero->getNom() << ". " << std::endl;
    lesDegats=( ( (saForce + rand()%20*uneTechnique->getPhysique() ) - ( unHero->getVitalite() + rand()%10 )/10 ) +( (saMagie + rand()%20 * uneTechnique->getMagique())- (unHero->getEsprit() + rand()%10)/10)) ;

    if (lesDegats <=0)
        lesDegats=0;

    std::cout << sonNom << " inflige " << lesDegats << " points de dégats à " << unHero->getNom() << ". " << std::endl;
    unHero->modifierPDV(lesDegats);
    if (unHero->testMort())
        unHero->mort();
}
