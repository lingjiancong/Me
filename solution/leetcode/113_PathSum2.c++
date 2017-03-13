/***
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
**/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) 
            return false;
        int left = sum - root->val;
        
        bool leftHas = false;
        if (root->left)
            leftHas = hasPathSum(root->left, left);
        bool rightHas = false;
        if (root->right)
            rightHas = hasPathSum(root->right, left); 
        return leftHas || rightHas || (left == 0 && !root->left && !root->right);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        
    }
};

int main() {
    return 0;
}
