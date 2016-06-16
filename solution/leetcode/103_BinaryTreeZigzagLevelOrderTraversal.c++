
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
        	return vector<vector<int>>();
        vector<vector<int>> result;
        progress(result, root, 0);

        return result;
    }

private:
	void progress(vector<vector<int>> &result, TreeNode *node, int level) {
		if (node == NULL)
			return;
		if (result.size() == level)
			result.push_back(vector<int>());
		if (level % 2 == 0)
			result[level].push_back(node->val);
		else
			result[level].insert(result[level].begin(), node->val);

		progress(result, node->left, level + 1);
		progress(result, node->right, level + 1);

	}
};