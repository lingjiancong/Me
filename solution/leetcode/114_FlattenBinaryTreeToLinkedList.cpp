//
//  114_FlattenBinaryTreeToLinkedList.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/1/19.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        
        vector<TreeNode*> vecs;
        traversal(root, vecs);
        
        int size = vecs.size();
        for (int i = 0; i < size - 1; ++i) {
            vecs[i]->left = vecs[i]->right = NULL;
            vecs[i]->right = vecs[i + 1];
        }
    }
    
private:
    void traversal(TreeNode* node, vector<TreeNode*> &vecs) {
        vecs.push_back(node);
        
        if (node->left != NULL) {
            traversal(node->left, vecs);
        }
        if (node->right != NULL) {
            traversal(node->right, vecs);
        }
    }
};

int main() {
    return 0;
}
