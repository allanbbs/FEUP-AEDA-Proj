//
// Created by maruba on 23/12/19.
//

#include "../Header/Motorista.h"

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

ostream &operator<<(ostream &out,const Motorista& w){
    out << left << setw(30) << w.getName() << setw(20) << w.getNif() << w.getHours() << endl;
    return out;
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

void Workers::printBST(int n) {
    int counter = 0;
    BSTItrIn<Motorista> it(BST_Workers);
    while(!it.isAtEnd()){
        counter ++;
        cout << it.retrieve();
        it.advance();
        if (counter == n) break;
    }

}
void Workers::printBST_reversed(int n){
    int counter = 0;
    vector<Motorista> m;
    BST_Workers.getReversedTree(m);
    for (auto const& it: m){
        counter ++;
        cout << it;
        if (counter == n) break;
    }
}

void Workers::printBST_alphabetic(int n) {
    vector<Motorista> m;
    int counter = 0;
    BSTItrLevel<Motorista> it (BST_Workers);
    while(!it.isAtEnd()){
        m.push_back(it.retrieve());
        it.advance();
    }
    sort(m.begin(),m.end(), [](const Motorista& worker1, const Motorista& worker2){return worker1.getName() < worker2.getName();});
    for (const auto & i: m){
        counter ++;
        cout << i;
        if (counter == n) break;
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

Motorista Workers::check_nif(long long Nif) const{
    BSTItrLevel<Motorista> it(BST_Workers);
    while(!it.isAtEnd()){
        if (it.retrieve().getNif() == Nif) return it.retrieve();
        it.advance();
    }
    throw NoWorker();
}