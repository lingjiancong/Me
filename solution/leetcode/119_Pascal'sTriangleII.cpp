//
//  119_Pascal'sTriangleII.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/2/1.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0 || rowIndex == 1)
            return vector<int>(rowIndex + 1, 1);
        vector<int> row(rowIndex + 1, 1);
        int previous = 1;
        for (int k = 2; k <= rowIndex; ++k) {
            previous = 1;
            for (int i = 1; i <= k / 2; ++i) {
                int t = row[i];
                row[i] = previous + row[i];
                previous = t;
            }
            for (int i = k / 2 + 1; i < k; ++i) {
                row[i] = row[k - i];
            }
        }
        return row;
    }
};

int main() {
    int rowIndex = 4;
    Solution solution;
    vector<int> row = solution.getRow(rowIndex);
    for (int i = 0; i < row.size(); ++i) {
        cout << row[i];
    }
    cout << endl;
    
}


