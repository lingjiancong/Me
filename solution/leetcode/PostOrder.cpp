//
//  PostOrder.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/2/8.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//


#include <iostream>
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
    void postOrder(TreeNode *root) {
        if (root == NULL)
            return;
        
        stack<TreeNode*> hold;
        stack<int> traversal;
        hold.push(root);
        traversal.push(1);
        
        while (!hold.empty()) {
            TreeNode *cur = hold.top();
            int tra = traversal.top();
            
            switch (tra) {
                case 0:
                    cout << cur->val << endl;
                    hold.pop();
                    traversal.pop();
                    if (cur->right != NULL) {
                        hold.push(cur->right);
                        traversal.push(1);
                    }
                    break;
                case 1:
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
    solution.postOrder(&n1);
    
    return 0;
}

