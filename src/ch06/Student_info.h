#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <list>
#include <vector>		// std::string
#include <string>		// std::vector
#include <algorithm>	// find()
#include "grade.h"

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