#include <algorithm>	// contains 'sort(b, e)'
#include <iomanip>		// contains 'setprecision(n)'
#include <ios>			// contains 'streamsize' data type
#include <iostream>
#include <vector>

using std::cout;			using std::vector;
using std::cin;				using std::sort;
using std::endl;

int main() {
	// create an input variable and a vector to hold them in
	double x;
	vector<double> values;

	// take values in with 'x' and store them in the vector 'values'
	cout << "Enter a list of values, ending with 'stop': " << endl;
	while (cin >> x) {
		values.push_back(x);
	}

	typedef vector<double>::size_type vec_sz;
	vec_sz length = values.size();
	vec_sz mid = length / 2;
	vec_sz q1 = length / 4;
	vec_sz q3 = 3 * length / 4;

	// sort values
	sort(values.begin(), values.end());

	// print first quartile
	cout << "First quartile: " << endl;
	for (vec_sz i = 0; i != q1; ++i)
		cout << values[i] << endl;
	cout << endl;

	// print second quartile
	cout << "Second quartile: " << endl;
	for (vec_sz i = q1; i != mid; ++i)
		cout << values[i] << endl;
	cout << endl;

	// print third quartile
	cout << "Third quartile: " << endl;
	for (vec_sz i = mid; i != q3; ++i)
		cout << values[i] << endl;
	cout << endl;

	cout << "Fourth quartile: " << endl;
	for (vec_sz i = q3; i != length; ++i)
		cout << values[i] << endl;
	cout << endl;
	
	return 0;
}