#include "sol.h"

Sol::Sol(QObject *parent) :
    QObject(parent)
{
    sonImage = new QImage("data/sol.png");
}

void Sol::afficher(QPainter *unPainter)
{
    if (sonImage->isNull()) return;

    QRect leRect = unPainter->viewport(); // Taille Ã  afficher

    for (int i=0; i<=leRect.height()/sonImage->height(); i++)
    {
        for (int j=0; j<=leRect.width()/sonImage->width(); j++)
        {
            unPainter->drawImage(j*sonImage->width(), i*sonImage->height(), *sonImage);
        }
    }
}
