#include <iostream>
using std::endl;
using std::cout;

class Solution {
public:
	int uniquePaths(int m, int n) {
		const int size = 101;
		int matrix[size][size] = { 0 };
		matrix[1][0] = 1;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
			}
		}
		return matrix[m][n];
	}
};

int main() {
	Solution solution;
	cout << solution.uniquePaths(2, 4) << endl;
	return 0;
}