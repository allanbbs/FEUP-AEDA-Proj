//
// Created by julia on 26/12/2019.
//

#ifndef AEDA_PROJ1_DATE_H
#define AEDA_PROJ1_DATE_H


#include <iostream>
#include <string>
#include <ctime>

class Date {
public:

    /**
     * @brief Default constructor for Date
     */
    Date();   // set the current time
    /**
     * @brief Constructor for date considering separated members as parameters
     * @param year Year
     * @param month Month
     * @param day Day
     */
    Date(unsigned int year, unsigned int month, unsigned int day);
    /**
     * @brief Constructor given the date as a string
     * @param yearMonthDay Date. Must be in format yyyy/mm/dd
     */
    Date(std::string yearMonthDay);

    /**
     * @brief Set the year
     * @param year
     */
    void setYear(unsigned int year);

    /**
     * @brief Set the hole date
     * @param date Date in the format yyyy/mm/dd
     */
    void setDate(std::string date);

    /**
     * @brief Get the year
     * @return Return the year
     */
    unsigned int getYear() const;

    std::string getDate() const; // returns the date in format "yyyy/mm/dd"

    //OTHERS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /**
     * @brief checks if date is after this date
     * @param date Date to be compared
     * @return true if is after, false otherwise
     */
    bool isAfter(const Date &date);
    bool isBefore(const Date &date); //checks if a date is before another


private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool bissexto(int ano); //Descobre se o ano eh bissexto
    int daysInMonth(int ano, int mes);  //returns the number of days in a specific month of a specif year
};
/**
 * @brief Gets today's day, month and year
 * @return Return the information as a Date
 */
std::string getTimeNow();
#endif //AEDA_PROJ1_DATE_H
