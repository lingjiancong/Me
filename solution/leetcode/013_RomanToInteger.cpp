#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		int count = 0;
 		while (count < s.size()) {
			int part = 0;
			char c = s[count];
			part += getRomanValue(c);
			while (++count < s.size()) {
				int sValue = getRomanValue(s[count]);
				int cValue = getRomanValue(c);
				if (sValue != cValue) {
					if (sValue > cValue) {
						part = sValue - part;
						count++;
					}
					break;
				}
				else {
					part += cValue;
				}
			}
			res += part;
		}
		return res;
	}

	int getRomanValue(char c) {
		if (c == 'I')
			return 1;
		if (c == 'V')
			return 5;
		if (c == 'X')
			return 10;
		if (c == 'L')
			return 50;
		if (c == 'C')
			return 100;
		if (c == 'D')
			return 500;
		if (c == 'M')
			return 1000;
		return 0;
	}
};

int main()
{
	string s = "DCXXI";
	Solution solution;
	int res = solution.romanToInt(s);
	cout << res << endl;
	return 0;
}