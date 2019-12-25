//
// Created by allanbs on 23/12/19.
//

#ifndef AEDA_PROJ1_WORKSHOP_H
#define AEDA_PROJ1_WORKSHOP_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
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
    Workshop& operator=(const Workshop &w1);
    friend ostream& operator<<(ostream& out,const Workshop &w){
      out<<"Name: "<<w.getName()<<endl;
      out<<"Brands: ";
      for(auto &elem : w.getBrands()){
          out<<elem<<" ";
      }
      out<<endl;
      out<<"Available in: "<<w.get_unavailability()<<endl;
        return out;
    };

};




#endif //AEDA_PROJ1_WORKSHOP_H
