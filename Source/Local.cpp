//
// Created by maruba on 14/10/19.
//

#include "../Header/Local.h"

#include <utility>


Local::Local() {
    name = "";
    x = 0;
    y = 0;
}

Local::Local(string  Name, float X, float Y): name(Name), x(X), y(Y) {};

float Local::get_Coordx() {
    return x;
}

float Local::get_Coordy() {
    return y;
}

string Local::getName() {
    return name;
}