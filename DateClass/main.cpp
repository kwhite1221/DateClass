#include <iostream>
#include "Date.h"

int main() {
	std::cout << "=== Date Class Test ===";

	std::cout << "Test 1: Normal date construction (12/25/2021)\n";
	Date d1(12, 25, 2021);
	std::cout << "Numeric: " << d1.formatNumeric() << "\n";
	std::cout << "Month Day Year: " << d1.formatMonthDayYear() << "\n";
	std::cout << "Day Month Year: " << d1.formatDayMonthYear() << "\n\n";

	std::cout << "Test 2: Leap year and boundary handling\n";
	Date d2(2, 29, 2024); // 2024 is a leap year
	std::cout << "2024 Leap Year check (object): " << (d2.isLeapYear() ? "True" : "False") << "\n";
	std::cout << "2023 Leap Year check (overload): " << (d2.isLeapYear(2023) ? "True" : "False") << "\n";
	std::cout << "Last day of Feb 2023: " << d2.lastDay(2, 2023) << "\n";
	std::cout << "Last day of Feb 2024: " << d2.lastDay(2, 2024) << "\n\n";

	std::cout << "Test 3: Invalid month input (13/10/2022)\n";
	Date d3(13, 10, 2022);
	std::cout << "Resulting Date (Expected 1/1/1900): " << d3.formatNumeric() << "\n\n";

	std::cout << "Test 4: Invalid day for April (4/31/2023)\n";
	Date d4(4, 31, 2023);
	std::cout << "Resulting Date (Expected 1/1/1900): " << d4.formatNumeric() << "\n\n";

	std::cout << "Test 5: Invalid leap day in non-leap year (2/29/2023)\n";
	Date d5(2, 29, 2023);
	std::cout << "Resulting Date (Expected 1/1/1900): " << d5.formatNumeric() << "\n\n";

	std::cout << "Test 6: Mutator setDate() with upper boundary (12/31/2025)\n";
	Date d6;
	d6.setDate(12, 31, 2025);
	std::cout << "Numeric: " << d6.formatNumeric() << "\n";
	std::cout << "Formatted: " << d6.formatMonthDayYear() << "\n";

	return 0;
}