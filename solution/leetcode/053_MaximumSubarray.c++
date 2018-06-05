#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;

            int leftSum = 0;
            int max = nums[0];
            for (int i = 0; i < nums.size(); ++i) {
                int maxTemp = 0;
                if (leftSum >= 0) {
                    maxTemp = leftSum + nums[i];
                    leftSum += nums[i];
                }
                else {
                    leftSum = nums[i];
                    maxTemp = leftSum;
                }
                if (maxTemp > max)
                    max = maxTemp;
            }
            return max;
        }
};

int main()
{
    Solution solution;
    int array[10] = {-1, -2, -1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
