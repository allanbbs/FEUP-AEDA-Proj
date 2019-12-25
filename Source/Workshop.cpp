//
// Created by allanbs on 23/12/19.
//

#include <vector>
#include <string>
#include "../Header/Workshop.h"
using namespace std;

Workshop::Workshop(string name,vector<string> aux,int nani){
    this->name = name;
    brands.assign(aux.begin(),aux.end());
    unavailability = nani;
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

Workshop& Workshop::operator=(const class Workshop & w1) {
    name = w1.getName();
    brands.clear();
    brands.assign(w1.getBrands().begin(),w1.getBrands().end());
    unavailability = w1.get_unavailability();
    return *this;
}