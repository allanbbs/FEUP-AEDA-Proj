//
// Created by maruba on 23/12/19.
//

#include "../Header/Motorista.h"


int Motorista::getHours() const{
    return hours;
}

bool Motorista::operator<(const Motorista & driver) const{
    return this->hours < driver.getHours();
}

