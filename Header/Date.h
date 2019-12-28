//
// Created by Amanda  on 25/12/19.
//

#ifndef AEDA_PROJ1_DATE_H
#define AEDA_PROJ1_DATE_H

#include <vector>
#include <iostream>
#include <string>

class Date {
public:

//CONTRUCTORS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Date();   // set the current time
    Date(unsigned int year, unsigned int month, unsigned int day);  //constructor given the parameters
    Date(std::string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"

//SET+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void setYear(unsigned int year);

    void setMonth(unsigned int month);

    void setDay(unsigned int day);

    void setDate(unsigned int year, unsigned int month, unsigned int day);

    void setDate();

    void setDate(std::string date);

//GET+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    unsigned int getYear() const;

    unsigned int getMonth() const;

    unsigned int getDay() const;

    std::string getDate() const; // returns the Date in format "yyyy/mm/dd"
    static std::string currentDate(){
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);

        return buf;
    };// get the current Date

//OTHERS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void show() const; // shows the Date on the screen in format "yyyy/mm/dd"
    bool isValid();  // return if this is a valid day
    bool isEqualTo(const Date &date);

    bool isAfter(const Date &date); //checks if a Date is after another
    bool isBefore(const Date &date); //checks if a Date is before another



private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool bissexto(int ano); //Descobre se o ano eh bissexto
    int daysInMonth(int ano, int mes);  //returns the number of days in a specific month of a specif year
    int checkDay(); //this function checks if it's a valid day for a specific month
    int checkMonth(); //this function checks if it's a valid month (between 1 and 12 inclusive)
};


#endif //AEDA_PROJ1_DATE_H
