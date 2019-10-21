#ifndef AEDA_PROJ1_ERRORS_H
#define AEDA_PROJ1_ERRORS_H

/**
 * Error case the client doens't exist
 */
class NoClient {
private:
    unsigned int nif;   /**<identification of the client*/
public:
    NoClient(const unsigned int& Nif);  /**<Constructor*/
    unsigned int getNif() const;
};

/**
 * Error case the service doesn't exist
 */
class NoService{
private:
    unsigned int id;
public:
    NoService(const unsigned int& Id);
    unsigned int getId() const;
};
/**
 * Error case the client already exists
 */
class ClientRepeated{
private:
    unsigned int nif;
public:
    ClientRepeated(const unsigned int& Nif);
    unsigned int getNif() const;

};
#endif //AEDA_PROJ1_ERRORS_H
