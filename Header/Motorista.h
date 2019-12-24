//
// Created by maruba on 23/12/19.
//

#ifndef AEDA_PROJ1_MOTORISTA_H
#define AEDA_PROJ1_MOTORISTA_H
#include "bst.h"
#include <string>
#include <vector>


class Motorista {
private:
    std::string name;
    long long int nif;
    float hours;
public:
    /**
     * @brief Default constructor
     */
    Motorista(): name(""), nif(0), hours(0) {};
    /**
     * Constructor for the Motorista
     * @param name The name of the worker
     * @param nif The nif of the worker
     * @param Hours Number of daily hours
     */
    Motorista(std::string Name, long long int Nif, float Hours): name(Name), nif(Nif), hours(Hours){};
    /**
     * @brief Organized by growing order of hours
     * @param driver The Motorista to be compared to
     * @return True: case the number of hours is less then the number of hours of driver, false otherwise
     */
    bool operator<(const Motorista &driver) const;
    /**
     * @brief Compares two Motorista variables
     * @param driver The Motorista to be compared to
     * @return True: case are equal, false otherwise
     */
    bool operator==(const Motorista &driver) const;
    /**
     * @brief Get the number of hours until now
     * @return Float with hours
     */
    float getHours() const;
    /**
     * @brief Get the name of the motorista
     * @return string with the name
     */
    std::string getName() const;
    /**
     * Get the Nif
     * @return the NIF
     */
    long long int getNif() const;
    /**
     * Set the hours worked in a day
     * @param h The hours to be set
     * @return true: if h <= 24; else false
     */
    bool setHours(const float & h);

};


class Workers{
private:
    BST<Motorista> BST_Workers;
public:
    /**
     * Default constructor
     */
    Workers(): BST_Workers(Motorista("",0,0)) {};
    /**
     * Get the Binary Tree in a vector in a In order sequence
     * @return Vector with the binary tree
     */
    vector<Motorista> getBST();
    /**
     * Adds a worker to the BST
     * @param new_motorista The worker to be added
     * @return return true if the worker was added, else false
     */
    bool addMotorista(const Motorista& new_motorista);
    /**
     * @brief prints the content of the BST
     */
    void printBST();
    /**
     * @brief Prints the content of the BST by reverse order, so that the elements are in descending order of hours
     */
    void printBST_reversed();
    /**
     * @brief read from Ficheiros, the file with Motoristas and insert on the BST
     */
    void readMotorista();

};




#endif //AEDA_PROJ1_MOTORISTA_H
