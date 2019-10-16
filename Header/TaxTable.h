//
// Created by allanbs on 15/10/19.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
#ifndef AEDA_PROJ1_TAXTABLE_H
#define AEDA_PROJ1_TAXTABLE_H
class TaxTable{
public:
    map<string,double> table;
public:
    TaxTable(istream& input);
    int tableSize() const {return table.size();};

};




































#endif //AEDA_PROJ1_TAXTABLE_H
