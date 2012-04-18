#include "personnage.h"

Personnage::Personnage(std::string unNom, int uneForce, int uneVitalite, int uneMagie, int unEsprit, int uneDexterite, int uneChance, int desPointsDeVie, int desPdVMax, int desPointsDeMagie,  int desPMMax, QPoint *unePosition, QImage uneImage)
    : sonNom(unNom), saForce(uneForce), saVitalite(uneVitalite), saMagie(uneMagie), sonEsprit(unEsprit), saDexterite(uneDexterite), saChance(uneChance), sesPointsDeVie(desPointsDeVie), sesPdVMax(desPdVMax), sesPointsDeMagie(desPointsDeMagie), sesPMMax(desPMMax)
    ,saPosition(*unePosition)
{
    sonImage = new QImage(uneImage);

{


int Personnage::getChance()
{
    return saChance;
}
int Personnage::getDexterite()
{
    return saDexterite ;
}
std::string Personnage::getNom()
{
    return sonNom;
}
int Personnage::getVitalite()
{
    return saVitalite;
}

int Personnage::getEsprit()
{
    return sonEsprit;
}

bool Personnage::calcProba( int uneDexterite)
{
    return((((saChance)+rand()%20)-((uneDexterite/4)+rand()%10))>=rand()%100);
}

bool Personnage::testMort()
{
    return (sesPointsDeVie<=0);
}

void Personnage::mort()
{
    std:: cout << sonNom << " est mort." << std::endl;
}
