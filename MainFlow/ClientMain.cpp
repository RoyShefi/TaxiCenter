//
// Created by Oded Thaller on 24/12/2016.
//

#include "Client.h"
#include "../Logging/easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

using namespace std;

BOOST_CLASS_EXPORT_GUID(StandardCab, "StandardCab");
BOOST_CLASS_EXPORT_GUID(LuxuryCab, "LuxuryCab");

/**
 * Find the status by Char given.
 * @param statusInput - Char input.
 * @return - the int value that the char represents.
 */
int findStatus(char statusInput) {
    if (statusInput == 'S') {
        return 0;
    } else if (statusInput == 'M') {
        return 1;
    } else if (statusInput == 'D') {
        return 2;
    } else if (statusInput == 'W') {
        return 3;
    } else {
        return -1;
    }
}

int checkInput(int id, int age, int stat, int exp, int cabId, char comma[4]) {
    if (id < 0 || age <= 0 || stat == -1 || exp < 0 || cabId < 0) {
        return -1;
    }
    for (int i = 0; i < 4; ++i) {
        if (comma[i] != ',') {
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {

    easyloggingpp::Configurations confFromFile("../Logging/Client_Config");
    easyloggingpp::Loggers::reconfigureAllLoggers(confFromFile);
    LOG(INFO) << "Client starting";

    int id, age, exp, cabId;
    char stat;
    char comma[4];
    Client* client = new Client(argv[1],atoi(argv[2]));

    // Create a new driver by user input.
    cin >> id >> comma[0] >> age >> comma[1] >> stat >> comma[2] >> exp >> comma[3] >> cabId;
    int status = findStatus(stat);

    if (checkInput(id, age, status, exp, cabId, comma) == 0) {

        client->Connect();
        client->sendDriver(id, age, (Driver::Status) status, exp, cabId);

        while (client->connected) {
            client->ListenToServer();
        }
    } else {
        LOG(ERROR) << "input incorrect";
    }

    client->~Client();
    LOG(INFO) << "Client exiting... Goodbye";
    return 0;
}