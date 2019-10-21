#ifndef AEDA_PROJ1_ERRORS_H
#define AEDA_PROJ1_ERRORS_H

#include <string>
/**
 * @brief Class made to throw types of errors
 */
class Error{
protected:
    std::string info;   /**<string containing the cause of the error*/
public:
    Error(std::string Info): info(Info) { };
    std::string getInfo() const {return info;};
};
/**
 * Error case the client doens't exist
 */

class NoClient: Error {
public:
    NoClient(const std::string & nif): Error(nif) {}
};

/**
 * Error case the service doesn't exist
 */
class NoService: Error{
public:
    NoService(const std::string &id): Error(id){ }
};
/**
 * Error case the client already exists
 */
class ClientRepeated: Error{
public:
    ClientRepeated(const std::string &id): Error(id){ }
};
#endif //AEDA_PROJ1_ERRORS_H

class WrongInput_option: Error{
public:
    WrongInput_option(const string &input): Error(input){ }
};