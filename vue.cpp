#include "vue.h"
//#include <QFocusEvent>

Vue::Vue(QWidget *parent) :
    QGLWidget(parent)
{
    sonTerrain = new Terrain(this);
    sonPainter = new QPainter();
    sonTimer = new QTimer(this);
    setFixedSize(800, 450);
    setFocusPolicy(Qt::StrongFocus);

    QObject::connect(sonTimer, SIGNAL(timeout()), this, SLOT(update()));
    QObject::connect(sonTimer, SIGNAL(timeout()), this, SLOT(logicEvent()));
    sonTimer->start(1000/60); // 60 images par seconde

}

Vue::~Vue()
{
    delete sonPainter;
    delete sonTerrain;
}



//Terrain Vue::getTerrain()
//{
//    return sonTerrain;
//}

void Vue::logicEvent()
{
    sonTerrain->logicEvent();
}



void Vue::paintEvent(QPaintEvent *event)
{
    sonPainter->begin(this);

    sonTerrain->afficher(sonPainter);

    sonPainter->end();
}

void Vue::keyPressEvent(QKeyEvent *event)
{
    sonTerrain->keyPressEvent(event);
}



void Vue::keyReleaseEvent(QKeyEvent *event)
{
    sonTerrain->keyReleaseEvent(event);
}
