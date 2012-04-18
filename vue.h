#ifndef VUE_H
#define VUE_H

#include <QtOpenGL/QGLWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

#include "terrain.h"
#include "equipe.h"

class Vue : public QGLWidget
{
    Q_OBJECT 

private:
//  Terrain *sonTerrain;
    QPainter *sonPainter;
    QTimer *sonTimer;

signals:

private slots:
    void logicEvent();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);


public:
    Vue(QWidget *parent = 0);
    ~Vue();
//    Terrain getTerrain();
    Terrain *sonTerrain;


public slots:


};

#endif // VUE_H
