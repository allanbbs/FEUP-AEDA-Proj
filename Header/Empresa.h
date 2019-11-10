//
// Created by maruba on 14/10/19.
//

#ifndef AEDA_PROJ1_EMPRESA_H
#define AEDA_PROJ1_EMPRESA_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Camiao.h"
#include "Servicos.h"
#include "Errors.h"
#include "Clientes.h"

/**
 * @file Empresa.h
 * @brief It contains the Empresa class declarations, resposable for the management of the enterprise
 */
using namespace std;

/**
 * @brief Class that manages an enterprise
 */
class Empresa {
private:
    vector<Clientes *> cli;     /**< Vector that contains all clients of this enterprise*/
    vector<Camiao *> cam;       /**<Vector that contais all camioes of this enterprise*/
    vector<Servicos *> ser;     /**<Vector that contais all services offered for the enterprise*/

public:
    static size_t nCam;         /**<How many trucks there are in the enterprise**/
    static size_t nCli;         /**<How many clients there are in the enterprise**/
    static size_t nSer;         /**<How many services there are in the enterprise in a specific month**/
    /**
     * @brief Read information from clients.txt file and build the cli vector
     */
    void gravaCli();
    /**
     * @brief Read information from camioes.txt file and build the cam vector
     */
    void gravaCam();
    /**
     * @brief Read information from servicos.txt file and build the ser vector
     */
    void gravaSer(Empresa &e, const int& month);
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
    double getLucro_mes() const;

    /**
     * @brief Add a new client to the vector cli
     * @param name The name of the new client
     * @param nif Personal numeration of the client
     */
    void addClientes(const string &name, const unsigned int &nif);
    /**
     * @param Partida Departure Local
     * @param Destino Arrival local
     * @param Id Identificantion for the service
     * @param Tipo What kind of products it will transport
     */
    Servicos * addServico(Servicos* s, const unsigned int cliNif);

    /**
     * @brief It adds a new truck to the enterprise
     * @param type the type of the trucm
     * @param cargaMax max number of items
     * @param caract the special caracteristic for the type of the truck: temperatura, quaoPerigoso or animalCount
     */
    void addCamiao(const int&  type, const unsigned int &cargaMax, const double& caract = -1);
    /**
     * @brief Search for a client with nif given
     * @param nif Identification of the client
     * @return Return the position of client in the vector cli
     */
    long int SearchCli(const unsigned int &nif) const;

    /**
     * @brief Search for a service with the id given
     * @param id Identification of the service
     * @return Return the position of the service in the vector ser. If it doesn't exist throw an exception
     */
    size_t SearchSer(const unsigned int &id) const;
    /**
     * @brief Get the profit of the month for a specific type o truck
     * 
     * @param type 
     * @return double 
     */
    double getLucro_camiaoMes(const string& type) const;

    /**
     * @brief Display the clients information in a specific format
     * 
     * @param nif Case it's a specific nif, the parameter nif must be diferent from zero
     * @param n Number of clients to be shown
     * @param f Function used to sort the vector
     */
    void display_clientesInfo(const unsigned int &nif= 0, long int n = 1, bool (*f)(const Clientes* c, const Clientes* c1) = Compare_clientes);
    /**
     * @brief Displays in a simple way the total profit of the month
     */
    void display_lucro_mes();
    /**
     * @brief display profit of each truck type
     * 
     */
    void display_CamiaoProfit();

    /**
     * @brief 
     * 
     * @param id Identification of the service which must be different from zero case needs to display a specific service
     * @param n Number of services
     * @param f Function to sort the vector
     * @param type Type of the service (if it's necessary)
     */
    void display_servicoStatus(const unsigned int &id = 0, long int n = 10000, bool(*f)(const Servicos*, const Servicos*) = Compare_servico_profit, const string& type = "") const;

    /**
     * @brief Add a truck to a specific service based on its id
     * 
     * @param id Identification of the truck
     * @param s Service to the truck be added to
     */
    void addCamiaoId_Servico(const int& id, Servicos* s);
    /**
     * @brief Choose trucks to be allocated to a service
     * 
     * @param s Service requesting trucks
     * @return true if it allocated trucks successfully
     * @return false if it didn't allocate trucks successfully
     */
    bool allocateCamiao(Servicos* s);
};

/**
 * @brief Header for list of services
 * 
 */
void headerServInfor();
/**
 * @brief Header for list of trucks
 * 
 */
void headerCamInfor();


#endif //AEDA_PROJ1_EMPRESA_H
