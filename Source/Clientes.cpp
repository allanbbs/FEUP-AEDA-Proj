//
// Created by Amanda  on 2019-10-14.
//
#include "../Header/Servicos.h"
#include "../Header/Clientes.h"
#include <vector>

using namespace std;

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
    profit += servico->get_profit();

}

ostream &operator<<(ostream &out, const Clientes &client) {
    cout<<fixed<<setprecision(2);
    out << left << setw(30) << client.name << setw(20) << client.nif;

    if (client.services.empty()) out << "No services!" << endl;

    for (auto a: client.services)       //list of services
        out << a->get_id() << " ";
    out << endl;

    return out;
}