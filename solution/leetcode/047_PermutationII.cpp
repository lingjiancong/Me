
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		std::sort(nums.begin(), nums.end());
		vector<int> initialNums(nums);
		permuteUnique(result, initialNums, nums, -1);
		return result;
	}

	void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
		if (i == j - 1) {
			res.push_back(num);
			return;
		}
		for (int k = i; k < j; k++) {
			if (i != k && num[i] == num[k]) continue;
			swap(num[i], num[k]);
			recursion(num, i + 1, j, res);
		}
	}
	vector<vector<int> > permuteUnique2(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		recursion(num, 0, num.size(), res);
		return res;
	}

private:
	void permuteUnique(vector<vector<int>> &result, const vector<int> &initialNums, vector<int> nums, int index) {
		int begin = index + 1, size = nums.size();
		if (begin == size) {
			result.push_back(nums);
			return;
		}
		permuteUnique(result, initialNums, nums, begin);
		for (int i = begin + 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1])
				continue;

			rightShift(nums, begin, i);
			permuteUnique(result, initialNums, nums, begin);
			leftShift(nums, begin, i);
		}
	}

	void rightShift(vector<int> &nums, int begin, int i) {
		int t = nums[i];
		for (int j = i; j > begin; --j)
			nums[j] = nums[j - 1];
		nums[begin] = t;
	}

	void leftShift(vector<int> &nums, int begin, int i) {
		int t = nums[begin];
		for (int j = begin; j < i; ++j)
			nums[j] = nums[j + 1];
		nums[i] = t;
	}

	void swap(int &a, int &b) {
		int t = a;
		a = b;
		b = t;
	}

	
};

int main()
{
	vector<int> nums({ 3, 3, 0, 0, 2, 3, 2 });
	Solution solution;
	vector<vector<int>> result = solution.permuteUnique(nums);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}