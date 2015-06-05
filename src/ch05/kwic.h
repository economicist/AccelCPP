#ifndef GUARD_kwic_h
#define GUARD_kwic_h

#include <string>
#include <vector>

struct Phrase_pair {
	std::vector<std::string> left, right;
};

struct Phrase_pair_collection {
	std::vector<Phrase_pair> pairs;
	std::string::size_type lWidth, rWidth;
};

Phrase_pair rotatePhrase(const Phrase_pair&);
Phrase_pair_collection phraseRotations(const std::string&);
Phrase_pair_collection append(const Phrase_pair_collection&, const Phrase_pair_collection&);
std::string vecstr2string(const std::vector<std::string>&);
bool compare(const Phrase_pair&, const Phrase_pair&);

#endif