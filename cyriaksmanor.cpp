#include "cyriaksmanor.h"
#include "ui_cyriaksmanor.h"
#include <iostream>

CyriaksManor::CyriaksManor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CyriaksManor)
{
    ui->setupUi(this);

    Vue *saVue = new Vue;
    setCentralWidget(saVue);

    QObject::connect(saVue->sonTerrain->sonEquipe, SIGNAL(lanceCombat()), this, SLOT(Combat()));

}

CyriaksManor::~CyriaksManor()
{
    delete ui;
    delete saVue;
}

//std::list<Monstre*> CyriaksManor::genererListeMonstre()
//{
//    for (int unCompteur(0); unCompteur<4;unCompteur++)
//    {
//        int unaleatoire(rand()%3);
//        std::list<Monstre*> listeGeneree;

//        switch (unaleatoire)
//        {
//        case 1:
//            Monstre* leMonstre1 = new Monstre("Gobelin1", 10, 11, 10, 15, 20, 12, 100, 100, 50, 50, QImage("data/leGobelin.png"));
//            Monstre* leMonstre2 = new Monstre("Gobelin2", 15, 13, 15, 7, 10, 15, 110, 110, 50, 50, QImage("data/leGobelin.png"));
//            Monstre* leMonstre3 = new Monstre("Meta-Voiture1", 12, 12, 7, 15, 25, 13, 175, 175, 25, 25, QImage("data/laMetaVoiture.png"));
//            Monstre* leMonstre4 = new Monstre("Meta-Voiture1", 13, 11, 8, 14, 22, 11, 200, 200, 25, 25, QImage("data/laMetaVoiture.png"));
//            listeGeneree.push_back();
//            break;

//        case 2:

//        }
//    }
//return
//}

void CyriaksManor::Combat()
{
    std::cout<<"siglal du combat reçu"<<std::endl;
    //Ici ya du boulot
    //genererListeMonstre();
    for (int unCompteur(0); unCompteur<4;unCompteur++)
    {
        int unaleatoire(rand()%3);
        std::list<Monstre*> listeGeneree;

        switch (unaleatoire)
        {
        case 1:
            Monstre* leMonstre1 = new Monstre("Gobelin1", 10, 11, 10, 15, 20, 12, 100, 100, 50, 50, QImage("data/leGobelin.png"));
            Monstre* leMonstre2 = new Monstre("Gobelin2", 15, 13, 15, 7, 10, 15, 110, 110, 50, 50, QImage("data/leGobelin.png"));
            Monstre* leMonstre3 = new Monstre("Meta-Voiture1", 12, 12, 7, 15, 25, 13, 175, 175, 25, 25, QImage("data/laMetaVoiture.png"));
            Monstre* leMonstre4 = new Monstre("Meta-Voiture2", 13, 11, 8, 14, 22, 11, 200, 200, 25, 25, QImage("data/laMetaVoiture.png"));

            listeGeneree.push_back(leMonstre1);
            listeGeneree.push_back(leMonstre2);
            listeGeneree.push_back(leMonstre3);
            listeGeneree.push_back(leMonstre4);
            break;

        //case 2:

        }
    }
}


