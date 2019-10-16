//
// Created by maruba on 14/10/19.
//

#ifndef AEDA_PROJ1_EMPRESA_H
#define AEDA_PROJ1_EMPRESA_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "clientes.h"
#include "Camiao.h"
#include "Servicos.h"

using namespace std;

/**
 * @brief Class that manages an enterprise
 */
class Empresa{
private:
    vector <Clientes*> cli; /**< Vector that contains all clients of this enterprise*/
    vector <Camiao*> cam;   /**<Vector that contais all camioes of this enterprise*/
    vector <Servicos*> ser; /**<Vector that contais all services offered for the enterprise*/
public:
    /**
     * @brief Constructor for the class
     */
    Empresa();
    /**
     * @brief Destructor for the class that cleans all the alocated vectors
     */
    ~Empresa();
    /**
     * @brief Calculates the profit of the month
     * @return Returns the profit of the month
     */
    float getLucro_mes() const;
    /**
     * @return Returns the number of clients
     */
    size_t get_numClientes() const;
    /**
     * @return Returns the number of camioes
     */
    size_t get_numCamiao() const;
    /**
     * @return Returns the number of services
     */
    size_t get_numServicos() const;
    /**
     * @brief Add a new client to the vector cli
     * @param name The name of the new client
     * @param nif Personal numeration of the client
     */
    void addClientes(const string& name,const unsigned int& nif);
    template<class T> float getLucro_camiaoMes(const T& c) const;
    /**
     * @brief This function prints on the screen the information about the client(s). Case the nif is given it just print the information of one client (which has the nif given).
     * @param n Number of clients to print
     * @param nif Personal numeration of the client
     */
    void display_clientesInfo(const unsigned int& n, const unsigned int& nif = 0);
    /**
     * @brief Displays in a simple way the total profit of the month
     */
    void display_lucro_mes();
    /**
     * @brief This function prints on the screen the information about the service(s). Case the id is given it just print the information of one service (which has the id give).
     * @param n Number of the services to print
     * @param id Identification number of the service
     */
    void display_servicoStatus(const unsigned int& n, const unsigned int& id = 0);

};


#endif //AEDA_PROJ1_EMPRESA_H
