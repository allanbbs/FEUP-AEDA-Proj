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

#define PI 3.14159265358979323846

#include "Local.h"
#include "Camiao.h"

using namespace std;


class Servicos {
private:
    unsigned int id;
    std::vector<Camiao *> camioes;           /**<Vector with all the camioes used to this service*/
    Local arrival;                          /**<Arrival place */
    Local departure;                        /**<Departure place */
    string type;                            /**<Type of the products transporting*/
    bool status;                            /**<If the service is complete */
    float profit;                           /**<Profit of the service*/
    float base_profit;
public:
    /**
     * @brief Default contructor for Servicos
     */
    Servicos();

    /**
     * @brief Constructor for Servicos
     * @param Departure Name of the departure place
     * @param Arrival Name of the arrival place
     * @param Id Identification for the service
     * @param profit is initialized by cal_profit() function
     */
    Servicos(const Local &Departure, const Local &Arrival, const unsigned int &Id, const string &Tipo);

    /**
     * @brief Default destructor
     */
    ~Servicos();

    /**
     * @brief Calculates the price according to the time of traveling, price of each camiao and the fixed tax
     * @param tax Fixed tax established by the enterprise
     * @param profit the total profit to be returned
     * @return Returns the profit based on the time
     */
    void cal_profitTime();

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
     * @brief Stores the information about the client at os;
     * @param out Ostream to store the information
     * @param servico Service to be displayed
     * @return Returns the ostream os
     */
    friend ostream &operator<<(ostream &out, Servicos servico);

    /**
     * @return Get the id of the service
     */
    unsigned int get_id();

    /**
     * @return the profit
     */
    float get_profit() const;

    /**
     * @return Returns the name of departure
     */
    string get_departure() const;

    /**
     * @return Returns the name of arrival
     */
    string get_arrival() const;

    /**
     * @return Returns the type of the service. What kind produtct it will transport
     */
    string get_tipo() const;

    /**
     * @brief status = false, service is not complete
     */
    void set_statusFalse();

    /**
     * @brief status = true, service is complete
     */
    void set_statusTrue();

    /**
     * Adds a camiao to the service and increase the profit variable based on the camiao profit
     * @param camiao
     */
    void addCamiao(Camiao *camiao);

    /**
     * If the same service is requested again by another client, the profit doubles
     */
    void request();

};


#endif //AEDA_PROJ1_SERVICOS_H
