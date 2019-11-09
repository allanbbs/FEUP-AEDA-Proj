//
// Created by maruba on 14/10/19.
//

#include "../Header/Servicos.h"
//empty constructor
Servicos::Servicos() {
    id = -1;
}

/**
 * @brief servicos constructor
 * @param Departure -  departures local
 * @param Arrival - arrivals local
 * @param Id - services id
 * @param Tipo - services type
 * @param Carga - type of cargo
 */
Servicos::Servicos(const Local &Departure, const Local &Arrival, const unsigned int &Id,const string& Tipo, const int & Carga) : id(Id), departure(Departure),

                                                                                         arrival(Arrival), type(Tipo), carga(Carga) {
    profit = 0;
    cal_profitTime();
};

/**
 * @function it calculates the profits with a pre determined by the time of the derivery
 */
void Servicos::cal_profitTime() {
    double tax = 75;
    profit += tax * cal_tempo();
    for (auto it = camioes.begin(); it < camioes.end(); it++)
        profit += (*it)-> cal_preco();
}
/**
 *
 * @return returns the time spends in the total travel
 */
double Servicos::cal_tempo() {
    double velocity = 60;
    double multiplier = PI / 180.0;
    double x1 = departure.get_Coordx() * multiplier;
    double x2 = arrival.get_Coordx() * multiplier; // get the coordinates of the locals (arrival and departure)
    double y1 = departure.get_Coordy() * multiplier;
    double y2 = arrival.get_Coordy() * multiplier;
    double dy = y2 - y1;
    double r = 6378.137; //radius of the earth

    double distance = acos(sin(x1)*sin(x2)+cos(x1)*cos(x2)*cos(dy))*r;
    // it calculates the distance between the two points
    return distance / velocity; //
}

/**
 * @function implementation of the operator <<
 * @param os
 * @param servico - service that will be show
 * @return -all info of service
 */
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

/**
 *
 * @return it returns the id of the service
 */
unsigned int Servicos::get_id() const{
    return id;
}
/**
 *
 * @return it returns the id of the profit
 */
double Servicos::get_profit() const {
    return profit;
}

/**
 *
 * @return it returns the name of the local of the departure destiny
 */
string Servicos::get_departure() const{
    return departure.getName();
}
/**
 *
 * @return it returns the name of the local of  the arrival destiny
 */

string Servicos::get_arrival() const{
    return arrival.getName();
}
/**
 *
 * @return it returns the type of the service
 */
string Servicos::get_tipo() const{
    return type;
}

/**
 *
 * @return // it returns the cargo
 */
int Servicos::get_carga() const {
    return carga;
}

//todo we dont wanna add a space to the last element
/**
 *
 * @return all trucks ids
 */
string Servicos::get_camioes_id() const {
    string s;

    for (int i = 0; i< camioes.size()-1; i++)
        s += to_string(camioes[i]->getId())+" ";
    
    //todo the last element must not contain a space
    s += to_string(camioes[camioes.size()-1]->getId());
    return s;
}

/**
 * @function function that adds a truck to the camioes vector
 * @param camiao - a truck
 */
void Servicos::addCamiao(Camiao *camiao) {
    camioes.push_back(camiao);
    profit += camiao->cal_preco();
    camiao->addedToService();       //increasing the truck totalProfit
}

/**
 * @function function that check if s is bigger tha s1
 * @param s- service
 * @param s1
 * @return - bool (false if s is lesser than s1 )
 */
bool Compare_servico_profit(const Servicos* s, const Servicos* s1){
    if (s->get_profit() < s1->get_profit()) return false;
    else if (s1->get_profit() < s->get_profit()) return true;
    else if(s->get_id() < s1->get_id()) return true;
    return false;
}
/**
 * @function function that check if s is lesser tha s1
 * @param s
 * @param s1
 * @return bool (false if s is bigger than s1 )
 */

bool Compare_servico_Leastprofit(const Servicos *s, const Servicos *s1){
    if (s->get_profit() < s1->get_profit()) return true;
    else if (s1->get_profit() < s->get_profit()) return false;
    else if(s->get_id() < s1->get_id()) return false;
    return true;
}



