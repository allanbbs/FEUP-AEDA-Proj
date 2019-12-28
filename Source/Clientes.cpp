//
// Created by Amanda  on 2019-10-14.
//
#include <vector>
#include "../Header/Clientes.h"
#include "../Header/Servicos.h"
#include "../Header/Date.h"


using namespace std;

/**
 * @file Clientes.cpp
 * @brief It contais the implementation of class Clientes responsable for Clients management
 */
Clientes::Clientes() {
    name = "";
    nif = 0;
}

Clientes::Clientes(const string &n, const long long int &anif) : name(n), nif(anif),
                                                                 lastrequest(Date("1900/01/01")), profit(0) {}

Clientes::Clientes(const string &n, const long long int &anif, string &aDate) : name(n), nif(anif),
                                                                                lastrequest(Date(aDate)), profit(0) {}


Clientes::~Clientes() {
    for (int i = 0; i < services.size(); i++) delete services[i];
    services.clear();
}


double Clientes::get_profit() const {
    return profit;
}

long long int Clientes::get_nif() const {
    return nif;
}


void Clientes::addService(Servicos *servico) {
    services.push_back(servico);
    profit += servico->get_profit();//increase profit variable


}

void Clientes::setLastrequest(Date &date) {
    lastrequest = date;
}

void Clientes::setName(const string &name) {
    this->name = name;
}

void Clientes::setNif(const long long int &nif) {
    this->nif = nif;
}

ostream &operator<<(ostream &out, const Clientes &client) {
    cout << fixed << setprecision(2);
    out << left << setw(30) << client.name << setw(20) << client.nif
        << setw(20) << client.profit;

    if (client.services.empty())
        out << "No services!";         //if the client hasn't requested for a service it will be noticed 

    for (auto a: client.services)                               //else it will print a list of the requested services
        out << a->get_id() << " ";
    out << endl;

    return out;                                                 //returns the name nif and requested services or "no services" announcement 
}

bool Clientes::inactive() {
    int y = stoi(Date::currentDate().substr(0, 4)) - 1;
    int m = stoi(Date::currentDate().substr(5, 7));
    int d = stoi(Date::currentDate().substr(8));
    Date now_minus_a_year = Date(y, m, d);
    return lastrequest.isAfter(now_minus_a_year);// if the lastServiceDate is before now minus a year,
    // there is more than  a year that the client doesnt request a service
}





//------------------------------------------------------------------------------------

bool Compare_clientes(const Clientes *c, const Clientes *c1) {
    if (c->get_profit() < c1->get_profit()) return false;
    else if (c1->get_profit() < c->get_profit()) return true;
    else if (c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}

bool Compare_clientesLeast(const Clientes *c, const Clientes *c1) {
    if (c->get_profit() < c1->get_profit()) return true;
    else if (c1->get_profit() < c->get_profit()) return false;
    else if (c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}

bool Compare_clientesAlphabetic(const Clientes *c, const Clientes *c1) {
    if (c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}