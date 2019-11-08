//
// Created by maruba on 06/11/19.
//

#ifndef AEDA_PROJ1_UTILS_H
#define AEDA_PROJ1_UTILS_H
#include "Empresa.h"


int checkOption(int min, int max);      //checks if it's a valid option
int validServiceId(Empresa &e);         //checks if it's a valid service id
int validClientNif(Empresa &e);
double checkNumber();
void wait();
#include <cstdlib>
void clear_screen();

#endif //AEDA_PROJ1_UTILS_H
