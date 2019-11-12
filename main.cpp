#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Header/TaxTable.h"
#include "Header/Camiao.h"
#include "Header/utils.h"
#include "Header/Clientes.h"
#include "Header/Servicos.h"
#include "Header/Empresa.h"
using namespace std;

/**
 * @file main.cpp
 * @brief This is the main page of the project that contains the implementation of it
 *
 */

ifstream in("../AEDA_Proj1/Ficheiros/tax.txt"); //NAO MUDA!
TaxTable *table = new TaxTable(in);


void mainMenu(Empresa &e);              //handle the main menu
void printMainMenu();
void printMenuStatus();                 //print the menu for status
void handleMenuStatus(Empresa &e);      //handle the menu status
void handleAddClient(Empresa &e);
void handleAddService(Empresa &e);
void handleAddTruck(Empresa &e);

int month;
extern bool novo;

int main(){
    Empresa e;
    cout << "Type the month to be analyzed [EXIT 0] ";
    month = checkOption(0,12);
    if (month != 0){
        e.gravaCli();
        e.gravaCam();
        e.gravaSer(e, month);
        mainMenu(e);
    }
}

void mainMenu(Empresa &e){
    string nome;
    while (true) {
        printMainMenu();
        int option;
        option = checkOption(1, 11);
        clear_screen();

        if (option == 5)                                            //exit option
            break;
        switch(option){
            case 1:
                handleMenuStatus(e);
                break;

            case 2:
                e.display_lucro_mes();
                e.display_CamiaoProfit();
                wait();
                break;

            case 6:
                handleAddClient(e);
                break;

            case 9: {
                handleAddService(e);
                break;
            }
            case 3:
                handleAddTruck(e);
                break;
            case 7:{
                long int nif = validClientNif(e);
                if (nif == -1) continue;
                e.changeClientName(nif);
                cout << "Name changed successfully! ";
                wait();
                break;
            }
            case 8:{
                long long nif = validClientNif(e);
                if (nif == -1) continue;
                e.removeClient(nif);
                cout << "Client removed successfully! ";
                wait();
                break;
            }
            case 4:{
                cout << "Type the id [EXIT 0]: ";
                long long int id = checkOption(0,e.get_cam_num());
                if (id == 0) continue;
                e.removeTruck(id);
                wait();
                break;
            }
            default:
                break;
        }
        clear_screen();
    }

}

void printMainMenu(){
    cout    << "      TRANSPORTATION ENTERPRISE                        CLIENTS MANAGEMENT           " << endl
            << "======================================      ======================================= " << endl
            << "Status information                 [1]      Add new client                      [6] " << endl
            << "Profit information                 [2]      Change client NAME                  [7] " << endl
            << "Add truck                          [3]      Remove a client                     [8] " << endl
            << "Remove truck                       [4]      New service request                 [9] " << endl
            << "Exit                               [5]                                              " << endl
            << "Number of trucks: " << Empresa::nCam << endl; 
}

void printMenuStatus(){
    cout    << "            SEARCH SERVICES                                                     SEARCH CLIENTS                  " << endl
            << "============================================                     ============================================   " << endl
            << "First x most profitable services         [1]                     First x most profitable clients          [6]   " << endl
            << "First x least profitable services        [2]                     First x least profitable clients         [7]   " << endl
            << "First x services of a specific type      [3]                     First x clients in alphabetic order      [8]   " << endl
            << "Specific service by id                   [4]                     Specific client status by nif            [9]   " << endl
            << "Cancel                                   [5]                                                                    " << endl
            << "Option:                                                                                                         " << endl;

}

void handleMenuStatus(Empresa &e){
    int option, id, nif, type;
    long int n;
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};

    while(true) {
        clear_screen();
        printMenuStatus();

        option = checkOption(1, 9);

        if (option == 5) return;
        switch(option){
            case 1: {
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue;
                e.display_servicoStatus(0, n);
                wait();
                break;
            }
            case 4:
                id = validServiceId(e);
                e.display_servicoStatus(id);
                wait();
                break;
            case 6:
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue;
                e.display_clientesInfo(0,n);
                wait();
                break;
            case 9:
                nif = validClientNif(e);
                if (nif != -1) {
                    e.display_clientesInfo(nif);
                    wait();
                }
                break;
            case 2:
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue;
                e.display_servicoStatus(0, n, Compare_servico_Leastprofit);
                wait();
                break;
            case 3:
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue; 
                cout << "Enter type of package (0 BASE | 1 FROZEN | 2 DANGEROUS | 3 ANIMAL) [EXIT -1] ";
                type = checkOption(-1, 3);
                if (type == -1) continue;
                e.display_servicoStatus(0, n, Compare_servico_Leastprofit, temp[type]);
                wait();
                break;
            case 7:
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue;
                e.display_clientesInfo(0,n,Compare_clientesLeast);
                wait();
                break;
            case 8:
                cout << "Type x [EXIT - 0][1~10000] ";
                n = checkOption(0, 10000);
                if (n == 0) continue;
                e.display_clientesInfo(0,n,Compare_clientesAlphabetic);
                wait();
                break;

        }
    }
}

void handleAddClient(Empresa &e){
    long long int nif;
    string nome;
    cout<<"Number of clients: "<< Empresa::nCli <<endl;

    
    while (true) {
        cout<<"NIF: ";
        nif = checkNumber();
        if (nif == 0 || nif < -1){
            cout << "Invalid NIF. Try again." << endl; 
             continue;                                                      //do not accept negative nifs
        }
        if (nif == -1) return;

        //case it was a ex-client
        long int pos = e.SearchCli((-1) * nif);
        if (pos != -1){
            e.reAcceptClient(pos);
            cout << "Client reaccepted! ";
            wait();
            return;
        }

        cout<<"Nome [EXIT -1]: ";
        cin.ignore();
        getline(cin,nome);
        if (nome == "-1") return;                                           //abort operation


        try {
            e.addClientes(nome, nif);
            ofstream o("../AEDA_Proj1/Ficheiros/clientes", ios_base::app);
            o << "\n" << nome << "\n" << nif;
            o.close();
            cout << "Client added successfully! ";
            wait();
            return;
        }
        catch (RepeatedClient &a) {
            cout << "There is already a client with nif "<< nif << endl;
            cout << "Try again:" << endl; 
            continue;
        }
    }
}

void handleAddService(Empresa &e){
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};
    map<unsigned int,string> temp_carac = { {0,"Frio"},{1,"Medio"},{2,"Quente"}, {3,"Toxico"},{4,"Inflamavel"},{5,"Quebravel"}, {6,"Pequeno"},{7,"Medio"},{8,"Grande"},{9,"None"}};
    double l1x, l1y, l2x,l2y;
    string partida,chegada,tipo;
    long int anif, type;
    int carga;

    while (true) {
        clear_screen();
        cout << "Enter the number of products ";
        carga = checkNumber();
        if (carga == -1) return;
        if (carga < -1 || carga == 0) {
            cout << "Only positive numbers! Try again." << endl;
            continue;
        }

        cout << "Enter place of departure [EXIT -1] ";
        cin.ignore();
        getline(cin, partida);
        if (partida == "-1") return;

        cout << "Enter place of arrival [EXIT -1] ";
        getline(cin, chegada);
        if (chegada == "-1") return;

        cout << "Enter type of package (0 BASE | 1 FROZEN | 2 DANGEROUS | 3 ANIMAL) [EXIT -1] ";
        type = checkOption(-1, 3);
        if (type == -1) return;
        tipo = temp[type];

        anif = validClientNif(e);
        if (anif == -1) return;

        cout << "Partida coordenada x (latitude) ";
        l1x = checkNumber();
        if (l1x == -1) return;
        cout << "Partida coordenada y (Longitude) ";
        l1y = checkNumber();
        if (l1y == -1) return;
        cout << "Chegada coordenada x (Latitude) ";
        l2x = checkNumber();
        if (l2x == -1) return;
        cout << "Chegada coordenada y (Longitude) ";
        l2y = checkNumber();
        if (l2y == -1) return;

        int opt = 9;
        if (tipo == "Congelado"){
            cout << "Enter type temperature of the products (0 COLD | 1 AMBIENT | 2 HOT) [EXIT -1]";
            opt = checkOption(-1,2);
            if (opt == -1) return;
        }
        else if (tipo == "Perigoso"){
            cout << "Enter how dangerous the products are (3 TOXIC | 4 FLAMBLE | 5 SENSIBLE) [EXIT 2]";
            opt = checkOption(2,5);
            if (opt == 2) return;
        }
        else if(tipo == "Animal"){
            cout << "Enter the size of the animals (6 LITTLE | 7 MEDIO | 8 BIG) [EXIT 5]";
            opt = checkOption(5,8);
            if (opt == 5) return;
        }

        Servicos *s = new Servicos(Local(partida, l1x, l1y), Local(chegada, l2x, l2y), ++Empresa::nSer, tipo, carga, temp_carac[opt]);



        if (!e.allocateCamiao(s)){
            cout << "Not enough trucks " << endl;
            wait();
            return;
        }

        e.addServico(s, anif);
        string fileName = "../AEDA_Proj1/Ficheiros/servicos"+to_string(month)+".txt"; 
        ofstream o(fileName.c_str(), ios_base::app);

        if (novo) {
            o << "\n";
            novo = false;
        }
        else o << "\n\n";

        o << partida << "\n" << l1x << "\n" << l1y;
        o << "\n" << chegada << "\n" << l2x << "\n" << l2y;
        o << "\n" << tipo << "\n" << anif<< "\n" << carga << "\n";
        if (tipo != "None")
            o << tipo << "\n";
        o << s->get_camioes_id();
        o.close();
        cout << "Service added successfully! ";
        wait();

        return;
    }
}

void handleAddTruck(Empresa &e){
    int type, carg;
    double caract;
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};
    while (true) {
        cout << "Max carg: ";
        carg = checkNumber();
        if (carg == -1) return;
        if (carg < 1){
            cout << "Only positive numbers." << endl;
            continue; 
        }
        else break;
    }

    cout << "[EXIT -1] Enter type of package (0 BASE | 1 FROZEN | 2 DANGEROUS | 3 ANIMAL): ";
    type = checkOption(-1, 3);
    if (type == -1) return;

    if(type == 0){
        e.addCamiao(0, carg);
    }
    else if (type == 1){
        e.addCamiao(1, carg);
    }
    else if (type == 2){
        e.addCamiao(2, carg);
    }
    else if (type == 3){
        e.addCamiao(3, carg);
    }

    cout << "Truck added successfully ";
    wait(); 

    ofstream o("../AEDA_Proj1/Ficheiros/camioes", ios_base::app);
    o << "\n\n" << carg << "\n" << temp[type];
    o << "\n" << caract;
    o.close();

}
