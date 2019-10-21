//
// Created by maruba on 14/10/19.
//

#include "../Header/Empresa.h"

void headerServInfor();

size_t Empresa::nCam = 0;
size_t Empresa::nCli = 0;
size_t Empresa::nSer = 0;

Empresa::Empresa() {}

Empresa::~Empresa() {
    for (int i = 0; i < nCam; i++) delete cli[i];              //cleaning the vector
    for (int i = 0; i < nCli; i++) delete cam[i];
    for (int i = 0; i < nSer; i++) delete ser[i];
    cli.clear();                                                            //deleting the vector allocation
    cam.clear();
    ser.clear();
}

double Empresa::getLucro_mes() const {
    double lucro = 0;
    for (auto it = cli.begin(); it < cli.end(); it++)
        lucro += (*it)->get_profit();
    return lucro;
}

void Empresa::addClientes(const string &name, const unsigned int &nif) {
    long int pos = SearchCli(nif);
    if (pos != -1)
        throw ClientRepeated(to_string(nif));
    auto c = new Clientes(name, nif);
    nCli++;
    cli.push_back(c);
}


void Empresa::addServico(const Local &Partida, const Local &Destino, const string &Tipo,
                         const unsigned int cliNif){
    long int pos = SearchCli(cliNif);
    if (pos == -1)
        throw NoClient(to_string(cliNif));

    Servicos *new_Service = new Servicos(Partida, Destino, ++nSer, Tipo);

    ser.push_back(new_Service);
    (cli[pos])->addService(new_Service);
}

long int Empresa::SearchCli(const unsigned int &nif) const{
    for (int i = 0; i< cli.size(); i++){
        if (cli[i]->get_nif() == nif) return i;
    }
    return -1;
}

size_t Empresa::SearchSer(const unsigned int &id)const {
    for (int i = 0; i < ser.size(); i++){
        if (ser[i]->get_id() == id) return i;
    }
    throw NoService(to_string(id));
}

void Empresa::display_lucro_mes() {
    cout<<fixed<<setprecision(2);
    cout << "Total profit of the month: " << this->getLucro_mes() << endl;
}

void Empresa::display_clientesInfo(const unsigned int &n, const unsigned int &nif) {
    ostringstream os;
    os<<fixed<<setprecision(2);
    if (nif) {
        long int pos = SearchCli(nif);
        if (pos == -1)
            throw NoClient(to_string(nif));

        os << left << setw(30) << "NAME" << setw(20) << "NIF" << "SERVICES" << endl;
        os << *cli[pos];
    } else {
        os << left << setw(30) << "NAME" << setw(20) << "NIF" << "SERVICES" << endl;
        for (auto it = cli.begin(); it < cli.end(); it++) {
            os << (*it);
        }
    }
    cout << os.str();
}

void Empresa::display_servicoStatus(const unsigned int &n, const unsigned int &id) const{
    ostringstream os;
    os<<fixed<<setprecision(2);
    if (id) {
        size_t pos = SearchSer(id);
        os << *ser[pos];
    } else {
        for (auto it = ser.begin(); it < ser.end(); it++) {
            os << (*it);
        }
    }
    headerServInfor();
    cout << os.str();
}

void headerServInfor() {
    cout << left << setw(10) << "ID"
         << setw(15) << "TIPO"
         << setw(10) << "TEMPO"
         << setw(30) << "PARTIDA"
         << setw(30) << "CHEGADA"
         << setw(15) << "N CAMIOES"
         << setw(10) << "PRECO" << endl;

}
