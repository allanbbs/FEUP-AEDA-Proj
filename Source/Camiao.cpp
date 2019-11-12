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

void Camiao::removeTruck() {
    this-> CargaMax = -CargaMax;
}

Congelado::Congelado(long long int carg, long long int Id) : Camiao(carg,Id){}

Congelado::~Congelado() {}

double Congelado::cal_preco() {
    //to implement after checking taxes format
    long long int Carga_positive = CargaMax < 0?  -CargaMax: CargaMax;
    return tax * (double)Carga_positive;
}

string Congelado::getType() const {return "Congelado";}

Perigoso::Perigoso(long long int carg, long long int Id) : Camiao(carg, Id){}

Perigoso::~Perigoso() {}

double Perigoso::cal_preco() {
    return tax*(double)CargaMax;
}

string Perigoso::getType() const {return "Perigoso";}

Animals::Animals(long long int carg, long long int Id) : Camiao(carg, Id){}

Animals::~Animals() {}

double Animals::cal_preco() {
    return tax*CargaMax;
}

string Animals::getType() const {
    return "Animal";}

string Base::getType() const {
    return "Base";
}

double Base::cal_preco() {
    return tax*CargaMax;
}

bool Compare(const Camiao* c1, const Camiao* c2){
    if (c1->getProfit() < c2->getProfit()) return true;
    else if (c1->getProfit() > c2->getProfit()) return false;
    else if (c1->getCargaMax() < c2->getCargaMax() ) return true;
    else if (c1->getCargaMax() > c2->getCargaMax()) return false;
    return true;
}