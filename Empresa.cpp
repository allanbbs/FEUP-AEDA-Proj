//
// Created by maruba on 14/10/19.
//

#include "Empresa.h"

Empresa::Empresa() {}

Empresa::~Empresa() {
    for (int i = 0; i < get_numClientes(); i++) delete cli[i];          //cleaning the vector
    for (int i = 0; i < get_numCamiao(); i++) delete cam[i];
    for (int i = 0; i < get_numServicos(); i++) delete ser[i];
    delete cli;                                                         //deleting the vector allocation
    delete cam;
    delete ser;
}

float Empresa::getLucro_mes() const {
    float lucro = 0;
    for (auto it = cli.begin(); it < cli.end(); it++)
        lucro += (*it)->cal_lucro();
    return lucro;
}


size_t Empresa::get_numClientes() const {
    return cli.size();
}

size_t Empresa::get_numCamiao() const {
    return cam.size();
}

size_t Empresa::get_numServicos() const {
    return ser.size();
}

void Empresa::addClientes(const string& name,const unsigned int& nif) {    //checked.
    auto c = new Clientes(name,nif);
    cli.push_back(c);
}

void Empresa::display_clientesInfo(const unsigned int& n, const unsigned int& nif) {
    ostringstream os;
    if (nif) {                                                          //case just one nif, search for it.
        auto it = find_if(cli.begin(), cli.end(), [nif](Clientes *c) { return (c->get_nif() == nif); });
        os << (*it);
    }
    else{
        for (auto it = cli.begin(); it < cli.end(); it++){
            os << (*it);
        }
    }
    cout << os.str();
}

void Empresa::display_lucro_mes() {
    cout << "Total profit of the month: " << this->getLucro_mes() << endl;
}

void Empresa::display_servicoStatus(const unsigned int &n, const unsigned int &id) {
    ostringstream os;
    if (id){
        auto it = find_if(ser.begin(),ser.end(), [id](Servicos* s){return s->get_id() == id;});
        os << (*it);
    }
    else{
        for (auto it = ser.begin(); it < ser.end(); it++){
            os << (*it);
        }
        cout << os.str();
    }
}