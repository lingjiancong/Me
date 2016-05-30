#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > res;
		for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
			if (i + 1 < nums.size()) {
				int j = i + 1, p = nums.size() - 1;
				while (j < p) {
					int sum = nums[j] + nums[p] + nums[i];
					if (sum == 0) {
							vector<int> vRes(3, 0);
							vRes[0] = nums[i];
							vRes[1] = nums[j];
							vRes[2] = nums[p];
							res.push_back(vRes);

							while (j < p && nums[j] == vRes[1]) j++;
							while (j < p && nums[p] == vRes[2]) p--;
					}
					else if (sum > 0)
						p--;
					else
						j++;
				}
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				i++;
		}
		return res;
	}
};

int main()
{
	int a[] = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	Solution solution;
	vector<vector<int> > result;
	result = solution.threeSum(nums);
	return 0;
}

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int closest = nums[0] + nums[1] + nums[2];
		int closestDistance = abs(closest - target);
		for (int i = 0; i < nums.size(); ++i) {
			if (i + 1 < nums.size()) {
				int j = i + 1, p = nums.size() - 1;
				while (j < p) {
					int sum = nums[j] + nums[p] + nums[i];
					int distance = abs(sum - target);
					if (distance < closestDistance) {
						closest = sum;
						closestDistance = distance;

					}
					if (sum == target) {
						j++;
						p--;
					}
					else if (sum > target)
						p--;
					else
						j++;
				}
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				i++;
		}
		return closest;
	}

	int abs(int v) {
		return v >= 0 ? v : v * -1;
	}
};