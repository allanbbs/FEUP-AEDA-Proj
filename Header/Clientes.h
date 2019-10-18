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
    string name;                      /**<Name of the client*/
    unsigned int nif;                 /**<Identification of the client*/
    vector<Servicos *> services;      /**<Services requested by the client*/
    float profit;                     /**<Clients profit*/
public:
    /**
     * Default constructos
     */
    Clientes();
    /**
     * Constructor
     * @param n Clients name
     * @param anif Nif (identificantion of the client)
     */
    Clientes(const string &n, const unsigned int &anif);
    /**
     * Default destructor
     */
    ~Clientes();
    /**
     * @return Returns the profit of the client
     */
    float get_profit() const;
    /**
     * @return Returns the clients nif (identification)
     */
    unsigned int get_nif() const;
    /**
     * Client request a service
     * @param servico Service to be added
     */
    void addService(Servicos *servico);
    /**
     * Display the information about the client
     * @param out ostream with the information
     * @param client object containing the client register
     * @return ostream with the information
     */
    friend ostream &operator<<(ostream &out, const Clientes &client);
};


#endif //AEDA_01_CLIENTES_H
