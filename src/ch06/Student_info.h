#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>		// std::istream
#include <list>			// std::list
#include <vector>		// std::vector
#include <string>		// std::string
#include <algorithm>	// find(), sort(), remove_if(), remove_copy_if()
#include "grade.h"		// grade(), fgrade(), pgrade()

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

typedef std::vector<Student_info> gradebook;

bool compare(const Student_info&, const Student_info&);
std::list<Student_info> sortByName(std::list<Student_info>&);
std::vector<Student_info> sortByName(std::vector<Student_info>&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
gradebook extract_fails(gradebook&);

#endif