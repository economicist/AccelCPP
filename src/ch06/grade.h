#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <stdexcept>
#include <vector>
#include "vecstats.h"
#include "Student_info.h"

struct Student_info;	// forward declaration (Student_info.h)

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double grade_aux(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
bool fgrade(const Student_info&);

#endif