//
// Created by maruba on 14/10/19.
//

#ifndef AEDA_PROJ1_SERVICOS_H
#define AEDA_PROJ1_SERVICOS_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#define PI 3.14159265358979323846
#include "Local.h"

using namespace std;


class Servicos{
private:
    unsigned int id;
    std::vector<Camiao*> camioes;   /**< vector with all the camioes used to this service*/
    Local destino;                  /**< arrival place */
    Local partida;                 /**<  departure place */
    string tipo;
public:
    /**
     * @brief Default contructor for Servicos
     */
    Servicos();
    /**
     * @brief Constructor for Servicos
     * @param Partida Name of the departure place
     * @param Destino Name of the arrival place
     * @param Id Identification for the service
     */
    Servicos(const Local& Partida, const Local& Destino, const unsigned int& Id, const string& Tipo);
    /**
     * @brief Default destructor
     */
    ~Servicos();
    /**
     * @brief Calculates the price according to the time of traveling, price of each camiao and the fixed tax
     * @param tax Fixed tax established by the enterprise
     * @param lucro the total profit to be returned
     * @return Returns the price
     */
    float cal_preco();
    /**
     * @brief Calculates the time of traveling according to geographic cordenates of the arrival and departure.
     * @return Returns the time of traveling
     */
    float cal_tempo();
    /**
     * @return Returns the number of camioes operating on this service
     */
    int num_camiao();
    /**
     * @return Get the id of the service
     */
    unsigned int get_id();
    /**
     * @brief Stores the information about the client at os;
     * @param out Ostream to store the information
     * @param servico Service to be displayed
     * @return Returns the ostream os
     */
    friend ostream & operator <<(ostream& out, Servicos servico);
    /**
     * @return Returns the name of partida
     */
    string get_partida();
    /**
     * @return Returns the name of destino
     */
    string get_destino();
    /**
     * @return Returns the type of the service. What kind produtct it will transport
     */
    string get_tipo();
};




#endif //AEDA_PROJ1_SERVICOS_H
