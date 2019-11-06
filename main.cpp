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


void mainMenu(Empresa &e);              //handle the main menu
void printMainMenu();                   //prints the main menu
int checkOption(int min, int max);      //checks if it's a valid option
int validServiceId(Empresa &e);         //checks if it's a valid service id
void printMenuStatus();                 //print the menu for status
void handleMenuStatus(Empresa &e);      //handle the menu status
void handleAddClient(Empresa &e);
int validClientNif(Empresa &e);
void handleAddService(Empresa &e);
void handleAddTruck(Empresa &e);
double checkNumber();
int month;

int main(){
    Empresa e;
    cout << "Welcome! Type the month to be analyzed [EXIT 0] ";
    month = checkOption(0,12);
    if (month != 0){
        e.gravaCli();
        e.gravaCam();
        e.gravaSer(e, month);
        mainMenu(e);
    }
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
        option = checkOption(1, 6);

        if (option == 6)                                            //exit option
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

            case 3:
                handleAddClient(e);
                break;

            case 4: {
                handleAddService(e);
                break;
            }
            case 5:
                handleAddTruck(e);

                break;
            default:
                break;
        }
    }

}

void printMainMenu(){
    cout    << "      TRANSPORTATION ENTERPRISE       " << endl 
            << "======================================" << endl
            << "Status information                 [1]" << endl
            << "Profit information                 [2]" << endl
            << "Add new client                     [3]" << endl
            << "New service request                [4]" << endl
            << "Add truck                          [5]" << endl
            << "Exit                               [6]" << endl;
}

void printMenuStatus(){
    cout    << "                STATUS MENU                 " << endl
            << "============================================" << endl
            << "First 20 most profitable service         [1]" << endl
            << "Specific service                         [2]" << endl
            << "First 20 most profitable clients         [3]" << endl
            << "Specific client status                   [4]" << endl
            << "Cancel                                   [5]" << endl
            << "Option: " << endl;

}

void handleMenuStatus(Empresa &e){
    int option, id, nif;
    while(true) {
        printMenuStatus();

        option = checkOption(1, 5);

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
    cout<<"NIF [EXIT -1]  ";
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

//TESTAR
void handleAddService(Empresa &e){
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};

    double l1x, l1y, l2x,l2y;
    string partida,chegada,tipo;
    long int anif, type;
    int carga;

    while (true) {
        //precisa checar os valores
        cout << "Enter the number of products ";
        carga = checkNumber();
        if (carga == -1) return;

        cout << "Enter place of departure [EXIT -1] ";
        cin.ignore();
        getline(cin, partida);
        if (partida == "-1") return;

        cout << "Enter place of arrival [EXIT -1] ";
        getline(cin, chegada);
        if (chegada == "-1") return;

        cout << "Enter type of package (0-BASE,1-FROZEN, 2-DANGEROUS,3-ANIMAL) [EXIT -1] ";
        type = checkOption(-1, 3);
        if (type == -1) return;

        anif = validClientNif(e);
        if (anif == -1) return;

        tipo = temp[type];
        try {
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
        }
        catch(WrongInput_option &error){
            cout << error.getInfo();
            cin.ignore();
            break;
        }

        Servicos * temp = e.addServico(Local(partida, l1x, l1y), Local(chegada, l2x, l2y), tipo, anif, carga);
        if (!e.allocateCamiao(temp)){
            cout << "Not enough trucks [PRESS ENTER]" << endl;
            wait();
            return;
        }
        string fileName = "../AEDA_Proj1/Ficheiros/servicos"+to_string(month)+".txt"; 
        ofstream o(fileName.c_str(), ios_base::app);
        o << "\n\n" << partida << "\n" << l1x << "\n" << l1y;
        o << "\n" << chegada << "\n" << l2x << "\n" << l2y;
        o << "\n" << tipo << "\n" << anif<< "\n" << carga << "\n";
        o << temp->get_camioes_id();
        o.close();
        cout << "Service added successfully! [PRESS ENTER]" << endl;
        wait();

        return;
    }
}

//DONE
int checkOption(int min, int max){
    int input;
    //if it's not an int
    while (true) {
        try {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw WrongInput_option("Invalid Input. Please enter an integer");

            }
                //if it's not in the interval
            else if (input > max || input < min) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw WrongInput_option("Given input is not an option. Try again");
            } else
                return input;
        }
        catch(WrongInput_option & error){
            cout << error.getInfo() << endl;
            continue;
        }
    }

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
        cout << "Type the nif [EXIT -1]  ";
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
    double input;
    while (true) {
        try {
            cout << "[EXIT -1] ";
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw WrongInput_option("Invalid Input. Please enter an integer");

            }
            else
                return input;
        }
        catch(WrongInput_option & error){
            cout << error.getInfo() << endl;
            continue;
        }
    }
}

//TESTAR
void handleAddTruck(Empresa &e){
    int type, carg;
    double caract;
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};
    while (true) {
        cout << "Max carg: ";
        carg = checkNumber();
        if (carg == -1) return;
        if (carg < 1) cout << "Only positive numbers." << endl;
        else break;
    }

    cout << "[EXIT -1] Enter type of package (0-Base,1-Frozen,2-Dangerous,3-Animal): ";
    type = checkOption(-1, 3);
    if (type == -1) return;

    if(type == 0)
        e.addCamiao(0, carg);

    else if (type == 1){
        cout << "Temperature: ";
        try{
            caract = checkNumber();
        }catch(WrongInput_option &error){
            cout << "Not a number! " << endl;
        }
        e.addCamiao(1, carg, caract);
    }
    else if (type == 2){
        cout << "Level of dangerous [1-10]: ";
        while(true) {
            try {
                caract = checkOption(1, 10);
                break;
            }
            catch (WrongInput_option &error) {
                cout << error.getInfo() << endl;
                continue;
            }
        }
        e.addCamiao(2, carg, caract);
    }
    else if (type == 3){
        cout << "[EXIT -1/0] Number of animals. Watch the max storage ("<< carg << ") " << endl;
        caract = checkOption(-1, 10);
        if (caract == -1 || caract == 0)  return;
        }
        e.addCamiao(3, carg, caract);


    ofstream o("../AEDA_Proj1/Ficheiros/camioes", ios_base::app);
    o << "\n" << carg << "\n" << temp[type];
    o << "\n" << caract << "\n";
    o.close();




};