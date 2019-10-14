//
// Created by maruba on 14/10/19.
//

#include "../Header/Servicos.h"

Servicos::Servicos() {}

Servicos::Servicos(const string &Partida, const string &Destino, const unsigned int &Id): id(Id), partida(Partida), destino(Destino){};

Servicos::~Servicos() {
    for (int i = 0; i < num_camiao(); i++) delete camioes[i];
    camioes.clear();
}

float Servicos::cal_preco() {
    float tax = 0.2;
    float lucro = 0;
    for (auto it = camioes.begin(); it < camioes.end(); it++){
        lucro+= (*it)->cal_preco();
    }
    lucro += (float)num_camiao()*tax*cal_tempo();
    return lucro;
}

float Servicos::cal_tempo() {

}

int Servicos::num_camiao() {
    return camioes.size();
}

int Servicos::get_id() {
    return id;
}
