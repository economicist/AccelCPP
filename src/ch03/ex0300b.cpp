#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;		using std::setprecision;
using std::cout;	using std::string;
using std::endl;	using std::streamsize;
using std::sort;	using std::vector;

int main() {
	// ask for and read the student's name
	cout << "Enter your first name: ";
	string name;
	cin >> name;
	cout << "Welcome, " + name + "!" << endl;

	// ask for and read midterm and final grades
	cout << "Enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter your homework grades, "
			"followed by end-of-file: ";

	// a variable into which to read
	// and a vector in which to store successive grades
	double x;
	vector<double> homework;
	// invariant: homework vector contains all the homework grades read so far
	while (cin >> x)
		homework.push_back(x);

	// ensure the homework vector is nonempty
	typedef vector<double>::size_type vec_sz;	// creates a size type called vec_sz
	vec_sz size = homework.size();	// creates a vec_sz size called size.
	if (size == 0) {
		cout << endl << "You must enter your homework grades. "
						"Please try again." << endl;
		return 1;
	}

	// sort the homework scores and find the median
	sort(homework.begin(), homework.end());
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
						   : homework[mid];

	// write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is: " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;

	return 0;
}