#include <iostream>
#include <vector>
#include <string>
#include "Header/TaxTable.h"
#include "Header/Camiao.h"
#include "Header/Clientes.h"
#include "Header/Servicos.h"
using namespace std;
ifstream in("/home/allanbs/2 Ano/AEDA/project/AEDA_Proj1/tax.txt");
TaxTable *table = new TaxTable(in);

int main() {
    Local partida("Porto",0.0,0.0);
    Local destino("Barra do Garcas",12.0,12.0);
    Clientes a("Allan",201800149);
    Servicos b(partida,destino,1,"Animal");
    a.addService(&b);
    cout<<b.cal_tempo()<<endl;
    return 0;

}



