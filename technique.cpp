#include "technique.h"

Technique::Technique(std::string unNom, int unePuisMagique, int unePuisPhysique, int uneProba)
    :sonNom(unNom), saPuisMagique(unePuisMagique), saPuisPhysique(unePuisPhysique), saProba(uneProba)
{
}

std::string Technique::getNom()
{
    return sonNom;
}

int Technique::getMagique()
{
    return saPuisMagique;
}

int Technique::getPhysique()
{
    return saPuisPhysique;
}

int Technique::getProba()
{
    return saProba;
}
