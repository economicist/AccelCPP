#include <iostream>
using std::cin;		using std::endl;
using std::cout;	using std::string;

int main() {
	int numberIn;
	
	cout << "Enter height: ";
	cin >> numberIn;
	const int height = numberIn;

	cout << "Enter width: ";
	cin >> numberIn;
	const int width = numberIn;

	int s;
	if (height > width)
		s = height;
	else
		s = width;
	const int side = s;

	// square of stars
	cout << endl;
	for (int r = 0; r != s; ++r) {
		const string::size_type qStars = side;
		const string stars(qStars, '*');
		cout << stars << endl;
	}

	// rectangle of stars
	cout << endl;
	for (int r = 0; r != height; ++r) {
		const string::size_type qStars = width;
		const string stars(qStars, '*');
		cout << stars << endl;
	}

	// triangle of stars
	cout << endl;
	for (int r = 0; r != height; ++r) {
		const string::size_type qStars = r + 1;
		const string stars(qStars, '*');
		cout << stars << endl;
	}
}