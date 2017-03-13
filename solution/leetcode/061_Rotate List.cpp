//
//  061_Rotate List.cpp
//  LeetCode
//
//  Created by jiancong ling on 2017/2/23.
//  Copyright © 2017年 jiancong ling. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        
        if (k == 0)
            return head;
        
        int len = 1;
        ListNode *tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        
        k = k%len ? k%len : k;
        int left = len - k;
        if (left <= 0)
            return head;
        
        int count = 1;
        ListNode *before = head;
        while (count < left) {
            count++;
            before = before->next;
        }
        
        ListNode *next = before->next;
        before->next = NULL;
        tail->next = head;
        
        return next;
    }
};

int main() {
    ListNode n1(1), n2(2);
    n1.next = &n2;
    
    Solution solution;
    solution.rotateRight(&n1, 1);
}


