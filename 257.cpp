// leetcode No.257 Binary Tree Paths

/*
 *	Given a binary tree, return all root-to-leaf paths. 
 *	For example, given the following binary tree: 
 *   	1
 * 	  /   \
 *	 2     3
 * 	  \
 *  	5
 *	All root-to-leaf paths are: 
 *	["1->2->5", "1->3"]
 */

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> ans;
	if (root)
	{
		string tmp;
		TreePaths(root, tmp, ans);
	}
	return ans;
}

void TreePaths(TreeNode* root, string tmp, vector<string> &ans)
{
	//递归调用该函数完成路径搜索
	if (!root) return;
	else
	{
		tmp += to_string(root->val);
		if ((root->left == NULL) && (root->right == NULL)) ans.push_back(tmp); //是叶子结点，保存路径
		else
		{
			tmp += "->";	//不是叶子结点才会加"->"符号
			TreePaths(root->left, tmp, ans);
			TreePaths(root->right, tmp, ans);
		}
	}
}