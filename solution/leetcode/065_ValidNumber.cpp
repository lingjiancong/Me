#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;

class Solution {
public:
	bool isNumber(string s) {
		int size = s.size();
		if (size == 0)
			return false;
		int begin = 0;

		while (begin < size && s[begin] == ' ') {
			begin++;
		}
		while (size > begin && s[size -1] == ' ') {
			size--;
		}
		if (begin == size)
			return false;
		char c = s[begin];
		if (c == '+' || c == '-')
			begin++;
		if (begin == size)
			return false;

		bool point = false;
		for (int i = begin; i < size; ++i) {
			char c = s[i];
			int index = c - '0';
			if (index >= 0 && index <= 9) {
				;
			}
			else if ( (c == 'e' || c == 'E') && i != begin) {
				return isPositiveInt(s, ++i, size);
			}
			else if (c == '.' && !point) {
			
				if (i == size - 1 && i == begin)
					return false;
				else if (i == begin && i != size - 1 && (s[i + 1] == 'e' || s[i + 1] == 'E'))
					return false;
				point = true;
			}
			else
				return false;
		}
		return true;
	}
private:
	bool isPositiveInt(string s, int begin, int size) {
		if (size == begin)
			return false;
		if (s[begin] == '+' || s[begin] == '-')
			begin++;
		if (size == begin)
			return false;

		for (int i = begin; i < size; ++i) {
			char c = s[i];
			int index = c - '0';
			if (!(index >= 0 && index <= 9))
				return false;
		}
		return true;
	}
};

int main() {
	Solution solution;
	string s1 = "1234";
	cout << s1 << ":" << solution.isNumber(s1) << endl;

	string s2 = "abc";
	cout << s2 << ":" << solution.isNumber(s2) << endl;

	string s3 = ".";
	cout << s3 << ":" << solution.isNumber(s3) << endl;

	string s4 = ".e10 ";
	cout << s4 << ":" << solution.isNumber(s4) << endl;
	return 0;
}