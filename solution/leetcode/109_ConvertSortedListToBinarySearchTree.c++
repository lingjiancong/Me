/**
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {

    TreeNode *node;

public:

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;

        node = head;
        int size = 0;

        // calc the size of list
        ListNode *temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        TreeNode *root = build(0, size - 1);
    }

private:

    TreeNode* build(int start, int end) {

        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *left = build(start, mid - 1);

        TreeNode *root = new TreeNode(node->val);

        TreeNode *right = build(mid + 1, end);

        root->left = left;
        root->right = right;

        // move 
        node = node->next;

        return root;
    }

public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *bst = getBST(nums, 0, nums.size() - 1);
        return bst;
    }

    void print(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        print(root->left);
        cout << root->val << " || ";
        print(root->right);
    }

private:

    TreeNode* getBST(vector<int>& nums, int begin, int end) {
        if (begin > end)
            return NULL;
        if (begin == end)
            return new TreeNode(nums[begin]);

        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        TreeNode *left = getBST(nums, begin, mid - 1);
        TreeNode *right = getBST(nums, mid + 1, end);

        root->left = left;
        root->right = right; return root;
    }

};

ListNode *buildList(const vetor<int> &nums) {

    int size = nums.size();
    if (size == 0)
        return NULL;
    int index = 0;

    ListNode *first = new ListNode(nums[index++]);
    ListNode *origin = first;

    while (index < size) {
        ListNode *next = new ListNode(nums[index++]);
        origin->next = next;
        origin = next;
    }
    return first;
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));

    ListNode *head = buildList(nums);

    Solution solution;
    TreeNode *root = solution.sortedListToBST(head);
    solution.print(root);

    root = solution.sortedArrayToBST(nus);
    solution.print(root); 
} 
    

