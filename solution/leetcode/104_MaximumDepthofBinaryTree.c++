
class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	int leftDepth = maxDepth(root->left) + 1;
    	int rightDepth = maxDepth(root->right) + 1;

    	return leftDepth > rightDepth ? leftDepth : rightDepth;        
    }
};

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (root == NULL)
			return 0;

		int res = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			++ res;
			for (int i = 0, n = q.size(); i < n; ++i) {
				TreeNode *p = q.front();
				q.pop();

				if (p->left != NULL)
					q.push(p->left);
				if (p->right != NULL)
					q.push(p->right);
			}
		}
		return res;
	}
};


