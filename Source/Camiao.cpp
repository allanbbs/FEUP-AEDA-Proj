//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"

//Base class//
Camiao::Camiao(const unsigned int& carg, const unsigned int& id) {
    CargaMax = carg;
    this->id = id;
}

Camiao::~Camiao() {}


//bool Camiao::operator<(class Camiao) const {}

//Congelado sub-class//
Congelado::Congelado(unsigned int carg, double temp, unsigned int Id) : Camiao(carg,Id){
    temperatura = temp;
}

Congelado::~Congelado() {}

double Congelado::getTemp() const {
    return temperatura;
}

double Congelado::cal_preco() {
    //to implement after checking taxes format
    return tax* 0.01 * temperatura * CargaMax;
}
string Congelado::getType() {return "Congelado";}

//Perigoso sub-class//

Perigoso::Perigoso(unsigned int carg, int lvl, unsigned int Id) : Camiao(carg, Id){
    quaoPerigoso = lvl;
}
Perigoso::~Perigoso() {}

int Perigoso::getLevel() const {
    return quaoPerigoso;
}

double Perigoso::cal_preco() {
    return tax*0.01*(double)quaoPerigoso*CargaMax;
}

string Perigoso::getType() {return "Perigoso";}

//Animals sub-class//
Animals::Animals(unsigned int carg, int number, unsigned int Id) : Camiao(carg, Id){
    animalCount = number;
}
Animals::~Animals() {}

int Animals::getAnimalCount() const {
    return animalCount;
}

double Animals::cal_preco() {
    return tax*0.01*animalCount*CargaMax;
}

string Animals::getType() {return "Animal";}

//Base subClass//
string Base::getType() {
    return "Base";
}

double Base::cal_preco() {
    return tax*0.01 *CargaMax;
}