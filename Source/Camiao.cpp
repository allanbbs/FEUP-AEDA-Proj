//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"

//Base class//
Camiao::Camiao(unsigned int carg) {
    CargaMax = carg;
}

Camiao::~Camiao() {}

double Camiao::cal_preco() {
    //to implement after checking tax format//
    return tax;
}
//Congelado sub-class//
Congelado::Congelado(unsigned int carg, double temp) : Camiao(carg){
    temperatura = temp;
}

Congelado::~Congelado() {}

double Congelado::getTemp() const {
    return temperatura;
}

double Congelado::cal_preco() {
    //to implement after checking taxes format
    return tax;
}
string Congelado::getType() {return "Congelado";}

//Perigoso sub-class//

Perigoso::Perigoso(unsigned int carg, int lvl) : Camiao(carg){
    quaoPerigoso = lvl;
}
Perigoso::~Perigoso() {}

int Perigoso::getLevel() const {
    return quaoPerigoso;
}

double Perigoso::cal_preco() {
    //to implement after checking tax format
    return tax;
}

string Perigoso::getType() {return "Perigoso";}

//Animals sub-class//
Animals::Animals(unsigned int carg, int number) : Camiao(carg){
    animalCount = number;
}
Animals::~Animals() {}

int Animals::getAnimalCount() const {
    return animalCount;
}

double Animals::cal_preco() {
    return tax;
}

string Animals::getType() {return "Animal";}
