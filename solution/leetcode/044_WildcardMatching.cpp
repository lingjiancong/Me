#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s == "" && p == "")
			return true;
		else if (p == "")
			return false;
		else if (s == "")
			return p == "*";

		char sc = s[0], pc = p[0];
		string np = p.substr(1), ns = s.substr(1);
		//string np(p, 1, p.size()), ns(s, 1, s.size());
		if (pc == '?') {	
			return isMatch(ns, np);
		}
		else if (pc == '*') {
			return isMatch(ns, p) || isMatch(s, np);
		}
		else if (sc != pc)
			return false;
		else
			return isMatch(ns, np);
	}
};

int main() {

	string s = "aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab";
	string p = "*ab***ba**b*b*aaab*b"; 
	Solution solution;
	cout << solution.isMatch(s, p) << endl;
	cout << "false: " << false << endl;
	cout << "true: " << true << endl;
	return 0;
}