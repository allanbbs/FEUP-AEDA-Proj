//
// Created by Amanda  on 2019-10-14.
//
#include <vector>
#include "../Header/Clientes.h"
using namespace std;
/**
 * @brief default clients constructor
 */
Clientes::Clientes() {
    name = "";
    nif = 0;
}
/**
* @brief clients constructor
 */
Clientes::Clientes(const string &n, const unsigned int &anif) : name(n), nif(anif), profit(0) {}
/**
 *@brief clients desconstructor
 */

Clientes::~Clientes() {
    for (int i = 0 ; i < services.size(); i++) delete services[i];
    services.clear();
}
/**
 * @return profit of this client
 */

double Clientes::get_profit() const {
    return profit;
}
/**
 * @return return the nif o the client
 */
unsigned int Clientes::get_nif() const {
    return nif;
}
/**
 * @function function that adds a service request by a costumer
 * @param servico
 */
void Clientes::addService(Servicos *servico) {
    services.push_back(servico);
    profit += servico->get_profit();

}
/**
 * @brief clientes constructor
 */

Clientes::Clientes() {
    name = "";
    nif = 0;
}
/**
 *
 * @param out
 * @param client
 * @return returns the name nif and requested services or "no services" announcement 
}
 */

/**
 *
 * @param out
 * @param client
 * @return
 */
ostream &operator<<(ostream &out, const Clientes &client) {
    cout<<fixed<<setprecision(2);
    out << left << setw(30) << client.name << setw(20) << client.nif;

    if (client.services.empty()) out << "No services!" << endl;
//if the client hasn't requested for a service it will be noticed 
    for (auto a: client.services) //else it will prints a list of the requested services
        out << a->get_id() << " ";
    out << endl;

    return out;//returns the name nif and requested services or "no services" announcement 
}
/**
 *
 * @param c
 * @param c1
 * @return true if c is bigger tanh c1, or false if is lesser
 * @function  function that checks if the client c is bigger than c1
 */
bool Compare_clientes(const Clientes* c, const Clientes* c1) {
    if (c->get_profit() < c1->get_profit()) return false;
    else if (c1->get_profit() < c->get_profit()) return true;
    else if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}
/**
 *
 * @param c
 * @param c1
 * @return true if c is lesser tanh c1, or false if is bigger
 * @function function that checks if the client c is lesser than c1 p
 */
bool Compare_clientesLeast(const Clientes *c, const Clientes* c1){
    if (c->get_profit() < c1->get_profit()) return true;
    else if (c1->get_profit() < c->get_profit()) return false;
    else if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}
/**
 *
 * @param c
 * @param c1
 * @return true if the name of c is alphabetic bigger than c
 * @function function that compares the name of clients only by name
 */

bool Compare_clientesAlphabetic(const Clientes *c, const Clientes* c1){
    if(c->getName() < c1->getName()) return true;
    else if (c1->getName() < c->getName()) return false;
    return true;
}