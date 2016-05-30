#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>> &matrix) {

		if (matrix.empty())
			return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();

		vector<int> left(n, 0), right(n, n), height(n, 0);
		int maxArea = 0;

		for (int i = 0; i < m; ++i) {
			int curLeft = 0, curRight = n;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					height[j]++;
					left[j] = max(left[j], curLeft);
				}
				else {
					height[j] = 0;
					left[j] = 0;
					curLeft = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; --j) {
				if (matrix[i][j] == '1')
					right[j] = min(right[j], curRight);
				else {
					right[j] = n;
					curRight = j;
				}
			}

			for (int j = 0; j < n; ++j) 
				maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
		}
		return maxArea;
	}
};

int main() {
	vector<vector<char>> nums({ {'0', '0', '1', '0'}, {'1', '1', '1', '0'} });

	Solution solution;
	cout << solution.maximalRectangle(nums) << endl;
	return 0;
}