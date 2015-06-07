#ifndef GUARD_median_h
#define GUARD_median_h

#include <stdexcept>	// std::domain_error
#include <vector>		// std::vector
#include <algorithm>	// sort()
#include <numeric>		// accumulate()

double median(std::vector<double>);
double average(const std::vector<double>&);

#endif