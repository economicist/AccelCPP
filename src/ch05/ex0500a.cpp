#include <algorithm>		// std::max
#include <iomanip>			// std::setprecision
#include <ios>				// std::streamsize
#include <iostream>			// std::cout, std::cin, std::endl
#include <stdexcept>		// std::domain_error
#include <string>			// std::string
#include "grade.h"			// grade
// #include "Student_info.h"	// Student_info, compare, read, read_hw

using std::cin;				using std::setprecision;
using std::cout;			using std::max;
using std::domain_error;	using std::streamsize;
using std::endl;			using std::string;

int main() {
	gradebook students;
	Student_info record;
	string::size_type maxlen = 0;	// the length of the longest name

	// read and store all the students' data.
	// Invariant: students contains all the student records read so far
	//			  maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		// and add the new record to the students list
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the student records and extract the fails
	students = sortByName(students);
	gradebook fails = extract_fails(students);

	// write the names and grades
	for (gradebook::iterator iter = students.begin(); iter != students.end(); ++iter) {
		// write the names, padded on the right to maxlen+1 characters
		cout << (*iter).name << string(maxlen + 1 - (*iter).name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch(domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

}