#include <iostream>

int main() {
	int k = 0, n = 10;
	while (k != n) {	// invariant: we have written k asterisks so far
		using std::cout;	// establish that we are using std::cout in this scope
		cout << "*";
		++k;
	}
	std::cout << std::endl;	// std:: is required here because
							// the using expression was in another scope
	return 0;
}