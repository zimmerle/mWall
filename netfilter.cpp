#include <stdio.h>
#include <stdlib.h>
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
    system(IPTABLES " -p TCP --syn -j ACCEPT");
    system(IPTABLES " -p TCP -m state --state ESTABLISHED,RELATED -j ACCEPT");
    system(IPTABLES " -P INPUT DROP");
}
