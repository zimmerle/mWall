#ifndef MWALL_H
#define MWALL_H

#include <QtGui/QMainWindow>
#include <QTimeLine>
#include "netfilter.h"

namespace Ui
{
    class mWall;
}

class mWall : public QMainWindow
{
    Q_OBJECT

public:
    mWall(QWidget *parent = 0);
    ~mWall();

private:
    Ui::mWall *ui;
    NetFilter *netfilter;

private slots:
    void on_bntWeb_clicked(bool checked);
    void on_bntSsh_clicked(bool checked);
    void on_btnEnable_clicked(bool checked);
};

#endif // MWALL_H
