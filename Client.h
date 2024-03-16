#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <netinet/in.h>
using namespace std;

class Client
{
public:
    Client(const string &nameClient, const int &port, const char *ip_addr="127.0.0.1");

    int c_connect(size_t bufsize=128);
    void c_clientHandler(int nConnect, size_t microseconds=10000);

private:
    struct sockaddr_in m_addr;
    string m_name;
    int m_client;
    string m_msg;
};

#endif // CLIENT_H
