
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include "Header/TaxTable.h"
#include "Header/Camiao.h"
using namespace std;
ifstream in("/home/allanbs/2 Ano/AEDA/project/AEDA_Proj1/tax.txt");
TaxTable *table = new TaxTable(in);
int main() {
    Camiao base(1000);
    Congelado con(1000,1,-100);
    Perigoso per(1000,1,7);
    Animals ani(1000,1,10);
    cout<<base.cal_preco()<<
    con.cal_preco()<<
    per.cal_preco()<<
    ani.cal_preco()<<endl;
}



