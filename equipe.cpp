#include "equipe.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



Equipe::Equipe(QPoint unePosition, QObject *parent) :
    QObject(parent),
    saPosition(unePosition)
{
    sonImage = new QImage("data/laChevre.png");
    saPosition+=QPoint(-25,-25);
}

void Equipe::afficher(QPainter *unPainter)
{
    unPainter->save();

    unPainter->drawImage(saPosition, *sonImage);

    unPainter->restore();
}

void Equipe::deplacer(QPoint unDeplacement)
{

    saPosition += unDeplacement * 3;
    if((rand()%1000<=8)&& unDeplacement!=QPoint(0,0)) //Chaque deplacement donne 0.008
    {
                                                      //chance de déclencher un combat
        std::cout<<"un combat"<<std::endl;
        emit lanceCombat();
    }
}

void Equipe::Fuite()
{

}

//void Equipe::lanceCombat()
//{
//    std::cout<<"Emmission d'un Combat"<<std::endl;
//}
