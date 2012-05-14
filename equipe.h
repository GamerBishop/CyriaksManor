#ifndef EQUIPE_H
#define EQUIPE_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QImage>
#include <list>

//#include "cyriaksmanor.h"
#include "hero.h"
#include "objet.h"

//CyriaksManor leJeu;

class Hero;

class Equipe : public QObject
{
    Q_OBJECT
private:
    QImage *sonImage;

    std::string sonNom;
    std::vector<Hero*> sesHeros;
    std::list<Objet*> sesObjets;

public:
    explicit Equipe(QPoint unePosition, QObject *parent = 0);
    void afficher(QPainter* unPainter);
    void deplacer(QPoint unDeplacement);
    void Fuite();
    QPoint saPosition;

signals:
    void lanceCombat();

public slots:

};

#endif // EQUIPE_H
