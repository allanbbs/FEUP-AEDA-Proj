//
// Created by maruba on 14/10/19.
//

#include "../Header/Servicos.h"


Servicos::Servicos() {
    id = -1;
}

Servicos::Servicos(const Local &Partida, const Local &Destino, const unsigned int &Id,const string& Tipo) : id(Id), partida(Partida),
                                                                                         destino(Destino), tipo(Tipo) {};

Servicos::~Servicos() {
    for (int i = 0; i < num_camiao(); i++) delete camioes[i];
    camioes.clear();
}

float Servicos::cal_preco() {
    float tax = 0.2;
    float lucro = 0;
    for (auto it = camioes.begin(); it < camioes.end(); it++) {
        lucro += (*it)->cal_preco();
    }
    lucro += (float) num_camiao() * tax * cal_tempo();
    return lucro;
}

float Servicos::cal_tempo() {
    float velocity = 60;
    double multiplier = PI / 180.0;
    float x1 = partida.get_Coordx() * multiplier;
    float x2 = destino.get_Coordx() * multiplier;
    float y1 = partida.get_Coordy() * multiplier;
    float y2 = destino.get_Coordy() * multiplier;
    double dy = y2 - y1;
    double r = 6378.137;

    double distance = acos(sin(x1)*sin(x2)+cos(x1)*cos(x2)*cos(dy))*r;

    return distance / velocity;
}

int Servicos::num_camiao() {
    return camioes.size();
}

unsigned int Servicos::get_id() {
    return id;
}

ostream &operator<<(ostream &os, Servicos servico) {
    cout.fill();
    os << left << setw(10) << servico.get_id()
               << setw(15) << servico.get_tipo()
               << setw(10) << servico.cal_tempo()
               << setw(30) << servico.get_partida()
               << setw(30) << servico.get_destino()
               << setw(10) << servico.num_camiao()
               << setw(10) << servico.cal_preco() << endl;
    return os;
}

string Servicos::get_destino() {
    return destino.getName();
}

string Servicos::get_partida() {
    return partida.getName();
}

string Servicos::get_tipo() {
    return tipo;
}