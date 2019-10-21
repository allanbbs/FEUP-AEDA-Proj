#include <iostream>
#include <vector>
#include <string>
#include "Header/TaxTable.h"
#include "Header/Camiao.h"
#include "Header/Clientes.h"
#include "Header/Servicos.h"
#include "Header/Empresa.h"
using namespace std;
ifstream in("../AEDA_Proj1/tax.txt"); //NAO MUDA!
TaxTable *table = new TaxTable(in);

//int main() {
//    Empresa emp;
//    Local partida("Porto",0.0,0.0);
//    Local destino("Barra do Garcas",12.0,12.0);
//    Local partida1("Antartida", -3, -80);
//    Local destino1("Antartica", 30,-80);
//    emp.addClientes("Allan",201800149);
//    emp.addClientes("Maruba", 201800175);
//    emp.addServico(partida,destino,"Animal", 201800149);
//    emp.addServico(partida1, destino1,"Base", 201800175);
//    emp.display_servicoStatus(1,1);
//    emp.display_clientesInfo(1,201800175);
//    emp.display_lucro_mes();
//    return 0;
//
//}

int main(){
    Empresa e;
    e.gravaCli();
    e.display_clientesInfo(1,201800175);

}

