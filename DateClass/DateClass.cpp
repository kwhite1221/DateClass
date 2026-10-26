#include "Date.h"
#include <sstream>
#include <iomanip>

bool Date::checkLeapYear(int y) const {
	if (y % 400 == 0) return true;
	if (y % 100 == 0) return false;
	if (y % 4 == 0) return true;
	return false;
}

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
	if (y < 1) {
		month = 1;
		day = 1;
		year = 1900;
		return;
	}

	if (m < 1 || m > 12) {
		month = 1;
		day = 1;
		year = 1900;
		return;
	}

	if (d < 1 || d > lastDay(m, y)) {
		month = 1;
		day = 1;
		year = 1900;
		return;
	}

	year = y;
	month = m;
	day = d;
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

bool Date::isLeapYear() const {
	return checkLeapYear(year);
}

bool Date::isLeapYear(int y) const {
	return checkLeapYear(y);
}

int Date::lastDay() const {
	return lastDay(month, year);
}

int Date::lastDay(int m, int y) const {
	switch (m) {
	case 2:
		return checkLeapYear(y) ? 29 : 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

std::string Date::formatNumeric() const {
	std::ostringstream oss;
	oss << month << "/" << day << "/" << year;
	return oss.str();
}

std::string Date::formatMonthDayYear() const {
	const std::string months[] = {
		"", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	std::ostringstream oss;
	oss << months[month] << " " << day << ", " << year;
	return oss.str();
}

std::string Date::formatDayMonthYear() const {
	const std::string months[] = {
		"", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "october", "November", "December"
	};
	std::ostringstream oss;
	oss << day << " " << months[month] << " " << year;
	return oss.str();
}
