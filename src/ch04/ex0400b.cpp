#include <iostream>		// std::cout, std::cin, std::endl, std::istream
#include <vector>		// std::vector
#include <algorithm>	// std::sort, std::max
#include <string>		// std::string
#include <ios>			// std::streamsize
#include <iomanip>		// std::setprecision
#include <stdexcept>	// std::domain_error

using std::cout;		using std::sort;
using std::cin;			using std::max;
using std::endl;		using std::streamsize;
using std::string;		using std::setprecision;
using std::vector;		using std::domain_error;
using std::istream;

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

double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

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

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

istream& read(istream& is, Student_info& s) {
	// read and store the student's name and midterm/final exam grades
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);	// read and store all homework grades for student
	return is;
}

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the records, and find the length of the longest name
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		// write the name, padded on the right to maxlen+1 characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write out the total grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
}