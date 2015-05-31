#include <iostream>
#include <string>

using std::cout;	using std::endl;
using std::cin;		using std::string;

int main() {
	cout << "Provide an input of words:" << endl;

	string word;
	cin >> word;
	string smallWord = word;
	string bigWord = word;

	while(cin >> word) {
		
		if (word.size() < smallWord.size()) {
			smallWord = word;
		}

		if (word.size() > bigWord.size()) {
			bigWord = word;
		}
		
	}

	cout << "Shortest word: " << smallWord << endl;
	cout << "Longest word: " << bigWord << endl;
}