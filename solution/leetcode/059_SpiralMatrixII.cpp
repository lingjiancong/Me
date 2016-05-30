#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::vector;
using std::string;
using std::endl;
using std::cout;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0)
			return vector<vector<int>>();
		vector<vector<int>> result(n, vector<int>(n, 0));
		int count = 0;

		int rowBegin = 0, rowEnd = n, colBegin = 0, colEnd = n;
		int len = n * n;
		while (rowBegin < rowEnd && colBegin < colEnd) {
			for (int i = colBegin; i < colEnd; ++i) {
				result[rowBegin][i] = ++count;
			}
			rowBegin++;
			for (int i = rowBegin; i < rowEnd; ++i) {
				result[i][colEnd - 1] = ++count;
			}
			colEnd--;
			for (int i = colEnd - 1; i >= colBegin && count < len; --i) {
				result[rowEnd - 1][i] = ++count;
			}
			rowEnd--;
			for (int i = rowEnd - 1; i >= rowBegin && count < len; --i) {
				result[i][colBegin] = ++count;
			}
			colBegin++;
		}
		return result;
	}	
};

int main() {
	Solution solution;
	vector<vector<int>> spiral = solution.generateMatrix(3);
	for (int i = 0; i < spiral.size(); ++i) {
		for (int j = 0; j < spiral.size(); ++j)
			cout << spiral[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}