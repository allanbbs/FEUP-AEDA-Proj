#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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

void mainMenu(Empresa &e);            //handle the main menu
void printMainMenu();        //prints the main menu

int main(){
    Empresa e;
    e.gravaCli();
    e.gravaSer();
    e.gravaCam();
    mainMenu(e);
}

//checks if the menu option input is accepted
int checkOption(int min, int max){
    int input;
    cin >> input;

    //if it's not an int
    if (cin.fail()){
        cin.ignore(1000, '\n');
        cin.clear();
        throw WrongInput_option("Invalid Input.Please enter an integer");

    }
    //if it's not in the interval
    else if (input > max || input < min){
        cin.ignore(1000, '\n');
        cin.clear();
        throw WrongInput_option("Given input is not an option.");
    }
    else
        return input;

}

void mainMenu(Empresa &e){
    string nome;
    while (true) {
        printMainMenu();
        int option;
        //check if it's an acceptable input
        try {
            option = checkOption(1, 5);
        }
        catch (WrongInput_option &e){
            cout << e.getInfo() << endl;
            continue;
        }

        if (option == 5)        //exit option
            break;
        switch(option){
            case 1:
                int id;
                cout<<"All Services(0)"<<endl;
                cout<<"Especific service(service_id)"<<endl;
                cin>>id;
                while(cin.fail()){
                    cin.clear();
                    cout<<"Wrong input! Please enter an integer"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin>>id;
                }
                e.display_servicoStatus(id);
                break;
            case 2:
                e.display_lucro_mes();
                break;
            case 3:
                unsigned int nif;
                cout<<"Number of clients: "<<e.getClientes().size()<<endl;
                cout<<"Nome: "<<endl;
                cin.ignore();
                getline(cin,nome);
                cout<<"NIF: "<<endl;
                cin>>nif;
                try {
                    e.addClientes(nome, nif);
                }
                catch(RepeatedClient &a){
                    cout<<a.getInfo()<<endl;
                }
                break;

            case 4: {
                map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};
                string partida,chegada,tipo;
                unsigned int anif;
                int type;
                cout<<"Enter place of departure: "<<endl;
                cin.ignore();
                getline(cin,partida);
                cout<<"Enter place of arrival: "<<endl;
                cin.ignore();
                getline(cin,chegada);
                cout<<"Enter type of package (0-Base,1-Frozen,2-Dangerous,3-Animal): "<<endl;

                try{
                    type = checkOption(0,3);
                }
                catch(WrongInput_option &e){
                    cout<<e.getInfo()<<endl;
                    break;

                }
                cin.ignore();
                cin>>anif;
                while(cin.fail()){
                    cin.clear();
                    cout<<"Wrong input.Please enter an integer"<<endl;
                    cin.ignore();
                    cin>>anif;
                }
                tipo = temp[type];
                e.addServico(Local(partida,0,0),Local(chegada,0,0),tipo,anif);
                break;
            }
            default:
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