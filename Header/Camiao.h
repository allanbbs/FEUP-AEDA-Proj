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
extern TaxTable* table;

class Camiao{
protected:
    unsigned int CargaMax;
    bool disponibilidade;
private:
    double tax = table->table["Base"];
public:
    explicit Camiao(unsigned int carg,bool disp = true);
    ~Camiao();
    virtual double cal_preco();
    };


class Congelado:public Camiao{
    private:
        int temperatura;
        double tax = table->table["Congelado"];
    public:
        Congelado(unsigned int carg,bool disp,int temp);
        ~Congelado();
        int getTemp() const;
        double cal_preco();
};


class Perigoso: public Camiao{
private:
    int quaoPerigoso;
    double tax = table->table["Perigoso"];
public:
    Perigoso(unsigned int carg,bool disp,int lvl);
    ~Perigoso();
    double cal_preco();
    int getLevel() const;
};

class Animals: public Camiao{
    private:
        int animalCount;
        double tax = table->table["Animal"];
    public:
        Animals(unsigned int carg,bool disp,int number);
        ~Animals();
        int getAnimalCount() const;
        void removeAnimal(){animalCount--;}
        void addAnimal(){animalCount++;}
        double cal_preco();
};






















































































#endif //AEDA_PROJ1_CAMIAO_H
