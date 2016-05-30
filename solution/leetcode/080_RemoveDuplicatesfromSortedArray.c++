#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	sort(nums.begin(), nums.end());

    	int n = nums.size(), start = 2, index = 2;
    	for (int i = start; i < n; ++i) {
    		if (nums[i] != nums[index - 2]) {
    			nums[index++] = nums[i];
    		}
    	}

    	return index <= n ? index : n;
    }
};

int main() {

	Solution solution;
	vector<int> nums({ 1, 1, 2, 2, 1, 2, 2, 3 });
	int len = solution.removeDuplicates(nums);
	for (int i = 0; i < len; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}