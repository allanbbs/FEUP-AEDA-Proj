//
// Created by maruba on 23/12/19.
//

#include "../Header/Motorista.h"
#include <iomanip>

float Motorista::getHours() const{
    return hours;
}

std::string Motorista::getName() const{
    return name;
}

long long int Motorista::getNif() const{
    return nif;
}

bool Motorista::operator<(const Motorista & driver) const{
    return this->getHours() < driver.getHours();
}

bool Motorista::operator==(const Motorista & driver) const{
    return (this->name == driver.getName() && this->nif == driver.getNif());
}


Motorista::Motorista(std::string name, int nif) {
    this->name = name;
    this->nif = nif;
    this->hours = 0;
}

bool Motorista::setHours(const float & h) {
    if(h > 24 || h<0) return false;
    this->hours= h;
    return true;
}


vector<Motorista> Workers::getBST() {
    BSTItrIn<Motorista> it(BST_Workers);
    vector<Motorista> temp;
    while (!it.isAtEnd()){
        temp.push_back(it.retrieve());
        it.advance();
    }
    return temp;
}

void Workers::addMotorista(const Motorista& new_motorista) {
    bool bosta = this->BST_Workers.insert(new_motorista);

}

void Workers::printBST() {
    BSTItrIn<Motorista> it(BST_Workers);
    while(!it.isAtEnd()){
        cout << left << setw(30) << it.retrieve().getName() << setw(20) << it.retrieve().getNif() << it.retrieve().getHours() << endl;
        it.advance();
    }

}