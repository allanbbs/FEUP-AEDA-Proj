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

Local::Local(string  Name, double X, double Y): name(Name), x(X), y(Y) {};

double Local::get_Coordx()const {
    return x;
}

double Local::get_Coordy()const {
    return y;
}

string Local::getName()const {
    return name;
}