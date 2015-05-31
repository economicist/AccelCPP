// include directives and using-declarations for library facilities
#include <iostream>		// std::cout, std::cin, std::endl
#include <string>		// std::string
#include <vector>		// std::vector
#include <algorithm>	// std::sort
#include <iomanip>		// std::setprecision
#include <ios>			// std::streamsize
#include <stdexcept>	// std::domain_error

using std::cout;	using std::string;
using std::cin;		using std::vector;
using std::endl;	using std::streamsize;
using std::sort;	using std::setprecision;
using std::istream;	using std::domain_error;

// code for median function from sec4.1.1/53
// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
// since this function changes the value of the input vector by design
// when the sort function is called, and we do not want these changes
// propagating back to the main program
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// code for grade(double, double, double) function from sec4.1/52
// compute a student's overall grade from midterm, final, and homework scores
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// code for grade(double, double, const vector<double>&) function from sec4.1.2/54
// compute a student's overall grade from midterm and final exam grades
// and a vector of homework scores
// this function does not copy its argument, because median does so for us
// 'const vector<double>&' accesses the argument vector directly, but the
// const qualifier ensures that we do not make changes that propagate back
// to the main program
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

// code for read_hw(istream&, vector<double>&) function from sec4.1.3/57
// read homework grades from an input stream into a vector<double>
// the input stream is taken in, modified by data entry, and returned
// the vector (as reference) is taken in, and modified in place.  It is not
// copied, meaning that as soon as something happens to it inside this function,
// it happens outside the function as well.
istream& read_hw(istream& in, vector<double>& hw) {
	// proceed if the input stream actually has data for us to read in
	if (in) {
		// if there is data on the input stream, then
		// get rid of previous contents
		hw.clear();

		// read homework grades until either of:
		//		actual end-of-file is reached
		//		something that isn't a grade is on the input stream
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

int main() {
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all your homework grades, "
			"followed by end-of-file: ";

	vector<double> homework;

	// read the homework grades
	read_hw(cin, homework);

	// compute and generate the final grade, if possible
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(4)
			 << final_grade << setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "You must enter your grades.  "
						"Please try again." << endl;
		return 1;
	}

	return 0;
}