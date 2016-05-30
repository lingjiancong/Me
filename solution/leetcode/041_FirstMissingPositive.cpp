#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] >= 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
				swap(nums[nums[i] - 1], nums[i]);
		}
		for (int i = 0; i < n; ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}

	int firstMissingPositive1(vector<int>& nums) {
		return firstMissingPositive(nums, 1, 0, nums.size());
	}

private:
	int firstMissingPositive(vector<int>& num, int expectMin, int begin, int end) {
		if (end - begin == 1) {
			if (num[begin] == expectMin)
				return expectMin + 1;
			else
				return expectMin;
		}
		int min = INT_MAX;
		int countPositive = 0;
		for (int i = begin; i < end; ++i) {
			if (num[i] > 0) {
				countPositive++;
				if (num[i] < min)
					min = num[i];
			}

		}
		if (min != expectMin)
			return expectMin;

		int median = (min + min + countPositive - 1) / 2;
		int i = begin, j = begin;
		for (i = begin; i < end; ++i) {
			if (num[i] <= median && num[i] > 0) {
				swap(num[i], num[j]);
				j++;
			}
		}
		int count = j - begin + 1;
		int expectCount = median - begin + 1;
		if (j != median) {
			if (j == end)
				return expectMin + 1;
			return firstMissingPositive(num, expectMin, begin, j);
		} 
		else {
			return firstMissingPositive(num, median + 1, median, end);
		}
		return 0;
	}

	void swap(int &a, int &b) {
		int t = a;
		a = b;
		b = t;
	}
};

int main() {
	vector<int> nums({ 1, 2, -1, 1, 3, 5, 6 });
	Solution solution;
	cout << solution.firstMissingPositive(nums) << endl;
	return 0;
}