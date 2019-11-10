//
// Created by maruba on 14/10/19.
//

#include "../Header/Local.h"

#include <utility>



/**
 * @brief default constructor
 */
Local::Local() {
    name = "";
    x = 0;
    y = 0;
}

/**
 * @brief local constructor
 * @param Name - name of the place
 * @param X - x coordinates
 * @param Y -y coordinates
 */
Local::Local(string  Name, double X, double Y): name(Name), x(X), y(Y) {};

/**
 * @return it returns the x coordinates
 */
double Local::get_Coordx()const {
    return x;
}
/**
 *
 * @return it returns the y coordinates
 */

double Local::get_Coordy()const {
    return y;
}
/**
 *
 * @return it returns the name of the location
 */

string Local::getName()const {
    return name;
}
