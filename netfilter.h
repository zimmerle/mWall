#ifndef NETFILTER_H
#define NETFILTER_H

class NetFilter
{
public:
    NetFilter();

    void flush();
    void enable(int);
    void disable(int);
    void init();
};

#endif // NETFILTER_H
