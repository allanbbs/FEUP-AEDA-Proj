//
// Created by allanbs on 15/10/19.
//
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "TaxTable.h"

using namespace std;
#ifndef AEDA_PROJ1_CAMIAO_H
#define AEDA_PROJ1_CAMIAO_H
extern TaxTable *table;

/**
 * @brief Class responsable for camiao management
 */
class Camiao {
protected:
    unsigned int CargaMax;                /**<Camiao max storage*/
private:
    double tax = table->table["Base"];  /**<Get the taxes*/
public:
    /**
     * Contructor
     * @param carg CargaMax
     * @param disp If a camiao is available or not
     */
    explicit Camiao(unsigned int carg);
    ~Camiao();                          /**<Destructor*/
    virtual double cal_preco();         /**<Price of the camiao service*/
};


class Congelado : public Camiao {
private:
    double temperatura;                      /**<Temperature*/
    double tax = table->table["Congelado"];/**<Get the taxes*/
public:
    /**
     * Contructor
     * @param carg cargaMax
     * @param disp If it's available or not
     * @param temp Temperature
     */
    Congelado(unsigned int carg, bool disp, double temp);
    ~Congelado();
    double getTemp() const;                /**<Get the temperature*/
    double cal_preco();
};


class Perigoso : public Camiao {
private:
    int quaoPerigoso;       /**<How dangerous an animal is*/
    double tax = table->table["Perigoso"];/**<Get the taxes*/
public:
    /**
     * Constructor
     * @param carg cargaMax
     * @param disp If it's available or not
     * @param lvl How dangerous the animal is
     */
    Perigoso(unsigned int carg, bool disp, int lvl);
    ~Perigoso();
    double cal_preco();
    int getLevel() const;       /**<Get quaoPerigoso*/
};

/**
 * Camiao with animals as product
 */
class Animals : public Camiao {
private:
    int animalCount;                    /**<How many animal there are in a camiao*/
    double tax = table->table["Animal"];/**<Get the taxes*/
public:
    /**
     * Contructor
     * @param carg CargaMax
     * @param disp If it's available or not
     * @param number id
     */
    Animals(unsigned int carg, bool disp, int number);
    ~Animals();                 /**<Destructor*/
    int getAnimalCount() const; /**<Get how many animals there are in a camiao*/
    void removeAnimal() { animalCount--; }
    void addAnimal() { animalCount++; }
    double cal_preco();
};


#endif //AEDA_PROJ1_CAMIAO_H
