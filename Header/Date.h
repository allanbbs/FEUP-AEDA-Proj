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
     * @brief Set the month
     * @param month
     */
    void setMonth(unsigned int month);
    /**
     * @brief set the day
     * @param day
     */
    void setDay(unsigned int day);
    /**
     * @brief Set the hole date given the parameters
     * @param year
     * @param month
     * @param day
     */
    void setDate(unsigned int year, unsigned int month, unsigned int day);

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
    /**
     * @brief Get the month
     * @return Return the Month
     */
    unsigned int getMonth() const;

    unsigned int getDay() const;
    std::string getDate() const; // returns the date in format "yyyy/mm/dd"

    //OTHERS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"
    bool isValid();  // return if this is a valid day
    bool isEqualTo(const Date &date);
    bool isAfter(const Date &date); //checks if a date is after another
    bool isBefore(const Date &date); //checks if a date is before another


private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool bissexto(int ano); //Descobre se o ano eh bissexto
    int daysInMonth(int ano, int mes);  //returns the number of days in a specific month of a specif year
    int checkDay(); //this function checks if it's a valid day for a specific month
    int checkMonth(); //this function checks if it's a valid month (between 1 and 12 inclusive)
};
/**
 * @brief Gets today's day, month and year
 * @return Return the information as a Date
 */
Date getTimeNow();
#endif //AEDA_PROJ1_DATE_H
