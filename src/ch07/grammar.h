#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include <cstdlib>		// rand()
#include <ctime>		// std::time
#include <iostream>		// std::istream
#include <map>			// std::map
#include <string>		// std::string
#include <stdexcept>	// std::domain_error, std::logic_error
#include <vector>		// std::vector
#include "string.h"		// split()

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
int nrand(int);

#endif