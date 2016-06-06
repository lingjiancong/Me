#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {

    	vector<int> cache;
    	vector<char> operators;
    	int num = 0;
    	int n = s.size();
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == '*' || s[i] == '/') {
    			char op = s[i];
    			int num1 = 0;
    			while (i < n - 1 && s[++i] == ' ')
    				;
    			while ( (s[i] - '0') >= 0 && (s[i] - '0') < 10) {
    				num1 = num1 * 10 + (s[i] - '0');
    				++i;
    			}
    			--i;
    			if (op == '*')
    				num *= num1;
    			else if (op == '/')
    				num /= num1;
    		}
    		else if (s[i] == '+' || s[i] == '-') {
    			char op = s[i];
    			cache.push_back(num);
    			num = 0;
    			operators.push_back(op);
    		}
    		else if (s[i] != ' ') {
    			num = num * 10 + (s[i] - '0');
    		}
    	}
    	cache.push_back(num);
    	num= cache[0];
    	n = operators.size();
    	for (int i = 0; i < n; ++i) {
    		if (operators[i] == '+')
    			num += cache[i + 1];
    		else if (operators[i] == '-')
    			num -= cache[i + 1];
    	}
    	return num;
    }
};

int main() {

	Solution solution;
	string s = "3+2*2";
	cout << solution.calculate(s) << endl;

	s = "3/2";
	cout << solution.calculate(s) << endl;

	s = "3+5 / 2";
	cout << solution.calculate(s) << endl;

	s = "1-1+1";
	cout << solution.calculate(s) << endl;
	return 0;
}
