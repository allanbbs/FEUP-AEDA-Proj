//
// Created by maruba on 23/12/19.
//

#ifndef AEDA_PROJ1_MOTORISTA_H
#define AEDA_PROJ1_MOTORISTA_H
#include "bst.h"
#include <string>


class Motorista {
private:
    std::string name;
    long long int nif;
    float hours;
public:
    /**
     * Default constructor for the Motorista
     * @param name the name of the worker
     * @param nif the nif of the worker
     */
    Motorista(std::string name, int nif);
    bool operator<(const Motorista &driver) const;
    bool operator==(const Motorista &driver) const;
    float getHours() const;
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
    Workers(): BST_Workers(Motorista("",0)) {};
    /**
     * Get the Binary Tree in a vector in a In order sequence
     * @return Vector with the binary tree
     */
    vector<Motorista> getBST();
    /**
     * Adds a worker to the BST
     * @param new_motorista The worker to be added
     */
    void addMotorista(const Motorista& new_motorista);

};




#endif //AEDA_PROJ1_MOTORISTA_H

//
// Created by maruba on 23/12/19.
//

#ifndef AEDA_PROJ1_MOTORISTA_H
#define AEDA_PROJ1_MOTORISTA_H
#include "bst.h"
#include <string>

class Motorista {
private:
    std::string name;
    int hours;
public:
    bool operator<(const Motorista &driver) const;
    int getHours() const;
};


class Workers{
private:
    BST<Motorista> it;
public:

};



#endif //AEDA_PROJ1_MOTORISTA_H
© 2019 GitHub, Inc.