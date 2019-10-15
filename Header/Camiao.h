//
// Created by allanbs on 15/10/19.
//
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef AEDA_PROJ1_CAMIAO_H
#define AEDA_PROJ1_CAMIAO_H

class Camiao{
protected:
    unsigned int CargaMax;
    bool disponibilidade;
    public:
        Camiao(unsigned int carg,bool disp = true);
        Camiao(ifstream&v);
        ~Camiao();
        virtual float cal_preco();
    };


class Congelado:public Camiao{
    private:
        int temperatura;
    public:
        Congelado(unsigned int carg,bool disp,int temp);bool
        ~Congelado();
        int getTemp() const;
        float cal_preco();
};


class Perigoso: public Camiao{
private:
    int quaoPerigoso;
public:
    Perigoso(unsigned int carg,bool disp,int lvl);
    ~Perigoso();
    float cal_preco();
    int getLevel() const;
};

class Animals: public Camiao{
    private:
        int animalCount;
    public:
        Animals(unsigned int carg,bool disp,int number);
        ~Animals();
        int getAnimalCount() const;
        void removeAnimal(){animalCount--;}
        void addAnimal(){animalCount++;}
        float cal_preco();
};






















































































#endif //AEDA_PROJ1_CAMIAO_H
