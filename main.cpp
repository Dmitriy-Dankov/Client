#include "Client.h"

#define PORT 5200

int main(int argc, char *argv[])
{
    cout << "Запуск Клиента\n";
    Client client("Dmitriy", PORT);

    client.c_clientHandler(client.c_connect(256), 50000);

    return 0;
}

