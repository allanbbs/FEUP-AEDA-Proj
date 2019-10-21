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
     * @param carg CargaMax in kg measure
     */
    explicit Camiao(unsigned int carg);
    /*
     * Default destructor
     */
    ~Camiao();
    /**
     * @return the price of the camiao
     */
    virtual double cal_preco();
    /**
     * @return the type of the camiao
     */
    virtual string getType() = 0;

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
    Congelado(unsigned int carg, double temp);
    /**
     * Default destructor
     */
    ~Congelado();
    double getTemp() const;                /**<Get the temperature*/
    double cal_preco();
    string getType();
};


class Perigoso : public Camiao {
private:
    int quaoPerigoso;       /**<How dangerous an animal is in a scale of 0-10*/
    double tax = table->table["Perigoso"];/**<Get the taxes*/
public:
    /**
     * Constructor
     * @param carg cargaMax
     * @param disp If it's available or not
     * @param lvl How dangerous the animal is
     */
    Perigoso(unsigned int carg, int lvl);
    ~Perigoso();
    double cal_preco();
    int getLevel() const;       /**<Get quaoPerigoso*/
    string getType();
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
    Animals(unsigned int carg, int number);
    ~Animals();                 /**<Destructor*/
    int getAnimalCount() const; /**<Get how many animals there are in a camiao*/
    void removeAnimal() { animalCount--; }
    void addAnimal() { animalCount++; }
    double cal_preco();
    string getType();
};


#endif //AEDA_PROJ1_CAMIAO_H
