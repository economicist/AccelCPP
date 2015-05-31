#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::setprecision;
using std::cout;	using std::string;
using std::endl;	using std::streamsize;
using std::vector;

int main() {
	// a vector containing students and another containing total scores
	vector<string> students;
	vector<double> totalScores;

	string name;
	int i = 0;	// how many students have we counted?
	// invariant: we have found the total scores of i students so far
	while (cin >> name) {
		cout << i << " " << name << " ";
		// store the student's name in the vector of student names.
		students.push_back(name);

		// read midterm and final grades
		double midterm, final;
		cin >> midterm >> final;
		cout << midterm << " " << final << " ";

		// the number and sum of homework grades read so far
		int count = 0;
		double sum = 0;

		// a variable into which to read homework grades
		double x;

		// invariant: we have read 'count' grades so far,
		// and 'sum' is the sum of the first count grades
		for (int k = 0; k != 6; k++) {
			cin >> x;
			cout << x << " ";
			++count;
			sum += x;
		}
		cout << endl;

		// compute average homework and total score
		if (count == 0) {
			double score = (0.2 * midterm + 0.4 * final) / 0.6;
			totalScores.push_back(score);
		} else {
			double score = 0.2 * midterm + 0.4 * final + 0.4 * sum / count;
			totalScores.push_back(score);
		}

		i++; // makes the invariant true again,
			 // since we have read and stored one
			 // more student's name and his scores.
	}

	typedef vector<string>::size_type vec_str_sz;
	typedef vector<double>::size_type vec_dbl_sz;
	vec_str_sz studentsCounted = students.size();
	vec_dbl_sz scoresTallied = totalScores.size();

	for (vec_str_sz i = 0; i != studentsCounted; ++i) {
		vec_dbl_sz j = i;
		cout << students[i] << " " << totalScores[j] << endl;
	}

	return 0;
}