#include "Client.h"

#include <arpa/inet.h>
#include <unistd.h>


Client::Client(const string &nameClient, const int &port, const char *ip_addr)
    : m_name{nameClient}
{
    m_client = socket(AF_INET, SOCK_STREAM, 0);

    if (m_client < 0)
    {
        cout << "Error creating socket...\n";
        exit(1);
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);
    m_addr.sin_addr.s_addr = inet_addr(ip_addr);
}

int Client::c_connect(size_t bufsize)
{
    char buff[bufsize];
    int nConnect = connect(m_client, (sockaddr*)&m_addr, sizeof(m_addr));

    if (nConnect < 0)
    {
        cout << "Error connecting to server...\n";
        exit(1);
    } else {
        recv(m_client, buff, bufsize, 0);
        cout << "Server=> " << buff << '\n';
    }
    return nConnect;
}

void Client::c_clientHandler(int nConnect, size_t microseconds)
{
    while (nConnect >= 0) {
        cout << m_name << "=> ";

        getline(cin, m_msg);
        m_msg += '\0';

        if(m_msg[0] == 'q') break;

        send(m_client, &m_msg[0], m_msg.size(), 0);
        usleep(microseconds);
    }

    close(m_client);
}
