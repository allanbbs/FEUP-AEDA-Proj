//
// Created by maruba on 17/10/19.
//

#ifndef AEDA_PROJ1_ERRORS_H
#define AEDA_PROJ1_ERRORS_H


class NoClient {
private:
    unsigned int nif;
public:
    NoClient(const unsigned int& Nif);
    unsigned int getNif();
};


#endif //AEDA_PROJ1_ERRORS_H
