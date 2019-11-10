//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"

/**
 *
 * @file Camiao.cpp
 * @brief It contains the implementation of the class Camiao and its sub-classes
 */

//Base class//
Camiao::Camiao(const long long int& carg, const long long int& id) {
    CargaMax = carg;
    this->id = id;
    totalProfit = 0;
}

Camiao::~Camiao() {}

void Camiao::addedToService() {
    totalProfit += cal_preco();
}


//Congelado sub-class//

//constructor of  congelado
Congelado::Congelado(long long int carg, double temp, long long int Id) : Camiao(carg,Id){
    temperatura = temp;
}
// congelado destructor
Congelado::~Congelado() {}
// it returns the temperature of de congelado of the truck
double Congelado::getTemp() const {
    return temperatura;
}

double Congelado::cal_preco() {
    //to implement after checking taxes format
    return tax* 0.01 * temperatura * (double)CargaMax;
}

string Congelado::getType() const {return "Congelado";}

//Perigoso sub-class//
Perigoso::Perigoso(long long int carg, int lvl, long long int Id) : Camiao(carg, Id){
    quaoPerigoso = lvl;
}

Perigoso::~Perigoso() {}

int Perigoso::getLevel() const {
    return quaoPerigoso;
}

double Perigoso::cal_preco() {
    return tax*0.01*(double)quaoPerigoso*(double)CargaMax;
}

string Perigoso::getType() const {return "Perigoso";}

// Animals sub-class//

Animals::Animals(long long int carg, int number, long long int Id) : Camiao(carg, Id){
    animalCount = number;
}

Animals::~Animals() {}

int Animals::getAnimalCount() const {
    return animalCount;
}

double Animals::cal_preco() {
    return tax*0.01*animalCount*CargaMax;
}

string Animals::getType() const {return "Animal";}

//Base subClass//
string Base::getType() const {
    return "Base";
}

double Base::cal_preco() {
    return tax*0.01 *CargaMax;
}

bool Compare(const Camiao* c1, const Camiao* c2){
    if (c1->getProfit() < c2->getProfit()) return true;
    else if (c1->getProfit() > c2->getProfit()) return false;
    else if (c1->getCargaMax() < c2->getCargaMax() ) return true;
    else if (c1->getCargaMax() > c2->getCargaMax()) return false;
    return true;
}