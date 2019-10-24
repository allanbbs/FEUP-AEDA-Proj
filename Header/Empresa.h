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

#include "Clientes.h"
#include "Camiao.h"
#include "Servicos.h"
#include "Errors.h"


using namespace std;

/**
 * @brief Class that manages an enterprise
 */
class Empresa {
private:
    vector<Clientes *> cli; /**< Vector that contains all clients of this enterprise*/
    vector<Camiao *> cam;   /**<Vector that contais all camioes of this enterprise*/
    vector<Servicos *> ser; /**<Vector that contais all services offered for the enterprise*/
    static size_t nCam;
    static size_t nCli;
    static size_t nSer;
public:
    /*
     * @brief Read information from clients.txt file and build the cli vector
     */
    void gravaCli();
    /*
     * @brief Read information from camioes.txt file and build the cam vector
     */
    void gravaCam();
    /*
     * @ brief Read information from servicos.txt file and build the ser vector
     */
    void gravaSer();
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
    void addServico(const Local &Partida, const Local &Destino, const string &Tipo, const unsigned int cliNif);

    /**
     * Search for a client with nif given
     * @param nif Identification of the client
     * @return Return the position of client in the vector cli
     */
    long int SearchCli(const unsigned int &nif) const;

    /**
     * Search for a service with the id given
     * @param id Identification of the service
     * @return Return the position of the service in the vector ser. If it doesn't exist throw an exception
     */
    size_t SearchSer(const unsigned int &id) const;

    template<class T>
    double getLucro_camiaoMes(const T &c) const;

    /**
     * @brief This function prints on the screen the information about the client(s). Case the nif is given it just print the information of one client (which has the nif given).
     * @param n Number of clients to print
     * @param nif Personal numeration of the client
     */
    void display_clientesInfo(const unsigned int &n, const unsigned int &nif = 0);

    /**
     * @brief Displays in a simple way the total profit of the month
     */
    void display_lucro_mes();

    /**
     * @brief This function prints on the screen the information about the service(s). Case the id is given it just print the information of one service (which has the id give).
     * @param n Number of the services to print
     * @param id Identification number of the service
     */
    void display_servicoStatus(const unsigned int &id = 0) const;

    vector<Servicos*> getServices() const{
        vector<Servicos*> res(ser);
        return res;
    }
    vector<Clientes*> getClientes() const{
        vector<Clientes*> res(cli);
        return res;
    }

    vector<Camiao*> getCamiao() const{
        vector<Camiao*> res(cam);
        return res;
    }
};


#endif //AEDA_PROJ1_EMPRESA_H
