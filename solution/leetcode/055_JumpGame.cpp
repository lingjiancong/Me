#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int position = 0; 
		int step = nums[position];
		int size = nums.size();
		while (position < size - 1) {
			int max = position, nextPosition = position;
			for (int i = 1; i <= nums[position]; ++i) {
				if (position + i >= size - 1) {
					position = size;
					break;
				}
				if (max < position + i + nums[position + i] && nums[position + i] != 0) {
					max = position + i + nums[position + i];
					nextPosition = position + i;
				}
			}
			if (position == nextPosition)
				break;
			else if (position >= size - 1)
				break;
			else
				position = nextPosition;
		}

		if (position < size - 1)
			return false;
		return true;

	}
};

int main() {
	vector<int> nums({ 3, 2, 1, 0, 4 });
	Solution solution;
	cout << solution.canJump(nums) << endl;
	return 0;
}