#include <iostream>
using std::cout;
using std::endl;

int main() {
	int start = 10;
	int end = -5;
	for (int i = start; i != end - 1; --i)
		cout << i << endl;
	return 0;
}