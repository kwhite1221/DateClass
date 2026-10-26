#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
	int month;
	int day;
	int year;

	bool checkLeapYear(int y) const;

public:
	Date(int m = 1, int d = 1, int y = 1900);

	void setDate(int m, int d, int y);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

	bool isLeapYear() const;

	bool isLeapYear(int year) const;

	int lastDay() const;

	int lastDay(int month, int year) const;

	std::string formatNumeric() const;
	std::string formatMonthDayYear() const;
	std::string formatDayMonthYear() const;

};

#endif

