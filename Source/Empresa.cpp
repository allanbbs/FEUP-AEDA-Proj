//
// Created by maruba on 14/10/19.
//

#include "../Header/Empresa.h"
#include <fstream>
void headerServInfor();

size_t Empresa::nCam = 0;
size_t Empresa::nCli = 0;
size_t Empresa::nSer = 0;

void Empresa::gravaCli() {
    ifstream file("../AEDA_Proj1/Ficheiros/clientes");
    string name;
    string aux;
    unsigned int nif;
    while(!file.eof()){
        getline(file, name);    //get name
        getline(file, aux);     //get string nif
        istringstream is(aux);        //get unsigned int nif
        is >> nif;
        addClientes(name,nif);      //add client
    }
}

void Empresa::gravaSer(Empresa &e, const int& month) {
    string fileName = "../AEDA_Proj1/Ficheiros/servicos"+to_string(month)+".txt"; 
    ifstream file(fileName.c_str());
    string local, aux, type;
    int aux_int, carga;
    double cordx, cordy;
    unsigned int cliNif;
    vector<int> trucks;

    //if the file does not exists, create one
    if (file.fail()) {
        ofstream create(fileName.c_str());
        create.close();
    }
    else {
        while (!file.eof()) {
            //get the first e local (the departure)
            getline(file, aux);
            getline(file, local);
            getline(file, aux);
            istringstream is(aux);
            is >> cordx;
            getline(file, aux);
            is.clear();
            is.str(aux);
            is >> cordy;
            Local *l1 = new Local(local, cordx, cordy);
            //get the second local (the arrival)
            getline(file, local);
            getline(file, aux);
            is.clear();
            is.str(aux);
            is >> cordx;
            getline(file, aux);
            is.clear();
            is.str(aux);
            is >> cordy;
            Local *l2 = new Local(local, cordx, cordy);
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
            Servicos *s = addServico(*l1, *l2, type, cliNif, carga);
            getline(file, aux);
            is.clear();
            is.str(aux);
            while (!is.eof() && aux != "0") {
                is >> aux_int;
                this->addCamiaoId_Servico(aux_int, s);
            }
        }
    }
}

void Empresa::gravaCam() {
    fstream file("../AEDA_Proj1/Ficheiros/camioes");
    unsigned int carga;
    double auxDouble;
    int auxInt;
    string type;
    string auxString;
    while(!file.eof()){
        getline(file, auxString); //get first line

        getline(file, auxString); //get cargaMax
        istringstream is(auxString);
        is >> carga;

        getline(file, type);        //get the type
        getline(file,auxString);    //get the special atribute
        is.clear();
        is.str(auxString);
        if (type == "Animal") {
            is >> auxInt;
            Animals * c = new Animals(carga, auxInt, ++nCam);
            cam.push_back(c);
        }
        else if(type == "Congelado") {
            is >> auxDouble;
            Congelado* c = new Congelado(carga, auxDouble, ++nCam);
            cam.push_back(c);
        }
        else if(type == "Perigoso"){
            is >> auxInt;
            Perigoso* c = new Perigoso(carga, auxInt, ++nCam);
            cam.push_back(c);
        }
        else{
            is >> auxInt;
            Base *c = new Base(carga, ++nCam);
            cam.push_back(c);
        }
    }
}

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
    if (pos != -1) throw RepeatedClient(name);
    auto c = new Clientes(name, nif);
    nCli++;
    cli.push_back(c);
}


Servicos* Empresa::addServico(const Local &Partida, const Local &Destino, const string &Tipo,
                         const unsigned int cliNif, const int& carga){
    long int pos = SearchCli(cliNif);
    if (pos == -1) throw NoClient(to_string(cliNif));
    Servicos *new_Service = new Servicos(Partida, Destino, ++nSer, Tipo, carga);
    ser.push_back(new_Service);
    (cli[pos])->addService(new_Service);
    return new_Service;
}
//podemos usar pesquisa binaria
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
    cout    <<  fixed   <<  setprecision(2);
    cout    <<  "Total profit of the month: " << this->getLucro_mes() << endl;
}

void Empresa::display_CamiaoProfit(){
    headerCamInfor();
    cout << left        << setw(10)     << getLucro_camiaoMes("Base")
         << setw(10)    << getLucro_camiaoMes("Congelado")
         << setw(10)    << getLucro_camiaoMes("Perigoso")
         << getLucro_camiaoMes("Animals") << endl;

}

void Empresa::display_clientesInfo(const unsigned int &nif) {
    ostringstream os;
    unsigned int n = 20;
    os<<fixed<<setprecision(2);
    if (nif) {
        long int pos = SearchCli(nif);
        if (pos == -1)
            throw NoClient(to_string(nif));

        os << left << setw(30) << "NAME" << setw(20) << "NIF" << setw(20) << "PROFIT" << "SERVICES" << endl;
        os << "=========================================================="
            "======================================="<< endl;
        os << *cli[pos];
    } else {
        vector<Clientes *> c(cli);
        sort(c.begin(), c.end(), Compare_clientes);
        os << left << setw(30) << "NAME" << setw(20) << "NIF" << setw(20) << "PROFIT" << "SERVICES" << endl;
        os << "=========================================================="
            "======================================="<< endl;
        for (auto it =  c.begin(); it < c.end(); it++) {
            os << *(*it);
            n--;
            if (n == 0) return;
        }
    }
    cout << os.str();
}

void Empresa::display_servicoStatus(const unsigned int &id) const{
    ostringstream os;
    unsigned int n = 20;
    os<<fixed<<setprecision(2);

    if (id) {
        size_t pos = SearchSer(id);
        os << *ser[pos];
    } else {
        vector<Servicos *> s(ser);
        sort(s.begin(), s.end(), Compare_servico);
        for (auto it = s.begin(); it != s.end(); it++) {
            os << **it;
            n--;
            if (n == 0) return;

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
            "=========="<< endl;

}

void headerCamInfor() {
    cout << left << setw(10) << "BASE"
         << setw(10) << "FROZEN"
         << setw(10) << "DANGEROUS"
         << "ANIMALS" << endl;
    cout << "=========================================================="
            "=========================================================="
            "=========="<< endl;

}

void Empresa::addCamiao(const int &type, const unsigned int &cargaMax, const double &caract) {
    map<unsigned int,string> temp = { {0,"Base"},{1,"Congelado"},{2,"Perigoso"},{3,"Animal"}};
    string sType = temp[type];
    unsigned int id = ++nCam;
    if (sType == "Base") {
        Camiao *c = new Base(cargaMax, id);
        cam.push_back(c);
    }
    else if (sType == "Congelado") {
        Camiao *c = new Congelado(cargaMax, caract, id);
        cam.push_back(c);
    }
    else if (sType == "Perigoso") {
        Camiao *c = new Perigoso(cargaMax, caract, id);
        cam.push_back(c);
    }
    else if (sType == "Animal") {
        Camiao *c = new Animals(cargaMax, caract, id);
        cam.push_back(c);
    }

}

//nao estamos checando se o camiao existe
void Empresa::addCamiaoId_Servico(const int& id, Servicos* s) {
    for (auto it = cam.begin(); it != cam.end(); it++){
        if ((*it)->getId() == id)
            s->addCamiao((*it));

    }
}


double Empresa::getLucro_camiaoMes(const string& type) const{
    double lucro = 0;
    for (auto const &it : cam){
        if (it->getType() == type)
            lucro+= it->getProfit();
    }
    return lucro;
}

//supostamente tinhamos de chegar o nivel de perigo e da temperatura
//por outro lado, talvez o perigo e temperatura influencie apenas no preço
bool Empresa::allocateCamiao(Servicos * s) {
    vector<Camiao *> cam_copy(cam);
    int carga = s->get_carga();
    sort(cam_copy.begin(), cam_copy.end(), Compare);
    //quickSort(cam_copy, 0, cam_copy.size());
    for (const auto & x: cam_copy){
        if (x->getType() == s->get_tipo()){
            carga -= x->getCargaMax();
            s->addCamiao(x);
        }
        if (carga<0)
            break;
    }
    return carga <= 0;

}


