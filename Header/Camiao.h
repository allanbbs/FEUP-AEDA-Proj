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
    unsigned int id;                        /**<The camiao identification*/
    double totalProfit;
public:
    /**
     * Contructor
     * @param carg CargaMax in kg measure
     */
    Camiao(const unsigned int& carg, const unsigned int& id);
    /*
     * Default destructor
     */
    virtual ~Camiao();
    /**
     * @return the price of the camiao
     */
    virtual double cal_preco() = 0;
    /**
     * @return the type of the camiao
     */
    virtual string getType() = 0;
    void addedToService();
    int getId() { return id; }
    double getProfit() {return totalProfit; }
    friend bool operator<(const Camiao& c1, const Camiao& c2);

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
    Congelado(unsigned int carg, double temp, unsigned int Id);
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
    Perigoso(unsigned int carg, int lvl, unsigned int Id);
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
    Animals(unsigned int carg, int number, unsigned int Id);
    ~Animals();                 /**<Destructor*/
    int getAnimalCount() const; /**<Get how many animals there are in a camiao*/
    //void removeAnimal() { animalCount--; }
    //void addAnimal() { animalCount++; }
    double cal_preco();
    string getType();
};

class Base: public Camiao{
private:
    double tax = table->table["Base"];  /**<Get the taxes*/
public:
    Base(unsigned int carg, unsigned int Id): Camiao(carg, Id) {};
    string getType();
    double cal_preco();

};

#endif //AEDA_PROJ1_CAMIAO_H
