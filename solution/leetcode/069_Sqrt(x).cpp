#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 1 || x == 0)
			return x;

		int left = 1, right = x;

		while (left < right) {
			int mid = (left + right) / 2;
			int divide = x / mid;
			if (mid > divide) {
				right = mid;
			}
			else if (mid <= divide) {
				left = mid + 1;
			}
		}
		return left - 1;
	}
};

int main() {
	Solution solution;
	cout << solution.mySqrt(2) << endl;
	cout << solution.mySqrt(53) << endl;
	return 0;
}