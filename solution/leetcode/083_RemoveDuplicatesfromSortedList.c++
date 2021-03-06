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
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *t = head, *res = head, *tt = head;
    	if (!head)
    		return head;

    	int beforeValue = t->val;
    	t = t->next;
    	

    	while (t) {
    		if (t->val == beforeValue) {
    			t = t->next;
    		}
    		else {
    			tt->next = t;
    			beforeValue = t->val;
    			tt = tt->next;
    			t = t->next;
    		}
    	}
    	tt->next = NULL;
    	return res;
    }
};

int main() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(3);
	ListNode n5(4);
	ListNode n6(4);
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
	ListNode *res = solution.deleteDuplicates(head);
	while (res) {
		cout << res->val << " -> ";
		res = res->next;
	}
	cout << endl;
	return 0;
}