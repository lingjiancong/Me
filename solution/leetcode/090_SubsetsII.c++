#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> combination;

        int n = nums.size();
        unordered_map<int, int> count;

        for (int i = 0; i <n; ++i) {
            if (count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else
                count[nums[i]]++;
        }

        for (int k = 0; k <= n; ++k) {
        	combineNext(result, combination, count, nums, k,  0);
        }
        return result;

    }

private:
    void combineNext(vector<vector<int>> &result, vector<int> &combination, unordered_map<int, int> &count,
    	vector<int> &nums, int k, int start) {
    	int n = nums.size();
    	if (k == 0) {
        	result.push_back(combination);
        	return;
    	}
        else if (start >= n) {
            return;
        }
        else if (k < 0) {
            return;
        }

    	int end = n - k;
    	for (int i = start; i <= end; ) {
            int p = count[nums[i]];
        	combination.push_back(nums[i]);
        	combineNext(result, combination, count, nums, k - 1, i + p);
        	combination.pop_back();
          
            if (p != 1) {
                int q = 1;
                while (++q <= p) {
                    int j = 0;
                    while (j++ < q) {
                        combination.push_back(nums[i]);
                    }
                    combineNext(result, combination, count, nums, k - q, i + p);
                    j = 0;
                    while (j++ < q) {
                        combination.pop_back();
                    }
                }
            }
            i = i + p;
    	}

	}
};

int main() {

	Solution solution;

	vector<int> nums({ 2, 2, 1, 2, 2});
	vector<vector<int>> result = solution.subsetsWithDup(nums);
	int row = result.size();
	for (int i = 0; i < row; ++i) {
		cout << "[ ";
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << "  ";
		}
		cout << "]";
		cout << endl;
	}
	return 0;
}