#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if (n == 0)
    		return 0;
    	if (n == 1)
    		return 1;
    	if (n == 2)
    		return 2;

    	int one = 2;
    	int two = 1;
    	for (int i = 3; i <= n; ++i) {
    		int all = one + two;
    		two = one;
    		one = all;
    	}
    	return one;
       
    }

};

int main() {
	Solution solution;
	int tab = 45;
	for (int i = 0; i < tab; ++i) {
		cout << "climbStatirs " << i << " steps: " << solution.climbStairs(i) << endl;
	}
	return 0;
}