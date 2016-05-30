#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;

class Solution{
public:
	string multiply(string num1, string num2) {
		int size = num1.size() + num2.size();
		string result(size, '0');

		int carry = 0, n1 = num1.size(), n2 = num2.size(), n3 = result.size();
		for (int i = n2 - 1; i >= 0; --i) {
			int indexBegin = n3 + i - n2;
			int index = 0;
			for (int j = n1 - 1; j >= 0; --j) {
				int v = (num2[i] - '0') * (num1[j] - '0');
				index = indexBegin + (j - n1 + 1);
				int value = v + (result[index] - '0') + carry;
				carry = value / 10;
				result[index] = value % 10 + '0';
			}
			result[index - 1] = ((result[index - 1] - '0') + carry) + '0';
			carry = 0;
		}

		int countZero = 0;
		for (countZero = 0; countZero < n3; ++countZero) {
			if (result[countZero] != '0')
				break;
		}
		if (countZero == n3)
			result = "0";
		else {
			string nResult(result, countZero, n3);
			result = nResult;
		}
		return result;
	}
};

int main() {
	Solution solution;
	string num1 = "11", num2 = "11";
	cout << solution.multiply(num1, num2) << endl;
	return 0;
}