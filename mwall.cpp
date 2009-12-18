#include <QTimeLine>
#include <QDebug>
#include <QHBoxLayout>
#include "mwall.h"

mWall::mWall(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mWall)
{
    ui->setupUi(this);
    ui->bntSsh->setEnabled(false);
    ui->bntWeb->setEnabled(false);

    netfilter = new NetFilter();
}

mWall::~mWall()
{
    delete ui;
}

void mWall::on_btnEnable_clicked(bool checked)
{
    qDebug() << "Enable bnt was clicked: " << checked;
    if (checked)
    {
        qDebug("Enabling the fw.");
        ui->bntSsh->setEnabled(true);
        ui->bntWeb->setEnabled(true);
        netfilter->init();


        if (ui->bntSsh->isChecked())
        {
            qDebug("Enabling ssh access");
            netfilter->enable(22);
        }

        if (ui->bntWeb->isChecked())
        {
            qDebug("Enabling web access");
            netfilter->enable(80);
            netfilter->enable(443);
        }
    }
    else
    {
        qDebug("Flushing the iptables rules");
        ui->bntSsh->setEnabled(false);
        ui->bntWeb->setEnabled(false);
        netfilter->flush();

    }
}

void mWall::on_bntSsh_clicked(bool checked)
{
    if (checked && ui->btnEnable->isChecked())
    {
        qDebug("Enabling SSH port");
        netfilter->enable(22);

    }
    else if (!checked && ui->btnEnable->isChecked())
    {
        qDebug("Disabling SSH port");
        netfilter->disable(22);
    }
}

void mWall::on_bntWeb_clicked(bool checked)
{
    if (checked && ui->btnEnable->isChecked())
    {
        qDebug("Enabling WEB port");
        netfilter->enable(80);
        netfilter->enable(443);
    }
    else if (!checked && ui->btnEnable->isChecked())
    {
        qDebug("Disabling WEB port");
        netfilter->disable(80);
        netfilter->disable(443);
    }
}
