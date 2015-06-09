#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <iostream>		// std::istream
#include <map>			// std::map
#include <string>		// std::string
#include <vector>		// std::vector
#include "string.h"		// split()

std::map<std::string, std::vector<int> >
	xref(std::istream& in, std::vector<std::string> find_words(const std::string&));

#endif