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

    QObject::connect(saVue->sonTerrain->sonEquipe, SIGNAL(lanceCombat()), this, SLOT(Combat(saVue->sonTerrain->sonEquipe->sesHeros*)));

}

CyriaksManor::~CyriaksManor()
{
    delete ui;
    delete saVue;
}


void CyriaksManor::Combat(std::vector<Hero*> lesHeros)
{
    std::cout<<"siglal du combat reçu"<<std::endl;
    //Ici ya du boulot
    //genererListeMonstre();

        int unaleatoire(rand()%3);
        std::vector<Monstre*> listeMonstreGeneree;

            switch (unaleatoire)
            {
            case 1:
                Monstre* leMonstre1 = new Monstre("EvilOurs - 1", 10, 11, 10, 15, 20, 12, 100, 100, 50, 50, QImage("data/leGobelin.png"));
                Monstre* leMonstre2 = new Monstre("EvilOurs - 2", 15, 13, 15, 7, 10, 15, 110, 110, 50, 50, QImage("data/leGobelin.png"));
                Monstre* leMonstre3 = new Monstre("Meta-Voiture - 1", 12, 12, 7, 15, 25, 13, 175, 175, 25, 25, QImage("data/laMetaVoiture.png"));
                Monstre* leMonstre4 = new Monstre("Meta-Voiture - 2", 13, 11, 8, 14, 22, 11, 200, 200, 25, 25, QImage("data/laMetaVoiture.png"));

                listeMonstreGeneree.push_back(leMonstre1);
                listeMonstreGeneree.push_back(leMonstre2);
                listeMonstreGeneree.push_back(leMonstre3);
                listeMonstreGeneree.push_back(leMonstre4);
                break;

                //case 2:

            }

        //setPosition()
        std::vector<Hero*>::iterator leItHero;
        std::vector<Monstre*>::iterator leItMonstre;
        std::map <Personnage*, std::pair <std::string, Personnage*>*> stockActions;
            bool uneVictoire(0), uneDefaite(0);
                    while (!uneVictoire || !uneDefaite)
            {

                        for (leItHero=lesHeros.begin(); leItHero != lesHeros.end(); leItHero++)
                        {


                        }

                        for (leItMonstre=listeMonstreGeneree.begin(); leItMonstre != listeMonstreGeneree.end(); leItMonstre++)
                        {

                         //   std::pair<std::string , Personnage*> unePaire;
                         //   unePaire.first="Attaque";
                         //   unePaire.second = (lesHeros.at(rand()%(lesHeros.size()) - 1));
                         //   stockActions[(*leItMonstre)]= lesHeros((rand()%4)-1)];
                        }
            }




    }



