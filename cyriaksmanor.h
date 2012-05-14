#ifndef CYRIAKSMANOR_H
#define CYRIAKSMANOR_H

#include <QKeyEvent>
#include <QMainWindow>
#include <list>

#include "vue.h"
#include "monstre.h"

namespace Ui
{
    class CyriaksManor;
}

class CyriaksManor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CyriaksManor(QWidget *parent = 0);
    ~CyriaksManor();
//    std::list<Monstre*> genererListeMonstre();
public slots:
    void Combat();

private:
    Ui::CyriaksManor *ui;
    Vue *saVue;

};

#endif // CYRIAKSMANOR_H
