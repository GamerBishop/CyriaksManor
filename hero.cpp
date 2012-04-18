#include "hero.h"
#include "monstre.h"


#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>

Hero::Hero(std::string unNom, int uneForce, int uneVitalite, int uneMagie, int unEsprit, int uneDexterite, int uneChance, int desPointsDeVie, int desPdVMax, int desPointsDeMagie,  int desPMMax, int unNiveau, int desPointsdExperiences, int uneConstanteXP, int unNiveauSuivant, QImage uneImage)
    :Personnage(unNom, uneForce, uneVitalite, uneMagie, unEsprit, uneDexterite, uneChance, desPointsDeVie, desPdVMax, desPointsDeMagie, desPMMax, QPoint* (0,0), uneImage),
     sonNiveau(unNiveau), sesPointsdExperiences(desPointsdExperiences), saConstanteXP(uneConstanteXP), sonNiveauSuivant(unNiveauSuivant)
{
}


int Hero::calcNivSuivant()
{
    int unCompteur(0);
    sonNiveauSuivant=0;

    while (unCompteur<(sonNiveau+1))
    {
        sonNiveauSuivant += ( saConstanteXP * pow(unCompteur,2));
        unCompteur++;
    }

    return sonNiveauSuivant;
}



int Hero::getNiveauSuivant()
{
    return sonNiveauSuivant;
}

void Hero::recalcNivSuivant()
{
    sonNiveauSuivant+=(saConstanteXP*(sonNiveau)^2);
}

void Hero::ajouterXP(int desXP)
{
    while (desXP!=0)
    {
        sesPointsdExperiences++;
        desXP--;
        if (sesPointsdExperiences==sonNiveauSuivant)
        {
           passerNiveau();
        }
    }
}

void Hero::modifierPDV(int desDegats)
{
    sesPointsDeVie -= desDegats;
    std::cout << sonNom << " a maintenant " << sesPointsDeVie << "PdV." << std::endl;
}

void Hero::Attaquer(Monstre* unMonstre)
{
    std::cout << sonNom << " attaque " << unMonstre->getNom() << ". " << std::endl;
    if ( calcProba( saDexterite))
    {
        int lesDegats= ( (saForce + rand()%20 ) - ( unMonstre->getVitalite() + rand()%10 )/10 ) ;

        if (lesDegats <=0)
            lesDegats=0;

        std::cout << sonNom << " inflige " << lesDegats << " points de dégats à " << unMonstre->getNom() << ". " << std::endl;
        unMonstre->modifierPDV(lesDegats);
        if (unMonstre->testMort())
            unMonstre->mort();
    }
    else
        std::cout<< sonNom << "a raté son attaque." << std::endl;
}

void Hero::passerNiveau()
{
    sonNiveau++;
    recalcNivSuivant();
    saForce+=rand()%3;
    saVitalite+=rand()%3;
    saMagie+=rand()%3;
    sonEsprit+=rand()%3;
    saDexterite+=rand()%3;
    saChance+=rand()%3;
    sesPointsDeVie+=sesPdVMax*(20/100);
    sesPdVMax+=sesPdVMax*(20/100);
    sesPointsDeMagie+=sesPMMax*(5/100);
    sesPMMax+=sesPMMax*(5/100);

}

void Hero::UtiliserTechnique(Monstre* unMonstre, Technique* uneTechnique)
{
    std::cout << sonNom << " utilise " << uneTechnique->getNom() << "sur " << unMonstre->getNom() << ". " << std::endl;

    if (uneTechnique->getProba()>= rand()%100)
    {
        int lesDegats=( ( (saForce + rand()%20*uneTechnique->getPhysique() ) - ( unMonstre->getVitalite() + rand()%10 )/10 ) +( (saMagie + rand()%20 * uneTechnique->getMagique())- (unMonstre->getEsprit() + rand()%10)/10)) ;

        if (lesDegats <=0)
            lesDegats=0;

        std::cout << sonNom << " inflige " << lesDegats << " points de dégats à " << unMonstre->getNom() << ". " << std::endl;
        unMonstre->modifierPDV(lesDegats);

        if (unMonstre->testMort())
            std::cout << unMonstre->getNom() << "est mort.";
    }
    else
        std::cout<< sonNom << "a manqué " << uneTechnique->getNom()<< ". " << std::endl;
}

void Hero::tentativeFuite(std::list <Monstre*>* lesMonstres, std::list <Hero*>* lesHeros)
{
    int moyenneDexteriteMonstres(0);

        for (std::list<Monstre*>::iterator leItMonstre=lesMonstres->begin(); leItMonstre!=lesMonstres->end();leItMonstre++)
            {
                moyenneDexteriteMonstres+=(*leItMonstre)->getDexterite();
            }

    moyenneDexteriteMonstres=moyenneDexteriteMonstres/lesMonstres->size();

    int moyenneDexteriteHeros(0), moyenneChanceHeros(0);

        for (std::list<Hero*>::iterator leItHero=lesHeros->begin(); leItHero!=lesHeros->end();leItHero++)
            {
                moyenneDexteriteHeros+=(*leItHero)->getDexterite();
                moyenneChanceHeros+=(*leItHero)->getChance();
            }

    moyenneDexteriteHeros=moyenneDexteriteHeros/4;
    moyenneChanceHeros=moyenneChanceHeros/4;

    if ((moyenneDexteriteHeros+((moyenneChanceHeros*rand()%100)/100))<(moyenneDexteriteMonstres+(rand()%255)))
            sonEquipe->Fuite();
}
