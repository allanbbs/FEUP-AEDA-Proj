//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"

//Base class//
Camiao::Camiao(unsigned int carg,bool disp) {
    CargaMax = carg;
    disponibilidade = disp;
}

Camiao::Camiao(ifstream &v) {
    //to implement after checking file format//
}

Camiao::~Camiao() {}

float Camiao::cal_preco() {
    //to implement after checking tax format
}
//Congelado sub-class//
Congelado::Congelado(unsigned int carg, bool disp, int temp) : Camiao(carg,disp){
    temperatura = temp;
}

Congelado::~Congelado() {}

int Congelado::getTemp() const {
    return temperatura;
}

float Congelado::cal_preco() {
    //to implement after checking taxes format
    return 0.0;
}

//Perigoso sub-class//

Perigoso::Perigoso(unsigned int carg, bool disp, int lvl) : Camiao(carg,disp){
    quaoPerigoso = lvl;
}
Perigoso::~Perigoso() {}

int Perigoso::getLevel() const {
    return quaoPerigoso;
}

float Perigoso::cal_preco() {
    //to implement after checking tax format
}

//Animals sub-class//
Animals::Animals(unsigned int carg, bool disp, int number) : Camiao(carg,disp){
    animalCount = number;
}
Animals::~Animals() {}

int Animals::getAnimalCount() const {
    return animalCount;
}



