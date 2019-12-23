//
// Created by maruba on 23/12/19.
//

#ifndef AEDA_PROJ1_MOTORISTA_H
#define AEDA_PROJ1_MOTORISTA_H
#include "bst.h"
#include <string>

class Motorista {
private:
    std::string name;
    int hours;
public:
    bool operator<(const Motorista &driver) const;
    int getHours() const;
};


class Workers{
private:
    BST<Motorista> it;
public:

};



#endif //AEDA_PROJ1_MOTORISTA_H
