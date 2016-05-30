#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int rowBegin = 0, rowEnd = n, columnBegin = 0, columnEnd = n;
		for (int i = rowBegin; i < rowEnd; ++i) {
			for (int j = columnBegin; j < columnEnd - 1; ++j) {
				int i0 = i, j0 = j;
				int i1 = j, j1 = n - 1 - i;
				int i2 = n - 1 - i, j2 = n - 1 - j;
				int i3 = n - 1 - j, j3 = i;

				int t = matrix[i3][j3];
				matrix[i3][j3] = matrix[i2][j2];
				matrix[i2][j2] = matrix[i1][j1];
				matrix[i1][j1] = matrix[i0][j0];
				matrix[i0][j0] = t;	
			}
			--rowEnd; --columnEnd; ++columnBegin;
		}
	}


	void rotateAwesome(vector<vector<int> > &matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				std::swap(matrix[i][j], matrix[j][i]);
		}
	}
};

int main() {
	vector<vector<int>> nums({ { 1, 2, 3 }, { 4, 5, 6 },{7, 8, 9} });

	Solution solution;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[i].size(); ++j) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	solution.rotate(nums);
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[i].size(); ++j) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}