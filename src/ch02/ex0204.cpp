#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;		using std::endl;
using std::cout;	using std::string;

int main() {
	// ask for the person's name
	cout << "Please enter your first name: ";

	// read the name
	string name;
	cin >> name;

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";

	// the number of blanks surrounding the greeting
	int pad;
	cout << "Vertical Padding: ";
	cin >> pad;
	const int vpad = pad;
	cout << "Horizontal Padding: ";
	cin >> pad;
	const int hpad = pad;

	// the number of rows and columns to write
	const int rows = vpad * 2 + 3;
	const string::size_type cols = greeting.size() + hpad * 2 + 2;

	// write a blank line to separate the output from the input
	cout << endl;

	// write 'rows' rows of output
	// invariant: we have written r rows so far
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;
		// invariant: we have written c characters so far in the current row
		while (c != cols) {
			// is it time to write the greeting?
			if (r == vpad + 1 && c == hpad + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				// are we on a border or not?
				if (r == 0 || r == rows - 1) {
					// we are on the top or bottom border
					const string::size_type width = cols;
					const string stars(width, '*');
					cout << stars;
					c += width;
				} else if (c == 0 || c == cols - 1) {
					// we are on the left or right border
					cout << "*";
					++c;
				} else {
					// we're not on a border or about to write our greeting
					// so we are going to place padding
					if (r != 0 && r != rows - 1 && r != vpad + 1) {
						// place vertical padding
						const string::size_type width = cols - 2;
						const string vpadding(width, ' ');
						cout << vpadding;
						c += width;
					} else {
						// place horizontal padding
						const string hpadding(hpad, ' ');
						cout << hpadding;
						c += hpad;
					}
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}