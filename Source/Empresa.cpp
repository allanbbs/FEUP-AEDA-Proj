//
// Created by maruba on 14/10/19.
//

#include "../Header/Empresa.h"
#include <fstream>

void headerServInfor();
bool novo;
size_t Empresa::nCam = 0;
size_t Empresa::nCli = 0;
size_t Empresa::nSer = 0;


void Empresa::gravaCli() {
    ifstream file("../AEDA_Proj1/Ficheiros/clientes");
    string name;                        //stores the name of the client       
    string aux;                         //auxiliar variable to read lines 
    unsigned int nif;
    while (!file.eof()) {
        getline(file, name);            //get name
        getline(file, aux);             //get string nif
        istringstream is(aux);          //get unsigned int nif
        is >> nif;
        addClientes(name, nif);         //add client
    }
}

void Empresa::gravaSer(Empresa &e, const int &month) {
    string fileName = "../AEDA_Proj1/Ficheiros/servicos" + to_string(month) + ".txt";
    ifstream file(fileName.c_str());
    string local, aux, type;
    int aux_int, carga;
    double cordx, cordy;
    unsigned int cliNif;
    vector<int> trucks;

    if (!file.fail())
        while (!file.eof()) {
            getline(file, aux);                             //get empty line 

            //get the first local (the departure)
            getline(file, local);                           //get the local of departure
            getline(file, aux);                             //get the first coordinate
            istringstream is(aux);
            is >> cordx;
            
            getline(file, aux);                             //get the second coordinate
            is.clear();
            is.str(aux);
            is >> cordy;
            Local *l1 = new Local(local, cordx, cordy);     //crete the local class for departure
            
            //get the second local (the arrival)
            getline(file, local);                           //get the local of arrival
            getline(file, aux);                             //get the first coordinate
            is.clear();
            is.str(aux);
            is >> cordx;
            
            getline(file, aux);                             //get the second coordinate
            is.clear();
            is.str(aux);
            is >> cordy;
            Local *l2 = new Local(local, cordx, cordy);     //create the local class for arrival
            
            //get the type of service
            getline(file, type);

            //get the client nif
            getline(file, aux);
            is.clear();
            is.str(aux);
            is >> cliNif;

            //get the carga
            getline(file, aux);
            is.clear();
            is.str(aux);
            is >> carga;

            Servicos *s = new Servicos(*l1, *l2, ++Empresa::nSer, type, carga);
            
            //get camioes id
            getline(file, aux);
            is.clear();
            is.str(aux);
            while (!is.eof() && aux != "0") {
                is >> aux_int;
                this->addCamiaoId_Servico(aux_int, s);
            }

            e.addServico(s, cliNif);                        //associate the service to a client
        }
    else novo = true;                                       //if there's nothing to read, it means that this is a new file
}


void Empresa::gravaCam() {
    fstream file("../AEDA_Proj1/Ficheiros/camioes");
    unsigned int carga;
    double auxDouble;
    int auxInt;
    string type;
    string auxString;
    while (!file.eof()) {
        getline(file, auxString); //get first line

        getline(file, auxString); //get cargaMax
        istringstream is(auxString);
        is >> carga;

        getline(file, type);        //get the type
        getline(file, auxString);    //get the special atribute
        is.clear();
        is.str(auxString);
        if (type == "Animal") {
            is >> auxInt;
            Animals *c = new Animals(carga, auxInt, ++nCam);
            cam.push_back(c);
        } else if (type == "Congelado") {
            is >> auxDouble;
            Congelado *c = new Congelado(carga, auxDouble, ++nCam);
            cam.push_back(c);
        } else if (type == "Perigoso") {
            is >> auxInt;
            Perigoso *c = new Perigoso(carga, auxInt, ++nCam);
            cam.push_back(c);
        } else {
            is >> auxInt;
            Base *c = new Base(carga, ++nCam);
            cam.push_back(c);
        }
    }
}

Empresa::Empresa() {}

//algum erro aqui
Empresa::~Empresa() {
    for (int i = nCam-1; i >= 0; i--) delete cli[i];              //cleaning the vector
    for (int i = nCli-1; i >= 0; i--) delete cam[i];
    for (int i = nSer-1; i >= 0; i--) delete ser[i];
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
    if (pos != -1) throw RepeatedClient(name);
    auto c = new Clientes(name, nif);
    nCli++;
    cli.push_back(c);
}

Servicos *Empresa::addServico(Servicos* s, const unsigned int cliNif) {
    long int pos = SearchCli(cliNif);
    if (pos == -1) throw NoClient(to_string(cliNif));
    ser.push_back(s);
    (cli[pos])->addService(s);
    return s;
}

//podemos usar pesquisa binaria
long int Empresa::SearchCli(const unsigned int &nif) const {
    for (int i = 0; i < cli.size(); i++) {
        if (cli[i]->get_nif() == nif) return i;
    }
    return -1;
}

size_t Empresa::SearchSer(const unsigned int &id) const {
    for (int i = 0; i < ser.size(); i++) {
        if (ser[i]->get_id() == id) return i;
    }
    throw NoService(to_string(id));
}

void Empresa::display_lucro_mes() {
    cout << fixed << setprecision(2);
    cout << "Total profit of the month: " << this->getLucro_mes() << endl;
}

void Empresa::display_CamiaoProfit() {
    headerCamInfor();
    cout << left << setw(10) << getLucro_camiaoMes("Base")
         << setw(10) << getLucro_camiaoMes("Congelado")
         << setw(10) << getLucro_camiaoMes("Perigoso")
         << getLucro_camiaoMes("Animals") << endl;

}

void Empresa::display_clientesInfo(const unsigned int &nif) {
    ostringstream os;
    unsigned int n = 20;
    os << fixed << setprecision(2);
    if (nif) {
        long int pos = SearchCli(nif);
        if (pos == -1)
            throw NoClient(to_string(nif));

        os << left << setw(30) << "NAME" << setw(20) << "NIF" << setw(20) << "PROFIT" << "SERVICES" << endl;
        os << "=========================================================="
              "=======================================" << endl;
        os << *cli[pos];
    } else {
        vector<Clientes *> c(cli);
        sort(c.begin(), c.end(), Compare_clientes);
        os << left << setw(30) << "NAME" << setw(20) << "NIF" << setw(20) << "PROFIT" << "SERVICES" << endl;
        os << "=========================================================="
              "=======================================" << endl;
        for (auto it = c.begin(); it < c.end(); it++) {
            os << *(*it);
            n--;
            if (n == 0) return;
        }
    }
    cout << os.str();
}

void Empresa::display_servicoStatus(const unsigned int &id, long int n, bool (*f)(const Servicos*, const Servicos*), const string& type) const {
    ostringstream os;
    os << fixed << setprecision(2);

    if (id) {
        size_t pos = SearchSer(id);
        os << *ser[pos];
    } else {
        vector<Servicos *> s(ser);
        sort(s.begin(), s.end(), f);
        if (type.empty()) {
            for (auto & it : s) {
                os << *it;
                n--;
                if (n == 0) break;
            }
        }
        else{
            for (auto & it : s) {
                if (it->get_tipo() == type){
                    os << *it;
                    n--;
                }
                if (n == 0) break;
            }
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
         << setw(10) << "PRECO"
         << "CARGA" << endl;
    cout << "=========================================================="
            "=========================================================="
            "==========" << endl;

}

void headerCamInfor() {
    cout << left << setw(10) << "BASE"
         << setw(10) << "FROZEN"
         << setw(10) << "DANGEROUS"
         << "ANIMALS" << endl;
    cout << "=========================================================="
            "=================================" << endl;

}

void Empresa::addCamiao(const int &type, const unsigned int &cargaMax, const double &caract) {
    map<unsigned int, string> temp = {{0, "Base"},
                                      {1, "Congelado"},
                                      {2, "Perigoso"},
                                      {3, "Animal"}};
    string sType = temp[type];
    unsigned int id = ++nCam;
    if (sType == "Base") {
        Camiao *c = new Base(cargaMax, id);
        cam.push_back(c);
    } else if (sType == "Congelado") {
        Camiao *c = new Congelado(cargaMax, caract, id);
        cam.push_back(c);
    } else if (sType == "Perigoso") {
        Camiao *c = new Perigoso(cargaMax, caract, id);
        cam.push_back(c);
    } else if (sType == "Animal") {
        Camiao *c = new Animals(cargaMax, caract, id);
        cam.push_back(c);
    }

}

//nao estamos checando se o camiao existe e nao precisa
void Empresa::addCamiaoId_Servico(const int &id, Servicos *s) {
    for (auto it = cam.begin(); it != cam.end(); it++) {
        if ((*it)->getId() == id)
            s->addCamiao((*it));

    }
}

double Empresa::getLucro_camiaoMes(const string &type) const {
    double lucro = 0;
    for (auto const &it : cam) {
        if (it->getType() == type)
            lucro += it->getProfit();
    }
    return lucro;
}

bool Empresa::allocateCamiao(Servicos *s) {
    vector<Camiao *> cam_copy(cam);
    int carga = s->get_carga();
    sort(cam_copy.begin(), cam_copy.end(), Compare);
    for (const auto &x: cam_copy) {
        if (x->getType() == s->get_tipo()) {
            carga -= x->getCargaMax();
            s->addCamiao(x);
        }
        if (carga <= 0)
            break;
    }
    return carga <= 0;

}


