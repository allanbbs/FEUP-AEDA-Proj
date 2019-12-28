//
// Created by allanbs on 23/12/19.
//

#include <vector>
#include <string>
#include "../Header/Workshop.h"
using namespace std;

Workshop::Workshop(string name,vector<string> aux){
    name = name;
    brands.assign(aux.begin(),aux.end());
    unavailability = 0;
}

bool Workshop::operator<(const class Workshop & w1) const{
    return unavailability > w1.get_unavailability();
}

bool Workshop::checkForBrand(string name)const {
    for(auto &brand : brands){
        if(brand == name) return true;
    }
    return false;
}