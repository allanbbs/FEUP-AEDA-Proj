//
// Created by Amanda  on 2019-10-14.
//
#include <string>
#include <iostream>
using namespace std;
#include "Servicos.h"
#ifndef AEDA_01_CLIENTES_H
#define AEDA_01_CLIENTES_H


class Clientes {
private:
    string name;
    unsigned int nif;   /**<Identification of the client*/
    vector <Servicos*> services;    /**<Services requested by the client*/
public:
    Clientes();
    Clientes(const string& n, const unsigned int& anif);
    ~Clientes();
    float cal_lucro() const;  /**<Calculates the total profit provided by the client*/
    unsigned int get_nif() const;
    void addService(Servicos *servico); /**<Add a service*/
    friend ostream & operator <<(ostream& out,const Clientes &client);  /**<Display the information abou a client*/

};


#endif //AEDA_01_CLIENTES_H
