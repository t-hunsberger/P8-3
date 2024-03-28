#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r) {
	switch (r) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:
			cerr << "Invalid Roman Numeral character: " << r << endl;
			return 0;
	}
}

int convertRomanToInt(string s) {
	int total = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (i < s.length() - 1 && romanCharValue(s[i]) < romanCharValue(s[i + 1])){
			total -= romanCharValue(s[i]);
		}
		else {
			total += romanCharValue(s[i]);
		}
	}
	return total;
}

int main() {
	string input;
	while (true) {
		cout << "Enter Roman Number or Q to quit: ";
		getline(cin, input);
		if(input == "Q" || input == "q")break;
		int numWords = convertRomanToInt(input);
		cout << input << " = " << convertRomanToInt(input) << endl;

	}
}