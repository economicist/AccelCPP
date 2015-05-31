#ifndef GUARD_Function_table
#define GUARD_Function_table

#include <algorithm>		// std::max
#include <iostream>			// std::cout, std::cin, std::endl
#include <ios>				// std::streamsize
#include <string>			// std::string
#include <vector>			// std::vector

struct Ordered_pair {
	long long x, y;
};

struct Function_table {
	std::vector<Ordered_pair> points;
	int numPoints;
	std::string::size_type xMaxDigits;
	std::string::size_type yMaxDigits;
};

Function_table genFunctionTable(long long&, long long&, long long&);
void printFunctionTable(Function_table&, std::string&, std::string&);
std::string::size_type integerWidth(long long);
bool fgrade(const Student_info& s);

#endif