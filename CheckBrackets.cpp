//============================================================================
// Name        : CheckBrackets.cpp
// Author      : Vadim Genkin
// Version     :
// Copyright   :
// Description : Check Brackets program
//============================================================================

#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

bool CheckBrackets(string s)
{
	stack<char> st;
	set<char> open_bracket_set{'(','{','['};
	set<char> close_bracket_set{')', '}', ']'};

	unordered_map<char,char> bracket_pairs {{'(', ')'}, {'{','}'},{'[',']'}};

	for(char &c : s) {
		if(open_bracket_set.count(c)) {
			st.push(c);
		}
		else if(close_bracket_set.count(c)) {
			if( bracket_pairs[st.top()] == c ) {
				st.pop();
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	bool result = CheckBrackets("({[]})");
	result ? cout << "passed" << endl : cout << "failed" << endl;

	return 0;
}
