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
 * @file Camiao.h
 * @brief It contains the declarations of the class Camiao and its sub-classes.
 */

/**
 * @brief Class responsable for truck management
 */
class Camiao {
protected:
    long long int CargaMax;                  /**<Camiao max storage, if negative means that the truck is not available anymore*/
    long long int id;                        /**<The camiao identification*/
    double totalProfit;                     /**<Total profit the of the truck**/
public:
    /**
     * Contructor
     * @param carg CargaMax in kg measure
     * @param id identification of the truck
     */
    Camiao(const long long int& carg, const long long int& id);
    /**
     * @brief Default destructor
     */
    virtual ~Camiao();
    /**
     * @return the default price of the truck for one service
     */
    virtual double cal_preco() = 0;
    /**
     * @return the type of the truck
     */
    virtual string getType() const = 0;
    /**
     * @brief Compute that the truck was added to a service and then increase it's total Profit
     *
     */
    void addedToService();
    /**
     * @brief Get the Id parameter
     * @return int
     */
    int getId() const { return id; }
    /**
     * @brief Get the Carga Max parameter
     * @return int
     */
    int getCargaMax() const {return CargaMax;}
    /**
     * @brief Get the Profit parameter
     * @return double
     */
    double getProfit() const {return totalProfit; }


};

/**
 * @brief Camiao Truck with frozens as product
 *
 */
class Congelado : public Camiao {
private:
    double temperatura;                                 /**<Temperature*/
    double tax = table->table["Congelado"];             /**<Get the taxes*/
public:
    /**
     * Contructor
     * @param carg cargaMax
     * @param disp If it's available or not
     * @param temp Temperature
     */
    Congelado(long long int carg, double temp, long long int Id);
    /**
     * Default destructor
     */
    ~Congelado();
    /**
     * @brief Get the Temp parameter
     * @return double
     */
    double getTemp() const;
    /**
     * @brief The default price of the truck for one service
     * @return double
     */
    double cal_preco();
    /**
     * @brief Get the Type parameter
     * @return string
     */
    string getType() const;
};

/**
 * @brief Camiao Sub class that handles trucks with dangerous products 
 * 
 */
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
    Perigoso(long long int carg, int lvl, long long int Id);
    /**
     * Default destructor
     *@brief Destroy the Perigoso object
     */
    ~Perigoso();
    double cal_preco();
    /**
     * @brief Get the Level of dangerous
     * @return int
     */
    int getLevel() const;
    /**
     * @brief Get the Type parameter
     * @return string
     */
    string getType() const;
};

/**
 * @brief Camiao Truck with animals as product
 */
class Animals : public Camiao {
private:
    int animalCount;                            /**<How many animal there are in a camiao*/
    double tax = table->table["Animal"];        /**<Get the taxes*/
public:
    /**
     * Contructor
     * @param carg CargaMax
     * @param disp If it's available or not
     * @param number id
     */
    Animals(long long int carg, int number, long long int Id);
    /**
     * Default destructor
     *
     */
    ~Animals();
    /**
     * @brief Get the Animal Count parameter
     * @return int
     */
    int getAnimalCount() const;
    /**
     * @brief The default price of the truck for one service
     * @return double
     */
    double cal_preco();
    /**
     * @brief Get the Type parameter
     * @return string
     */
    string getType() const;
};

/**
 * @brief Camiao Sub class for base products
 */
class Base: public Camiao {
private:
    double tax = table->table["Base"];      /**<Get the taxes*/
public:
    /**
     * @brief Construct a new Base object
     * @param carg The actual storage
     * @param Id The identification number of the truck
     */
    Base(long long int carg, long long int Id): Camiao(carg, Id) {};
    /**
     * @brief Get the Type object
     * @return string
     */
    string getType() const;
    /**
     * @brief The default price of the truck for one service
     * @return double
     */
    double cal_preco();

};

/**
 * @brief It compares two trucks
 *
 * @param c1 first client
 * @param c2 second client
 * @return true if profit c1 < c2. If they have the same profit compare the max storage c1<c2. If they have the same storage return true
 * @return false  if profit c2 < c1. If they have the same profit compare the max storage c2<c1.
 */
bool Compare(const Camiao* c1, const Camiao* c2);
#endif //AEDA_PROJ1_CAMIAO_H
