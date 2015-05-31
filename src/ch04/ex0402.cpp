#include <iostream>			// std::cout, std::cin, std::endl;
#include "Function_table.h"	// genFunctionTable, printFunctionTable

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	cout << "f(x) = x^2" << endl;

	// Get bounds and step size for our table
	long long first, last, step;
	cout << "Starting integer: ";
	cin >> first;
	cout << "Ending integer: ";
	cin >> last;
	cout << "Step size: ";
	cin >> step;

	// generate a "table" of integers (long long for maximum capacity)
	// and the squares of those integers
	Function_table xSquared = genFunctionTable(first, last, step);
	
	// print the table
	string xTitle = "x";
	string yTitle = "x^2";
	printFunctionTable(xSquared, xTitle, yTitle);
}