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
Congelado::Congelado(unsigned int carg, bool disp, double temp) : Camiao(carg){
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

//Perigoso sub-class//

Perigoso::Perigoso(unsigned int carg, bool disp, int lvl) : Camiao(carg){
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

//Animals sub-class//
Animals::Animals(unsigned int carg, bool disp, int number) : Camiao(carg){
    animalCount = number;
}
Animals::~Animals() {}

int Animals::getAnimalCount() const {
    return animalCount;
}

double Animals::cal_preco() {
    return tax;
}
