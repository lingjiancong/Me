
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;

		vector<TreeNode*> row(1, root);
		traversal(result, row);
		return result;
	}

private:
	void traversal(vector<vector<int>> &result, vector<TreeNode*> row) {
		int size = row.size();
		if (size == 0)
			return;
		vector<int> v;
		vector<TreeNode*> nextRow;
		for (int i = 0; i < size; ++i) {
			v.push_back(row[i]->val);
			if (row[i]->left)
				nextRow.push_back(row[i]->left);
			if (row[i]->right)
				nextRow.push_back(row[i]->right);

		}
		result.insert(result.begin(), v);
		traversal(result, nextRow);
	}
};