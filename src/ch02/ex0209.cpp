#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int x, y;
	cout << "Enter a number: ";
	cin >> x;
	cout << "Enter another number: ";
	cin >> y;

	int min, max;
	if (x < y) {
		min = x;
		max = y;
	} else {
		min = y;
		max = x;
	}

	cout << "Maximum: " << max << endl;
	return 0;
}