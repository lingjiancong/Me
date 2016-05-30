#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int size = nums.size();
		if (size == 0 || size == 1)
			return;
		int position = nums.size() - 1;
		for (; position >= 0; --position) {
			if (!(position - 1 >= 0 && nums[position] <= nums[position - 1]))
				break;
		}
		if (position == 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		position--;

		int next = position + 1;
		for (; next < size; ++next) {
			if (nums[next] <= nums[position])
				break;
		}
		swap(nums[position], nums[next - 1]);
		reverse(nums.begin() + position + 1, nums.end());
	}

	void swap(int &a, int &b) {
		int t = a;
		a = b;
		b = t;
	}
};

int main() {
	Solution solution;
	vector<int> nums({2, 2, 0, 4, 3, 1});
	solution.nextPermutation(nums);
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}