#include "Function_table.h" // genFunctionTable, printFunctionTable, integerWidth

using std::string;		using std::cout;
using std::vector;		using std::cin;
using std::streamsize;	using std::endl;
using std::max;

Function_table genFunctionTable(long long& start, long long& end, long long& step) {
	Function_table out;
	out.numPoints = 0;
	out.xMaxDigits = 1;
	out.yMaxDigits = 1;
	for (long long i = start; i <= end; i += step) {
		long long x = i;
		long long y = i * i;
		string::size_type xDigits = integerWidth(x);
		string::size_type yDigits = integerWidth(y);
		if (xDigits > out.xMaxDigits)
			out.xMaxDigits = xDigits;
		if (yDigits > out.yMaxDigits)
			out.yMaxDigits = yDigits;
		Ordered_pair pair;
		pair.x = x;;
		pair.y = y;
		out.points.push_back(pair);
		out.numPoints++;
	}
	return out;
}

void printFunctionTable(Function_table& fTable, string& xTitle, string& yTitle) {
	string::size_type xColWidth = xTitle.size() + 3;
	string::size_type yColWidth = yTitle.size() + 1;
	if (fTable.xMaxDigits > xTitle.size())
		xColWidth = fTable.xMaxDigits + 2;
	if (fTable.xMaxDigits > yTitle.size())
		yColWidth = fTable.yMaxDigits + 1;
	cout << string(xColWidth - xTitle.size() - 1, ' ') << xTitle << " | ";
	cout << string(yColWidth - yTitle.size() - 1, ' ') << yTitle << endl;
	for (int i = 0; i != fTable.numPoints; ++i) {
		if (i % 5 == 0) {
			cout << string(xColWidth, '-') << "|";
			cout << string(yColWidth, '-') << endl;
		}
		string::size_type xDigits = integerWidth(fTable.points[i].x);
		string::size_type yDigits = integerWidth(fTable.points[i].y);
		cout << string(xColWidth - 1 - xDigits, ' ');
		cout << fTable.points[i].x;
		cout << " | ";
		cout << string(yColWidth - 1 - yDigits, ' ');
		cout << fTable.points[i].y;
		cout << endl;
	}
}

string::size_type integerWidth(long long x) {
	string::size_type width = (x >= 0 ? 1 : 2);
	// invariant: we have counted 'width' digits from the right)
	while (x / 10 != 0) {
		width++;
		x = x / 10;
	}		
	return width;
}