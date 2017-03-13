//
//  120_Triangle.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/2/6.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        
        vector<int> circum(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; ++j) {
                int min = circum[j] > circum[j + 1] ? circum[j + 1] : circum[j];
                circum[j] = min + triangle[i][j];
            }
        }
        
        return circum[0];
    }

    
    int minimumTotal_1(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        
        vector<vector<int>> circum;
        for (int i = 0; i <  triangle.size(); ++i) {
            circum.push_back(vector<int>(triangle[i].size(), INT_MIN));
        }

        int least = calc(triangle, circum, 0, 0);
        
        return least;
        
    }
    
private:
    int calc(vector<vector<int>> &triangle, vector<vector<int>> &circum, int row, int column) {
        if (circum[row][column] != INT_MIN)
            return circum[row][column];
        else if (row == triangle.size() - 1)
            return triangle[row][column];
        
        int left = calc(triangle, circum, row + 1, column);
        int right = calc(triangle, circum, row + 1, column + 1);
        if (left > right) {
            circum[row][column] = right + triangle[row][column];
        } else {
            circum[row][column] = left + triangle[row][column];
        }
        return circum[row][column];
        
    }

};

int main() {
    vector<vector<int>> nums;
    
    nums.push_back(vector<int>{2});
    nums.push_back(vector<int>{3, 4});
    nums.push_back(vector<int>{6, 5, 7});
    nums.push_back(vector<int>{4, 1, 8, 3});
    
    Solution solution;
    int least = solution.minimumTotal(nums);
    cout << least << endl;
    return 0;
}
