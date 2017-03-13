//
//  116_PopulatingNextRightPointersInEachNode.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/1/20.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        
        TreeLinkNode* begin = root;
        TreeLinkNode *right = NULL, *next = begin->left;
        
        while (begin->left != NULL) {
            begin->left->next = begin->right;
            if (right != NULL)
                right->next = begin->left;
            right = begin->right;
            if (begin->next == NULL) {
                begin = next;
                if (begin != NULL)
                    next = begin->left;
                right = NULL;
            } else
                begin = begin->next;
        }
    }
};

int main() {
    cout << "Hello" << endl;
    return 0;
}
