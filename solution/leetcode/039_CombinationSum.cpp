#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<vector<int>> result = vector<vector<int>>();
		if (candidates.size() == 0)
			return result;
		int longSize = target / candidates[0];

		for (int i = 1; i <= longSize; ++i) {
			vector<vector<int>> fixedSizeResult = combinationSum(candidates, target, i, 0);
			for (int j = 0; j < fixedSizeResult.size(); ++j) {
				//std::reverse(fixedSizeResult[j].begin(), fixedSizeResult[j].end());
				result.push_back(fixedSizeResult[j]);
			}
		}
		return result;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target, int size, int candidatesIndex) {
		vector<vector<int>> localResult = vector<vector<int>>();
		if (size == 1) {
			if (std::find(candidates.begin() + candidatesIndex, candidates.end(), target) != candidates.end()) {
				vector<int> element = vector<int>();
				element.push_back(target);
				localResult.push_back(element);
			}
			return localResult;
		}
		for (int i = candidatesIndex; i < candidates.size(); ++i) {
			int left = target - candidates[i];
			vector<vector<int>> partResult;
			if (left > 0) {
				partResult = combinationSum(candidates, left, size - 1, i);
				for (int j = 0; j < partResult.size(); ++j)
					partResult[j].insert(partResult[j].begin(), candidates[i]);
			}
			for (int j = 0; j < partResult.size(); ++j)
				localResult.push_back(partResult[j]);
		}
		return localResult;
	}
};

int main() {
	Solution solution;
	vector<int> candidates({2, 3, 6, 7});
	int target = 7;
	vector<vector<int>> result = solution.combinationSum(candidates, target);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	cout << "end end end " << endl;
	return 0;
}