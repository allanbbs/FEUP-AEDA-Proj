//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"
#include <stack>
#include "../Header/Errors.h"
/**
 *
 * @file Camiao.cpp
 * @brief It contains the implementation of the class Camiao and its sub-classes
 */

Camiao::Camiao(const long long int& carg, const long long int& id,string name) {
    CargaMax = carg;
    this->id = id;
    totalProfit = 0;
    brand = name;
}

Camiao::~Camiao() {}

void Camiao::addedToService() {
    totalProfit += cal_preco();
}

void Camiao::removeTruck() {
    this-> CargaMax = -CargaMax;
}


Workshop Camiao::requestGenericService(priority_queue<Workshop>& aux) {
    //stack<Workshop> aux1;
    //if(aux.empty()) throw EmptyQueue();
    Workshop d = aux.top();
    aux.pop();
    d.setUn(d.get_unavailability() + 7);
    aux.push(d);
    return d;
}

Workshop Camiao::requestSpecificService(priority_queue<Workshop> &aux) {
    stack<Workshop> aux1;
    Workshop d=aux.top();
    while(!aux.empty()){
        if(aux.top().checkForBrand(brand)){
            d = aux.top();
            d.setUn(d.get_unavailability()+20);
            aux1.push(d);
            aux.pop();
        }
        else{
            aux1.push(aux.top());
            aux.pop();
        }
    }
    while(!aux1.empty()){
        aux.push(aux1.top());
        aux1.pop();
    }
    return d;
}




//------------------------------------------------------------------------------------
Congelado::Congelado(long long int carg, long long int Id,string name) : Camiao(carg,Id,name){}

Congelado::~Congelado() {}

double Congelado::cal_preco() {
    //to implement after checking taxes format
    long long int Carga_positive = CargaMax < 0 ?  -CargaMax : CargaMax;  // case the truck is not used anymore the max storage will be negative, but we want to calculate the profit with positive numbers
    return tax * (double)Carga_positive;
}

string Congelado::getType() const {
    return "Congelado";
}

//------------------------------------------------------------------------------------

Perigoso::Perigoso(long long int carg, long long int Id,string name) : Camiao(carg, Id,name){}

Perigoso::~Perigoso() {}

double Perigoso::cal_preco() {
    return tax * (double)CargaMax;
}

string Perigoso::getType() const {return "Perigoso";}

//------------------------------------------------------------------------------------

Animals::Animals(long long int carg, long long int Id,string name) : Camiao(carg, Id,name){}

Animals::~Animals() {}

double Animals::cal_preco() {
    return tax * (double)CargaMax;
}

string Animals::getType() const {
    return "Animal";}


//------------------------------------------------------------------------------------

string Base::getType() const {
    return "Base";
}

double Base::cal_preco() {
    return tax * (double)CargaMax;
}

//------------------------------------------------------------------------------------

bool Compare(const Camiao* c1, const Camiao* c2){
    if (c1->getProfit() < c2->getProfit()) return true;
    else if (c1->getProfit() > c2->getProfit()) return false;
    else if (c1->getCargaMax() < c2->getCargaMax() ) return true;
    else if (c1->getCargaMax() > c2->getCargaMax()) return false;
    return true;
}