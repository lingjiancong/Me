//
//  117_PopulatingNextRightPointersInEachNodeII.cpp
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
        
        TreeLinkNode *begin = root;
        TreeLinkNode *left = NULL, *right = NULL, *next = root;
        int way = 0;
        
        
        while (next) {
            begin = next;
            while (begin != NULL && left == NULL) {
                switch (way) {
                    case 0:
                        left = begin->left;
                        break;
                    case 1:
                        left = begin->right;
                        break;
                    case 2:
                        begin = begin->next;
                        break;
                }
                way = (++way) % 3;
            }
            next = left;
            if (left != NULL) {
                while (begin != NULL) {
                    switch (way) {
                        case 0:
                            right = begin->left;
                            break;
                        case 1:
                            right = begin->right;
                            break;
                        case 2:
                            begin = begin->next;
                            break;
                    }
                    if (right != NULL) {
                        left->next = right;
                        left = right;
                        right = NULL;
                    }
                    way = (++way) % 3;
                }
                left = right = NULL;
            }
        }
    }
};

int main() {
    return 0;
}
