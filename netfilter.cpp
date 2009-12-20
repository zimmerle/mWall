#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include "netfilter.h"

#define IPTABLES "/usr/sbin/iptables"

NetFilter::NetFilter()
{
    flush();
}

void NetFilter::flush()
{
    system(IPTABLES " -P INPUT ACCEPT");
    system(IPTABLES " -F");
}

void NetFilter::enable(int port /* missing proto */)
{
    char line[2048];
    sprintf(line, "%s -A INPUT -p TCP -s 0/0 --dport %d -j ACCEPT\0\0", IPTABLES, port);

    system(line);
}

void NetFilter::disable(int port /* missing proto */)
{
    char line[2048];
    sprintf(line, "%s -D INPUT -p TCP -s 0/0 --dport %d -j ACCEPT\0\0", IPTABLES, port);

    system(line);
}

void NetFilter::init()
{
    qDebug() << "Dropping";
    system(IPTABLES " -P INPUT DROP");
    //system(IPTABLES " --syn -j ACCEPT");
    qDebug() << "ESTABLISHED,RELATED";
    system(IPTABLES " -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT");
    qDebug() << "lo";
    system(IPTABLES " -A INPUT -i lo -j ACCEPT");
    qDebug() << "Done!";

}
