//
// Created by Amanda  on 2019-10-14.
//

#ifndef AEDA_01_CLIENTES_H
#define AEDA_01_CLIENTES_H


class Clientes {
private:
    string name;
    unsigned int nif;
    vector <Servicos*> ser;
public:
    Clientes();
    Clientes(string n,unsigned int anif);
    ~Clientes();
    float cal_lucro();
    unsigned int get_nif(); (
    void addService(Servico &servico);
    friend ostream & operator <<(ostream& out, Clientes client);

};


#endif //AEDA_01_CLIENTES_H
