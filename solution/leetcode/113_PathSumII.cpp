//
//  LeetCode
//
//  Created by jiancong ling on 2016/12/27.
//  Copyright © 2016年 jiancong ling. All rights reserved.
//
//  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vecs;
        if (root == NULL) {
            return vecs;
        }
        vector<int> path;
        int sump= 0;
        
        iterate(root, vecs, path, sum, sump);
        
        
        return vecs;
    }
    
private:
    void iterate(TreeNode* root, vector<vector<int>> &vecs, vector<int> &path, int sum, int sump) {
        sump += root->val;
        path.push_back(root->val);
        
        if (sump == sum && root->left == NULL && root->right == NULL) {
            vecs.push_back(path);
            path.pop_back();
            return;
        }
        
        if (root->left != NULL) {
            iterate(root->left, vecs, path, sum, sump);
        }
        
        if (root->right != NULL) {
            iterate(root->right, vecs, path, sum, sump);
        }
        
        path.pop_back();
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TreeNode n1(5), n2(4), n3(8), n4(11), n5(13), n6(4), n7(7), n8(2), n9(5), n10(1);
    
    n1.left = &n2, n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5, n3.right = &n6;
    n4.left = &n7, n4.right = &n8;
    n6.left = &n9, n6.right = &n10;
    
    Solution solution;
    int sum = 22;
    vector<vector<int>> vecs = solution.pathSum(&n1, sum);
    
    for (int i = 0; i < vecs.size(); i++) {
        for (int j = 0; j < vecs[i].size(); ++j) {
            cout << " " << vecs[i][j];
        }
        cout << endl;
    }
    return 0;
}
