#include <iostream>
#include <vector>
#include <string>
#include "Header/TaxTable.h"
#include "Header/Camiao.h"
#include "Header/Clientes.h"
#include "Header/Servicos.h"
#include "Header/Empresa.h"
using namespace std;
ifstream in("../AEDA_Proj1/Ficheiros/tax.txt"); //NAO MUDA!
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

void mainMenu();            //handle the main menu
void printMainMenu();        //prints the main menu

int main(){
    Empresa e;
    e.gravaCli();
    e.gravaSer();
    e.gravaCam();
    mainMenu();
}

//checks if the menu option input is accepted
int checkOption(int min, int max){
    int input;
    cin >> input;

    //if it's not an int
    if (cin.fail()){
        throw WrongInput_option("Invalid Input.");
        cin.ignore(1000, '\n');
        cin.clear();
    }
    //if it's not in the interval
    else if (input > max || input < min){
        throw WrongInput_option("Input is not an option.");
        cin.ignore(1000, '\n');
        cin.clear();
    }
    else
        return input;

}

void mainMenu(){
    while (true) {
        int option;
        //check if it's an acceptable input
        try {
            option = checkOption(1, 5);
        }
        catch (Error &e){
            cout << e.getInfo() << endl;
            continue;
        }

        if (option == 5)        //exit option
            break;
        switch(option){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }

}

void printMainMenu(){
    cout << "--TRANSPORTATION ENTERPRISE--" << endl << endl
        << "1 -- Status information" << endl
        << "2 -- Profit information" << endl
        << "3 -- Add new client" << endl
        << "4 -- New service request" << endl
        << "5 -- Exit" << endl;
}