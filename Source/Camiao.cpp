//
// Created by allanbs on 15/10/19.
//
#include "../Header/Camiao.h"

//Base class//
Camiao::Camiao(const unsigned int& carg, const unsigned int& id) {
    CargaMax = carg;
    this->id = id;
    totalProfit = 0;
}
// c
Camiao::~Camiao() {}

void Camiao::addedToService() {
    totalProfit += cal_preco();
}


//Congelado sub-class//

//constructor of  congelado
Congelado::Congelado(unsigned int carg, double temp, unsigned int Id) : Camiao(carg,Id){
    temperatura = temp;
}
// congelado destructor
Congelado::~Congelado() {}
// it returns the temperature of de congelado of the truck
double Congelado::getTemp() const {
    return temperatura;
}
/**
 *@function  function that calculates the final price of the delivery
 */
double Congelado::cal_preco() {
    //to implement after checking taxes format
    return tax* 0.01 * temperatura * CargaMax;
}
/**
 * @return it return the type of the truck
 */
string Congelado::getType() const {return "Congelado";}

//Perigoso sub-class//

/**
 *@brief perigoso constructor
 */
Perigoso::Perigoso(unsigned int carg, int lvl, unsigned int Id) : Camiao(carg, Id){
    quaoPerigoso = lvl;
}
/**
*@brief perigoso destructor
 */
Perigoso::~Perigoso() {}
/**
*@retun returns how dangerous is the cargo it
 */
int Perigoso::getLevel() const {
    return quaoPerigoso;
}
/**
*@function function that calculates the final price of the delivery
 */
double Perigoso::cal_preco() {
    return tax*0.01*(double)quaoPerigoso*CargaMax;
}
/**
 *@retun it returns the type of the truck
 */
string Perigoso::getType() const {return "Perigoso";}

// Animals sub-class//
/**
 *@brief  animals constructor
 * @param carg - maximun cargo surportd
 * @param number - number of animals
 * @param id- number of identification
 */
Animals::Animals(unsigned int carg, int number, unsigned int Id) : Camiao(carg, Id){
    animalCount = number;
}
/**
 *@brief animals destructor
 */
Animals::~Animals() {}
/**
* @retun it returns the num of animals
 */
int Animals::getAnimalCount() const {
    return animalCount;
}
/**
*@function that calculates the final price od the delivery
 */
double Animals::cal_preco() {
    return tax*0.01*animalCount*CargaMax;
}
/**
 *
 * @return returns the type of the truck
 */
string Animals::getType() const {return "Animal";}

//Base subClass//

/**
 *
 * @brief defult constructor
 */
string Base::getType() const {
    return "Base";
}
/**
//@function function that calculates the final price of the delivery
 */
double Base::cal_preco() {
    return tax*0.01 *CargaMax;
}
/**
 * @function function check c1 is lesser than c2
 */
bool Compare(const Camiao* c1, const Camiao* c2){
    if (c1->getProfit() < c2->getProfit()) return true;
    else if (c1->getProfit() > c2->getProfit()) return false;
    else if (c1->getCargaMax() < c2->getCargaMax() ) return true;
    else if (c1->getCargaMax() > c2->getCargaMax()) return false;
    return true;
}