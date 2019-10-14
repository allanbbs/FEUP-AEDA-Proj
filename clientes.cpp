//
// Created by Amanda  on 2019-10-14.
//
#include "serivos.cpp"
#include "servicos.h"
#include "clientes.h"

Clientes::Clientes() {
    //
}
Clientes::Clientes(string n, unsigned int anif) {
    name = n;
    nif = anif;
}
Clients::~Clientes(){

}
float Clientes::cal_lucro() {
    float lucro = 0;

    for (auto it = ser.begin(); it < ser.end(); it++) {
        lucro+= (*it)->cal_preco();
    }
    return lucro;
}
void Clientes::addService(Servico &servico) {
    ser->push_back(servico*)//todo n sei se esta certo
}
unsigned int Clientes::get_nif() {
    return nif;
}

ostream & Clientes::operator<<(ostream &out, Clientes client) {
    return out;
}