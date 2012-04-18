#ifndef TERRAIN_H
#define TERRAIN_H

#include <QKeyEvent>
#include <QObject>

#include "equipe.h"
#include "sol.h"

class Terrain : public QObject
{
    Q_OBJECT
private:
    Sol *sonSol;
//  Equipe *sonEquipe;
    QPoint sonDeplacementEquipe;

public:
    explicit Terrain(QObject *parent = 0);
    void afficher(QPainter* unPainter);
//  Equipe getEquipe();
    Equipe *sonEquipe;
    void logicEvent();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:

};

#endif // TERRAIN_H
