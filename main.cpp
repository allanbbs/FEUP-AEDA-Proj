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


void mainMenu(Empresa &e);            //handle the main menu
void printMainMenu();                   //prints the main menu
int checkOption(int min, int max);      //checks if it's a valid option
int validServiceId(Empresa &e);       //checks if it's a valid service id
void printMenuStatus();                 //print the menu for status
void handleMenuStatus(Empresa &e);                //handle the menu status
void handleAddClient(Empresa &e);
int validClientNif(Empresa &e);
void handleAddService(Empresa &e);
double checkNumber();

int main(){
    Empresa e;
    e.gravaCli();
    e.gravaSer();
    e.gravaCam();
    mainMenu(e);
}


void wait(){
    cout << endl << "[PRESS ENTER]";
    cin.ignore();
    while (cin.get() != '\n') {};
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
        catch (WrongInput_option &error){
            cout << error.getInfo() << endl;
            continue;
        }

        if (option == 5)                                            //exit option
            break;
        switch(option){
            case 1:
                handleMenuStatus(e);
                break;

            case 2:
                e.display_lucro_mes();
                break;

            case 3:
                handleAddClient(e);
                break;

            case 4: {
                handleAddService(e);
            }
            default:
                break;
        }
    }

}

void printMainMenu(){
    cout << "--TRANSPORTATION ENTERPRISE--" << endl << endl
        << "[1] -- Status information" << endl
        << "[2] -- Profit information" << endl
        << "[3] -- Add new client" << endl
        << "[4] -- New service request" << endl
        << "[5] -- Exit" << endl;
}

void printMenuStatus(){
    cout<< "--STATUS MENU--" << endl
        <<"[1] -- First 20 most profitable service status"<<endl
        <<"[2] -- Specific service"<<endl
        <<"[3] -- First n clients status" << endl
        <<"[4] -- Specific client status" << endl
        <<"[5] -- Cancel" << endl
        <<"Option: " << endl;

}

void handleMenuStatus(Empresa &e){
    int option, n, id, nif;

    while(true) {
        printMenuStatus();
        try {
            option = checkOption(1, 5);
        }
        catch (WrongInput_option &error) {
            cout << error.getInfo() << endl;
            continue;
        }
        if (option == 5) return;
        switch(option){
            case 1:
                e.display_servicoStatus();
                wait();
                break;
            case 2:
                id = validServiceId(e);
                e.display_servicoStatus(id);
                wait();
                break;
            case 3:
                e.display_clientesInfo();
                wait();
                break;
            case 4:
                nif = validClientNif(e);
                if (nif != -1) {
                    e.display_clientesInfo(nif);
                    wait();
                }
                break;
        }

    }
}

void handleAddClient(Empresa &e){
    int nif;
    string nome;
    cout<<"Number of clients: "<< Empresa::nCli <<endl;
    cout<<"Nome: ";
    cin.ignore();
    getline(cin,nome);
    cout<<"[exit -1] NIF: ";
    while (true) {
        cin >> nif;
        if (nif == -1) return;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        try {
            e.addClientes(nome, nif);
            ofstream o("../AEDA_Proj1/Ficheiros/clientes", ios_base::app);
            o << "\n" << nome << "\n" << nif;
            o.close();
            return;
        }
        catch (RepeatedClient &a) {
            cout << "There is already a client with nif "<<a.getInfo() << endl;
            continue;
        }
    }
}

void handleAddService(Empresa &e){
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};

    double l1x, l1y, l2x,l2y;
    string partida,chegada,tipo;
    long int anif, type;

    while (true) {
        cout << "Enter place of departure: ";
        cin.ignore();
        getline(cin, partida);
        cout << "Enter place of arrival: ";
        cin.ignore();
        getline(cin, chegada);
        cout << "Enter type of package (0-Base,1-Frozen,2-Dangerous,3-Animal): ";

        try {
            type = checkOption(0, 3);
        }
        catch (WrongInput_option &e) {
            cout << e.getInfo() << endl;
            continue;

        }
        anif = validClientNif(e);
        if (anif == -1) return;
        tipo = temp[type];
        try {
            cout << "Partida coordenada x (latitude): " << endl;
            l1x = checkNumber();
            cout << "Partida coordenada y (Longitude): " << endl;
            l1y = checkNumber();
            cout << "Chegada coordenada x (Latitude): " << endl;
            l2x = checkNumber();
            cout << "Chegada coordenada y (Longitude): " << endl;
            l2y = checkNumber();
        }
        catch(WrongInput_option &error){
            cout << error.getInfo();
            cin.ignore();
            break;
        }

        e.addServico(Local(partida, l1x, l1y), Local(chegada, l2x, l2y), tipo, anif);
        cout << "Service added successfully" << endl;
        wait();
        return;
    }
}

//checks if the menu option input is accepted
int checkOption(int min, int max){
    int input;
    cin >> input;

    //if it's not an int
    if (cin.fail()){
        cin.ignore(1000, '\n');
        cin.clear();
        throw WrongInput_option("Invalid Input. Please enter an integer");

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


int validServiceId(Empresa &e){
    int id;
    while(true) {
        cout << "Type the id: ";
        cin >> id;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        try {
            e.SearchSer(id);
            return id;
        }
        catch (NoService &error) {
            cout <<"The id " <<error.getInfo() << "does not exist!"<<endl;
            cout <<"Type 1 to " << Empresa::nSer << endl;
            continue;
        }
    }
}

int validClientNif(Empresa &e) {
    int nif;
    while (true) {
        cout << "[-1] Cancel. Type the nif: ";
        cin >> nif;
        if (nif == -1) return -1;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (e.SearchCli(nif) != -1)
            return nif;
        else
            cout << "No client with nif " << nif << endl;

    }
}

double checkNumber(){
    double m;
    string j;
    for (int i = 0; i < 4; i++){
        cin >> m;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Not a number " << 3-i << " more tries" << endl;
        }
        else
            return m;

    }
    throw WrongInput_option("Too many trie. Aborting operation! \n");
}