//
// Created by allanbs on 15/10/19.
//
#include "../Header/TaxTable.h"
#include <string>
using namespace std;
TaxTable::TaxTable(istream &input) {
    string type;
    string tax;
    if(!input.eof())
    while(!input.eof()){
        getline(input,type);
        getline(input,tax);
        if(!type.empty() && !tax.empty())table[type] = stod(tax);
    }
}
