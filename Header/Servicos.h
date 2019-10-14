//
// Created by maruba on 14/10/19.
//

#ifndef AEDA_PROJ1_SERVICOS_H
#define AEDA_PROJ1_SERVICOS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Servicos{
private:
    unsigned int id;
    std::vector<Camiao*> camioes;   /**< vector with all the camioes used to this service*/
    string destino;                 /**< arrival place */
    string partida;                 /**<  departure place */
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
    Servicos(const string& Partida, const string& Destino, const unsigned int& Id);
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
     * @brief Calculates the time of traveling according to geographic cordenates of the arrival and departure
     * @return Returns the time of traveling
     */
    float cal_tempo();
    /**
     * @return Returns the number of camioes operating on this service
     */
    int num_camiao();
    /**
     * @return get the id of the service
     */
    int get_id();
    friend ostream & operator <<(ostream& out, Servicos servico);
};




#endif //AEDA_PROJ1_SERVICOS_H
