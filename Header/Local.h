//
// Created by maruba on 14/10/19.
//

#ifndef AEDA_PROJ1_LOCAL_H
#define AEDA_PROJ1_LOCAL_H
#include <iostream>
#include <string>
using namespace std;


class Local {
private:
    string name;
    float x, y;
public:
    Local();
    Local(string  Name, float X, float Y);
    float get_Coordx() const;
    float get_Coordy() const;
    string getName() const;

};


#endif //AEDA_PROJ1_LOCAL_H
