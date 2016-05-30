#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl; 

class Solution {
public:
	string addBinary(string a, string b) {

		int longN = a.size(), shortN = b.size();
		string longS, shortS;
		if (longN > shortN) {
			longS = a;
			shortS = b;
		}
		else {
			longS = b;
			shortS = a;
			std::swap(longN, shortN);
		}

		string addResult(longN, '0');
		bool carry = false;
		for (int i = longN - 1; i >= 0; --i) {
			int count = 0;
			if (carry) count++;
			if (i - longN + shortN >= 0 && shortS[i - longN + shortN] == '1') count++;
			if (longS[i] == '1') count++;
			switch (count) {
			case 0:
				addResult[i] = '0';
				break;
			case 1:
				addResult[i] = '1';
				carry = false;
				break;
			case 2:
				addResult[i] = '0';
				carry = true;
				break;
			case 3:
				addResult[i] = '1';
				carry = true;
				break;
			}
		}
		if (carry)
			return "1" + addResult;
		return addResult;
	}
};

int main() {
	Solution solution;
	string a = "1111";
	string b = "1111";
	cout << solution.addBinary(a, b) << endl;
	return 0;
}