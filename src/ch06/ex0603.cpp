// Exercise 6-3 and 6-4
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> u(10, 100);	// 10 copies of the integer 100
	vector<int> v;
	// copy(u.begin(), u.end(), v.begin());				// segfault
	// copy(u.begin(), u.end(), back_inserter(v));		// works
	// copy(u.begin(), u.end(), front_inserter(v));		// works
	copy(u.begin(), u.end(), inserter(v, v.end()));		// works

	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		cout << *i << endl;
	}
}