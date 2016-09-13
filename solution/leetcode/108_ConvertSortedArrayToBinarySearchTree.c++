#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {

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
        root->right = right;

        return root;
    }

};


int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));

    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);

    solution.print(root);
}



