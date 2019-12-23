//
// Created by allanbs on 23/12/19.
//

#ifndef AEDA_PROJ1_WORKSHOP_H
#define AEDA_PROJ1_WORKSHOP_H

#include <string>
#include <vector>
#include <algorithm>>
using namespace std;


class Workshop{
private:
    string name;
    vector<string> brands;
    int unavailability;
public:
    explicit Workshop(string name) : name(name){};
    Workshop(string name,vector<string> aux);
    int get_unavailability() const {return unavailability;};
    string getName() const{return name;};
    bool checkForBrand(string name)const;
    bool operator<(const Workshop &w1)const;


};




#endif //AEDA_PROJ1_WORKSHOP_H
