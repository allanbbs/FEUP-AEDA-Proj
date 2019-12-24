//
// Created by maruba on 23/12/19.
//

#ifndef AEDA_PROJ1_MOTORISTA_H
#define AEDA_PROJ1_MOTORISTA_H
#include "bst.h"
#include "Errors.h"

#include <fstream>
#include <iomanip>
#include <istream>
#include <algorithm>
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

    friend ostream &operator<<(ostream &out,const Motorista& w);
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
     * @brief Prints the content of the BST
     * @param n Number of elements to print
     */
    void printBST(int n);
    /**
     * @brief Prints the content of the BST by reverse order, so that the elements are in descending order of hours
     * @param n Number of elements to print
     */
    void printBST_reversed(int n);
    /**
     * @brief read from Ficheiros, the file with Motoristas and insert on the BST
     */
    void readMotorista();

    /**
     * It prints the bst in an alphabetic other of Motorista name
     * @param n Number of elements to be printed
     */
    void printBST_alphabetic(int n);
    /**
     * @brief Search for Motorista with the specif nif
     * @param Nif Nif to be searched
     * @return Return a Motorista with name "" if it doesn't exist, else return the Motorista with the nif asked
     */
    Motorista check_nif(long long int Nif) const;
};




#endif //AEDA_PROJ1_MOTORISTA_H
