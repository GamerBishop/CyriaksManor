#ifndef SOL_H
#define SOL_H

#include <QObject>
#include <QImage>
#include <QPainter>

class Sol : public QObject
{
    Q_OBJECT

private:
    QImage* sonImage;

public:
    explicit Sol(QObject *parent = 0);
    void afficher(QPainter* unPainter);

signals:

public slots:

};

#endif // SOL_H
