//
//  PostOrder.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/2/8.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == NULL)
            return vector<int>();
        
        stack<TreeNode*> hold;
        stack<int> traversal;
        hold.push(root);
        traversal.push(1);
        
        vector<int> result;
        
        while (!hold.empty()) {
            TreeNode *cur = hold.top();
            int tra = traversal.top();
            
            switch (tra) {
                case 0:
                    hold.pop();
                    traversal.pop();
                    if (cur->right != NULL) {
                        hold.push(cur->right);
                        traversal.push(1);
                    }
                    break;
                case 1:
                    result.push_back(cur->val);
                    traversal.pop();
                    traversal.push(0);
                    if (cur->left != NULL) {
                        hold.push(cur->left);
                        traversal.pop();
                        traversal.push(0);
                        traversal.push(1);
                    } else {
                        traversal.pop();
                        traversal.push(0);
                    }
                    break;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    TreeNode n1(5), n2(4), n3(8), n4(11), n5(13), n6(4), n7(7), n8(2), n9(5), n10(1);
//    
//    n1.left = &n2, n1.right = &n3;
//    n2.left = &n4;
//    n3.left = &n5, n3.right = &n6;
//    n4.left = &n7, n4.right = &n8;
//    n6.left = &n9, n6.right = &n10;
    
    TreeNode n1(1), n2(2);
    n1.left = &n2;
    Solution solution;
    vector<int> result = solution.preorderTraversal(&n1);
 
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

