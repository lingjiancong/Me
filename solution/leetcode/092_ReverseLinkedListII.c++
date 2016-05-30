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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

    	if (m == n)
    		return head;
    	m = m - 1;

    	ListNode *firstHead = head, *firstEnd = NULL;
    	ListNode *secondHead = NULL, *secondEnd = NULL;
    	ListNode *thirdHead = NULL, *thirdEnd = NULL;

    	int k = 0;
    	ListNode *t = head;
    	while (++k < m) {
    		t = t->next;
    	}
    	firstEnd = t;

    	if (m == 0)
    		secondHead = head;
    	else
    		secondHead = t->next;
    	t = secondHead;
    	k = 0;
    	int p = n - m;
    	while (++k < p) {
    		t = t->next;
    	}
    	secondEnd = t;
    	thirdHead = t->next;

    	ListNode *before = secondHead, *cur = secondHead->next;
    	secondEnd->next = NULL;

    	while (cur) {
    		t = cur->next;
    		cur->next = before;
    		before = cur;
    		cur = t;
    	}

    	if (m == 0)
    		firstHead = secondEnd;
    	else
    		firstEnd->next = secondEnd;
    	secondHead->next = thirdHead;

    	return firstHead;
    }
};

int main() {

	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);

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
	int m = 1, n = 7;
	ListNode *res = solution.reverseBetween(head, m, n);
	while (res) {
		cout << res->val << " -> ";
		res = res->next;
	}
	cout << endl;
	return 0;
}