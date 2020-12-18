#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <regex> 
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	void next();               // advance to next day
	friend std::istream& operator>> (std::istream& is, Date& dt);
	friend std::ostream& operator<< (std::ostream& os, Date& dt);
    
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
	bool validate(int y, int m, int d);
};

#endif