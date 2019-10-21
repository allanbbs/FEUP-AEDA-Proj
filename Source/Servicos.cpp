//
// Created by maruba on 14/10/19.
//

#include "../Header/Servicos.h"


Servicos::Servicos() {
    id = -1;
}

Servicos::Servicos(const Local &Departure, const Local &Arrival, const unsigned int &Id,const string& Tipo) : id(Id), departure(Departure),

                                                                                         arrival(Arrival), type(Tipo), status(false) {
    profit = 0;
    base_profit = 0;
    cal_profitTime();
};

Servicos::~Servicos() {
    for (int i = 0; i < num_camiao(); i++) delete camioes[i];
    camioes.clear();
}

void Servicos::cal_profitTime() {
    float tax = 0.2;
    profit += tax * cal_tempo();
    base_profit = tax*cal_tempo();
}

float Servicos::cal_tempo() {
    float velocity = 60;
    double multiplier = PI / 180.0;
    float x1 = departure.get_Coordx() * multiplier;
    float x2 = arrival.get_Coordx() * multiplier;
    float y1 = departure.get_Coordy() * multiplier;
    float y2 = arrival.get_Coordy() * multiplier;
    double dy = y2 - y1;
    double r = 6378.137; //radius of the earth

    double distance = acos(sin(x1)*sin(x2)+cos(x1)*cos(x2)*cos(dy))*r;

    return distance / velocity;
}

int Servicos::num_camiao() {
    return camioes.size();
}


ostream &operator<<(ostream &os, Servicos servico) {
    cout.fill();
    os << left << setw(10) << servico.get_id()
               << setw(15) << servico.get_tipo()
               << setw(10) << servico.cal_tempo()
               << setw(30) << servico.get_departure()
               << setw(30) << servico.get_arrival()
               << setw(15) << servico.num_camiao()
               << setw(10) << servico.profit << endl;
    return os;
}

unsigned int Servicos::get_id() {
    return id;
}

float Servicos::get_profit() const {
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

void Servicos::set_statusFalse() {
    status = false;
}

void Servicos::set_statusTrue() {
    status = true;
}

void Servicos::addCamiao(Camiao *camiao) {
    camioes.push_back(camiao);
    profit += camiao->cal_preco();
    base_profit+= camiao->cal_preco();
}

void Servicos::request() {
    profit+=base_profit;
}
