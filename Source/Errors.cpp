//
// Created by maruba on 17/10/19.
//

#include "../Header/Errors.h"


NoClient::NoClient(const unsigned int &Nif): nif(Nif) {}

unsigned int NoClient::getNif() {
    return nif;
}

NoService::NoService(const unsigned int &Id): id(Id) {}

unsigned int NoService::getId() {
    return id;
}

//cliente repetido

