#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> nums(n + 1, 0);
		nums[0] = nums[1] = 1;
		for (int i = 2; i <= n; ++i) {
			// nums[i]
			for (int j = 1; j <= i; ++j) 
				nums[i] += nums[j - 1] * nums[i - j];
		}
		return nums[n];
	}
};

int main() {
	Solution solution;
	int n = 3;

	cout << "n = " << n << " " << solution.numTrees(n) << endl;

	n = 5;
	cout << "n = " << n << " " << solution.numTrees(n) << endl;
	return 0;
}