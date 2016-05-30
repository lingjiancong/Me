#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode lessNode(0);
    	ListNode moreNode(0);

    	ListNode *less = &lessNode;
    	ListNode *more = &moreNode;
    	ListNode *t = head;

    	while (t) {
    		if (t->val < x) {
    			less->next = t;
    			less = less->next;
    		}
    		else {
    			more->next = t;
    			more = more->next;
    		}
    		t = t->next;
    	}
    	more->next = NULL;
    	less->next = moreNode.next;
    	return lessNode.next;
    }
};

int main() {
	ListNode n1(1);
	ListNode n2(4);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(5);
	ListNode n6(2);
	ListNode n7(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	ListNode *head = &n1;
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;

	Solution solution;
	head = &n1;
	ListNode *res = solution.partition(head, 3);
	while (res) {
		cout << res->val << " -> ";
		res = res->next;
	}
	cout << endl;
	return 0;
}