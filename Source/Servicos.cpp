//
// Created by maruba on 14/10/19.
//

#include "../Header/Servicos.h"

Servicos::Servicos() {
    id = -1;
}

Servicos::Servicos(const Local &Departure, const Local &Arrival, const unsigned int &Id,const string& Tipo, const int & Carga) : id(Id), departure(Departure),

                                                                                         arrival(Arrival), type(Tipo), carga(Carga) {
    profit = 0;
    cal_profitTime();
};

//complexity O^n
void Servicos::cal_profitTime() {
    double tax = 75;
    profit += tax * cal_tempo();
    for (auto it = camioes.begin(); it < camioes.end(); it++)
        profit += (*it)-> cal_preco();
}

double Servicos::cal_tempo() {
    double velocity = 60;
    double multiplier = PI / 180.0;
    double x1 = departure.get_Coordx() * multiplier;
    double x2 = arrival.get_Coordx() * multiplier;
    double y1 = departure.get_Coordy() * multiplier;
    double y2 = arrival.get_Coordy() * multiplier;
    double dy = y2 - y1;
    double r = 6378.137; //radius of the earth

    double distance = acos(sin(x1)*sin(x2)+cos(x1)*cos(x2)*cos(dy))*r;

    return distance / velocity;
}

int Servicos::num_camiao() {
    return camioes.size();
}


ostream &operator<<(ostream &os, Servicos servico) {
    os<<fixed<<setprecision(2);
    cout.fill();
    os << left << setw(10) << servico.get_id()
               << setw(15) << servico.get_tipo()
               << setw(10) << servico.cal_tempo()
               << setw(30) << servico.get_departure()
               << setw(30) << servico.get_arrival()
               << setw(15) << servico.num_camiao()
               << setw(10) << servico.get_profit()
               << servico.carga << endl;
    return os;
}

unsigned int Servicos::get_id() const{
    return id;
}

double Servicos::get_profit() const {
    return profit;
}

string Servicos::get_departure() const{
    return departure.getName();
}

string Servicos::get_arrival() const{
    return arrival.getName();
}

string Servicos::get_tipo() const{
    return type;
}

int Servicos::get_carga() const {
    return carga;
}

//we dont wanna add a space to the last element
string Servicos::get_camioes_id() const {
    string s;

    for (int i = 0; i< camioes.size()-1; i++)
        s += to_string(camioes[i]->getId())+" ";
    
    //the last element must not contain a space
    s += to_string(camioes[camioes.size()-1]->getId());
    return s;
}
void Servicos::addCamiao(Camiao *camiao) {
    camioes.push_back(camiao);
    profit += camiao->cal_preco();
    camiao->addedToService();       //increasing the truck totalProfit
}

bool Compare_servico(const Servicos* c, const Servicos* c1){
    if (c->get_profit() < c1->get_profit()) return false;
    else if (c1->get_profit() < c->get_profit()) return true;
    else if(c->get_id() < c1->get_id()) return true;
    return false;
}



