#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	vector<int> spiralOrder1(vector<vector<int>>& matrix) {
		vector<int> sprial;
		int m = matrix.size();
		if (m == 0)
			return sprial;
		int n = matrix[0].size();
		spiralMatrix(matrix, sprial, 0, m, 0, n);
		return sprial;
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return vector<int>();
		int n = matrix[0].size();
		vector<int> sprial(m*n);
		int count = 0;
		int mBegin = 0, mEnd = m, nBegin = 0, nEnd = n;
		while (true) {
			for (int i = nBegin; i < nEnd; ++i) {
				sprial[count++] = matrix[mBegin][i];
			}
			mBegin++;
			if (mBegin >= mEnd)
				break;
			for (int i = mBegin; i < mEnd; ++i) {
				sprial[count++] = matrix[i][nEnd - 1];
			}
			nEnd--;
			if (nEnd <= nBegin)
				break;
			for (int i = nEnd - 1; i >= nBegin; --i) {
				sprial[count++] = matrix[mEnd - 1][i];
			}
			mEnd--;
			if (mEnd <= mBegin)
				break;
			for (int i = mEnd - 1; i >= mBegin; --i) {
				sprial[count++] = matrix[i][nBegin];
			}
			nBegin++;
			if (nBegin >= nEnd)
				break;
		}
		return sprial;
	}

private:
	void spiralMatrix(vector<vector<int>> &matrix, vector<int> &sprial, int mBegin, int mEnd, int nBegin, int nEnd) {
		for (int i = nBegin; i < nEnd; ++i) {
			sprial.push_back(matrix[mBegin][i]);
		}
		mBegin++;
		if (mBegin >= mEnd)
			return;
		for (int i = mBegin; i < mEnd; ++i) {
			sprial.push_back(matrix[i][nEnd - 1]);
		}
		nEnd--;
		if (nEnd <= nBegin)
			return;
		for (int i = nEnd - 1; i >= nBegin; --i) {
			sprial.push_back(matrix[mEnd - 1][i]);
		}
		mEnd--;
		if (mEnd <= mBegin)
			return;
		for (int i = mEnd - 1; i >= mBegin; --i) {
			sprial.push_back(matrix[i][nBegin]);
		}
		nBegin++;
		if (nBegin >= nEnd)
			return;
		spiralMatrix(matrix, sprial, mBegin, mEnd, nBegin, nEnd);
	}
};

int main() {
	vector<vector<int>> matrix({ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } });
	Solution solution;
	vector<int> spiral = solution.spiralOrder(matrix);
	for (int i = 0; i < spiral.size(); ++i)
		cout << spiral[i] << " ";
	cout << endl;
	return 0;
}