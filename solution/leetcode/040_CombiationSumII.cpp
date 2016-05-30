#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
private:
	void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &combination, int begin) {
		if (target == 0) {
			result.push_back(combination);
			return;
		}
		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
			if (i == begin || candidates[i] != candidates[i - 1]) {
				combination.push_back(candidates[i]);
				combinationSum2(candidates, target - candidates[i], result, combination, i + 1);
				combination.pop_back();
			}
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> combination;

		combinationSum2(candidates, target, result, combination, 0);
		return result;
	}


};

int main() {
	Solution solution;
	vector<int> candidates({ 10, 1, 2, 7, 6, 1, 5 });
	int target = 8;
	vector<vector<int>> result = solution.combinationSum2(candidates, target);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}