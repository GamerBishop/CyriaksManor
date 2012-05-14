#include <QtGui/QApplication>
#include "cyriaksmanor.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "partie.h"
#include "monstre.h"
#include "hero.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CyriaksManor leJeu;
    leJeu.show();

    srand(time(NULL));
//    std::cout << "Let's Fight!" << std::endl;
//    int compteur(0);

//    std::list<Monstre*> lesMonstres;
//    std::list<Hero*> lesHeros;
//   // Monstre* leGobelin= new Monstre("Gobelin1", 10, 11, 10, 15, 20, 12, 100, 100, 50, 50);
//    Monstre* theWalker = new Monstre("Walker", 10, 30, 2, 2, 2, 10, 80, 80, 20, 20);
//    Hero* leGuerrier= new Hero("Guerrier", 15, 20, 17, 25, 30, 54, 150, 150, 75, 75, 4, 55, 68, 0);
//    leGuerrier->calcNivSuivant();
//    std::cout << "Son Niveau Suivant à " << leGuerrier->getNiveauSuivant() << "XP. \n";
//    //Hero* laMagicienne = new Hero("Magicienne", 10, 15, 30, 25, 15, 54, 110, 110, 75, 75, 3, 45);

//    while (compteur!=10)
//    {
//        std::cout << std::endl;
//        leGuerrier->Attaquer(theWalker);
//        std::cout << std::endl;
//        std::cout << std::endl;
//        theWalker->Attaquer(leGuerrier);
//        compteur++;
//        std::cout << std::endl;
//    }

    return a.exec();
}
