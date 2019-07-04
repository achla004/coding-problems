#include <iostream>
#include <string>
#include <stack>
using namespace std;
const bool debug = false;

inline bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

inline std::string expr(const std::string & text) {
	std::string result;

	std::stack<char> s {};
	char c;
	int pos = 0;
	while(pos < text.length()) {
		c = text[pos++];
		if(isOperator(c)) {
			s.push(c);
		} else if (c == '(') {
			s.push(c);
		} else if (c == ')') {
			while(s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop();
		} else {
			result += c;
		}
	}

	while(!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;
	cin.ignore(1, '\n');
	for(int i = 0; i < tests; ++i) {
		std::string line;
		getline(cin, line);
		if(debug) cout << " Line: " << line << endl;

		cout << expr(line) << '\n';
	}

	return 0;
}

