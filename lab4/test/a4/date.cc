#include <ctime> // time and localtime
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Date::Date()
{
	time_t timer = time(0);			 // time in seconds since 1970-01-01
	tm *locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d)
{

	if ((y < 10000 && y > 999 && m > 0 && m < 13 && d <= Date::daysPerMonth[m - 1] && d > 0))
	{
		year = y;
		month = m;
		day = d;
	}
	else
	{
		cout << "invalid date, object was not created" << endl;
	}
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::next()
{
	day++;
	if(day > daysPerMonth[month-1]){
		day = 1;
		month++;
		if(month > 12){
			month = 1;
			year++;
		}
	}

}

std::istream& operator>>(std::istream &is, Date &dt){
	string s;
	is >> s;

	std::regex b("(?:[0-9]{2})?[0-9]{2}\\-(1[0-2]|0?[1-9])\\-(3[01]|[12][0-9]|0?[1-9])");
	bool okInput = std::regex_match(s, b);

	if (okInput && dt.day <= Date::daysPerMonth[dt.month - 1])
	{
		dt.year = std::stoi(s.substr(0, 4));
		dt.month = std::stoi(s.substr(5, 2));
		dt.day = std::stoi(s.substr(8, 2));
	}
	else
	{
		is.setstate(std::ios_base::failbit);
	}

	return is;
}

std::ostream& operator<<(std::ostream &os, Date &dt)
{
	string day = std::to_string(dt.day);
	string month = std::to_string(dt.month);
	if (dt.day < 10)
	{
		day = "0" + std::to_string(dt.day);
	}
	if (dt.month < 10)
	{
		month = "0" + std::to_string(dt.month);
	}
	os << dt.year << "-" << month << "-" << day;
	return os;
}