//
//  118_Pascal'sTriangle.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/1/24.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return vector<vector<int>>();
        vector<vector<int>> nums(numRows);
        nums[0] = vector<int>(1, 1);
        for (int i = 2; i <= numRows; ++i) {
            vector<int> num(i);
            num[0] = 1;
            for (int j = 1; j < (i + 1) / 2; ++j) {
                num[j] = nums[i - 2][j - 1] + nums[i -2][j];
            }
            for (int j = (i + 1) / 2; j < i; ++j) {
                num[j] = num[i - 1 - j];
            }
            nums[i - 1] = num;
        }
          return nums;
    }
  
};

int main() {
    Solution solution;
    vector<vector<int>> nums = solution.generate(5);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
