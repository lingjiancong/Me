//
//  115_DistinctSubsequences.cpp
//  LeetCode
//
//  Here is an example:
//  S = "rabbbit", T = "rabbit"
//  Return 3.
//
//  Created by jiancong ling on 2017/1/19.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solved, but need to be improved, HaHa!!
class Solution {
public:
    int numDistinct(string s, string t) {
        int t_size = (int)t.size(), s_size = (int)s.size();
        string ss;
        int chars[256];
        for (int i = 0; i < t_size; ++i) {
            chars[(int) t[i]] = 1;
        }
        for (int i = 0; i < s_size; ++i) {
            if (chars[(int) s[i]] == 1) {
                ss = ss + s[i];
            }
        }
        s_size = (int)ss.size();
        s = ss;
        
        if (t_size == 0) {
            return 1;
        }
        if (s_size < t_size) {
            return 0;
        }
        
        vector<vector<int>> nums(s_size, vector<int>(t_size, -1));
        
        int count = get(s, 0, t, 0, nums);
        
        return count;
    }
    
private:
    
    int get(string s, int s_index, string t, int t_index, vector<vector<int>> &nums) {
        if (t_index >= t.size()) {
            return 1;
        }
        if (s_index >= s.size()) {
            return 0;
        }
        if (nums[s_index][t_index] != -1) {
            return nums[s_index][t_index];
        }
        int count = 0;
        if (s[s_index] == t[t_index]) {
            int count1 = get(s, s_index + 1, t, t_index + 1, nums);
            if (s_index + 1 < s.size() && t_index + 1 < t.size())
                nums[s_index + 1][t_index + 1] = count1;
            count += count1;
        }
        int count2 = get(s, s_index + 1, t, t_index, nums);
        if (s_index + 1 < s.size())
            nums[s_index + 1][t_index] = count2;
        count += count2;
        
        return count;
    }
    
};

int main() {
    string s = "rabbbit212fda11211213", t = "rabit11";
    Solution solution;
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}
