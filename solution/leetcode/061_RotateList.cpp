#include <iostream>
using std::cout;
using std::endl;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		int size = 0;
		ListNode *newHead = head;
		while (newHead) {
			size++;
			newHead = newHead->next;
		}
		if (size == 0 || !(k %= size))
			return head;
		int k1th = k + 1;
		ListNode *k1thNode = head;

		int count = 0;
		while (++count < k1th && k1thNode) {
			k1thNode = k1thNode->next;
		}
		if (!k1thNode)
			return head;
		ListNode *tailNode = k1thNode;
		k1thNode = head;
		while (tailNode->next) {
			tailNode = tailNode->next;
			k1thNode = k1thNode->next;
		}
		ListNode *kthNode = k1thNode ? k1thNode->next : NULL;
		if (tailNode)
			tailNode->next = head;
		if (k1thNode)
			k1thNode->next = NULL;
		return kthNode;
	}
};

int main() {

	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.next = &n2;  
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;

	ListNode *head = &n1;
	
	Solution solution;
	ListNode *rotate = solution.rotateRight(NULL,1);
	while (rotate) {
		cout << rotate->val << "->";
		rotate = rotate->next;
	}
	cout << endl;

	return 0;
}