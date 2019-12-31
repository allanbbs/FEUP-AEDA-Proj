//
// Created by allanbs on 23/12/19.
//

#ifndef AEDA_PROJ1_WORKSHOP_H
#define AEDA_PROJ1_WORKSHOP_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;


class Workshop{
private:
    string name;
    vector<string> brands;
    int unavailability;
public:
    explicit Workshop(string name) : name(name){};
    Workshop(string name,vector<string> &aux,int nani);
    int get_unavailability() const {return unavailability;};
    string getName() const{return name;};
    vector<string> getBrands()const{return brands;};
    bool checkForBrand(string name)const;
    bool operator<(const Workshop &w1)const;
    bool operator==(const Workshop& w1) const { return name==w1.getName();};
    friend ostream& operator<<(ostream& out, Workshop w);
    void setUn(int a) { unavailability = a;};
    void addBrand(string n){brands.push_back(n);};
    //Workshop& operator=(const Workshop &w1);

};

void headerWorkshop();



#endif //AEDA_PROJ1_WORKSHOP_H
