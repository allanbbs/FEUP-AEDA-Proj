//
// Created by Amanda  on 2019-10-14.
//
#include <vector>
#include "../Header/Clientes.h"
using namespace std;

/**
 * @file Clientes.cpp
 * @brief It contais the implementation of class Clientes responsable for Clients management
 */
Clientes::Clientes() {
    name = "";
    nif = 0;
}

Clientes::Clientes(const string &n, const unsigned int &anif) : name(n), nif(anif), profit(0) {}

Clientes::~Clientes() {
    for (int i = 0 ; i < services.size(); i++) delete services[i];
    services.clear();
}


double Clientes::get_profit() const {
    return profit;
}

unsigned int Clientes::get_nif() const {
    return nif;
}


void Clientes::addService(Servicos *servico) {
    services.push_back(servico);
    profit += servico->get_profit();                            //increase profit variable

}


ostream &operator<<(ostream &out, const Clientes &client) {
    cout<<fixed<<setprecision(2);
    out << left << setw(30) << client.name << setw(20) << client.nif
                <<setw(20) << client.profit; 

    if (client.services.empty()) out << "No services!" << endl; //if the client hasn't requested for a service it will be noticed   

    for (auto a: client.services)                               //else it will print a list of the requested services
        out << a->get_id() << " ";
    out << endl;

    return out;                                                 //returns the name nif and requested services or "no services" announcement 
}

bool Compare_clientes(const Clientes* c, const Clientes* c1) {
    if (c->get_profit() < c1->get_profit()) return false;
    else if (c1->get_profit() < c->get_profit()) return true;
    else if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}

bool Compare_clientesLeast(const Clientes *c, const Clientes* c1){
    if (c->get_profit() < c1->get_profit()) return true;
    else if (c1->get_profit() < c->get_profit()) return false;
    else if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}

bool Compare_clientesAlphabetic(const Clientes *c, const Clientes* c1){
    if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}