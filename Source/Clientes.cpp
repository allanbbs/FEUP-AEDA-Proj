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

Clientes::Clientes(const string& n, const unsigned int& anif): name(n), nif(anif) {}

Clientes::~Clientes() {

}

float Clientes::cal_lucro() const{
    float lucro = 0.0;
    if (services.empty()) {
        cout << "No service to calculate gains" << endl;
        return lucro;
    }
    for (auto it = services.begin(); it < services.end(); it++) {
        lucro += (*it)->cal_preco();
    }
    return lucro;
}

void Clientes::addService(Servicos *servico) {
    services.push_back(servico);
}

unsigned int Clientes::get_nif() const{
    return nif;
}

ostream &operator<<(ostream &out, const Clientes &client) {
    out << left << setw(30) << client.name << setw(20) << client.nif;

    if (client.services.empty()) out << "No services!" << endl;

    for (auto a: client.services)       //list of services
        out << a->get_id() << " ";
    out << endl;

    return out;
    }