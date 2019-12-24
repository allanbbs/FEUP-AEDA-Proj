//
// Created by maruba on 23/12/19.
//

#include "../Header/Motorista.h"
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;

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

bool Workers::addMotorista(const Motorista& new_motorista) {
    return this->BST_Workers.insert(new_motorista);

}

void Workers::printBST() {
    BSTItrIn<Motorista> it(BST_Workers);
    while(!it.isAtEnd()){
        cout << left << setw(30) << it.retrieve().getName() << setw(20) << it.retrieve().getNif() << it.retrieve().getHours() << endl;
        it.advance();
    }

}

void Workers::readMotorista() {
    string name, aux;
    fstream file;
    file.open("../AEDA_Proj1/Ficheiros/Motoristas");
    while(!file.eof()){
        getline(file, name);
        getline(file, aux);
        long long int nif = stoi(aux);
        getline(file, aux);
        float hours = stof(aux);

        BST_Workers.insert(Motorista(name, nif, hours));
    }

}