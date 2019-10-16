//
// Created by Amanda  on 2019-10-14.
//
#include "../Header/Servicos.h"
#include "../Header/Clientes.h"
#include <vector>
using namespace std;
Clientes::Clientes() {
    //
}
Clientes::Clientes(string n, unsigned int anif) {
    name = n;
    nif = anif;
}
Clientes::~Clientes(){

}
float Clientes::cal_lucro() {
    float lucro = 0;

    for (auto it = services.begin(); it < services.end(); it++) {
        lucro+= (*it)->cal_preco();
    }
    return lucro;
}
void Clientes::addService(Servicos servico) {
    services.push_back(&servico);
}
unsigned int Clientes::get_nif() {
    return nif;
}

ostream & operator<<(ostream &out, Clientes client) {
    return out;
}