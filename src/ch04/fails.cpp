#include <algorithm>		// std::sort, std::max
#include <iomanip>			// std::setprecision
#include <ios>				// std::streamsize
#include <iostream>			// std::cout, std::cin, std::endl
#include <stdexcept>		// std::domain_error
#include <string>			// std::string
#include <vector>			// std::vector
#include "grade.h"			// grade
#include "Student_info.h"	// Student_info, compare, read, read_hw

using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	// the length of the longest name

	// read and store all the students' data.
	// Invariant: students contains all the student records read so far
	//			  maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		// and add the new record to the students vector
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the student records and extract the fails
	sort(students.begin(), students.end(), compare);
	vector<Student_info> fails = extract_fails(students);
	
	// write the names and grades
	// for (vector<Student_info>::iterator iter = fails.begin(); iter != fails.end(); ++iter) {
	// 	// write the names, padded on the right to maxlen+1 characters
	// 	cout << (*iter).name << string(maxlen + 1 - (*iter).name.size(), ' ');

	// 	// compute and write the grade
	// 	try {
	// 		double final_grade = grade(*iter);
	// 		streamsize prec = cout.precision();
	// 		cout << setprecision(3) << final_grade << setprecision(prec);
	// 	} catch(domain_error e) {
	// 		cout << e.what();
	// 	}
	// 	cout << endl;
	// }
}