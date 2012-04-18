#include "terrain.h"

Terrain::Terrain(QObject *parent) :
    QObject(parent),
    sonDeplacementEquipe(QPoint()) // (0;0)
{
    sonSol = new Sol(this);
    sonEquipe = new Equipe(QPoint(25, 25), this);
}

void Terrain::afficher(QPainter *unPainter)
{
    sonSol->afficher(unPainter);
    sonEquipe->afficher(unPainter);
}

void Terrain::logicEvent()
{
    if(  ((sonDeplacementEquipe==QPoint(-1, 0)) && (sonEquipe->saPosition.x()<=0))
       ||((sonDeplacementEquipe==QPoint(1, 0)) && (sonEquipe->saPosition.x()>=750))
       ||((sonDeplacementEquipe==QPoint(0, -1)) && (sonEquipe->saPosition.y()<=0))
       ||((sonDeplacementEquipe==QPoint(0, 1)) && (sonEquipe->saPosition.y()>=400)))
    {}
    else
    sonEquipe->deplacer(sonDeplacementEquipe);

}

void Terrain::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch (event->key())
        {
            case Qt::Key_Left:          
                sonDeplacementEquipe = QPoint(-1, 0);
                break;
            case Qt::Key_Right:            
                sonDeplacementEquipe = QPoint(1, 0);
                break;
            case Qt::Key_Up:            
                sonDeplacementEquipe = QPoint(0, -1);
                break;
            case Qt::Key_Down:            
                sonDeplacementEquipe = QPoint(0, 1);
                break;
        }
    }
}

void Terrain::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
        sonDeplacementEquipe = QPoint(0, 0);
}

//Equipe Terrain::getEquipe()
//{
//    return (sonEquipe*);
//}
