/*
 *	95. Unique Binary Search Trees II
 *	Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

 *	For example,
 *	Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

/*
 *	I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. So if I pick i-th node as my root, 
 *	the left subtree will contain elements 1 to (i-1), and the right subtree will contain elements (i+1) to n. 
 *	I use recursive calls to get back all possible trees for left and right subtrees and combine them in all possible ways with the root.
 */

vector<TreeNode*> subGenerateTrees(int start, int end)
{
	vector<TreeNode*> ans;
	if (start > end)
	{
		ans.push_back(NULL);
		return ans;
	}
	else if (start == end)
	{
		ans.push_back(new TreeNode(start));
		return ans;
	}
	vector<TreeNode*> left, right;
	for (int i = start;i <= end;++i)
	{
		left = subGenerateTrees(start, i - 1);
		right = subGenerateTrees(i + 1, end);
		for (TreeNode* subleft : left)
		{
			for (TreeNode* subright : right)
			{
				TreeNode* root = new TreeNode(i);
				root->left = subleft;
				root->right = subright;
				ans.push_back(root);
			}
		}
	}
	return ans;
}

vector<TreeNode*> generateTrees(int n)
{
	if (n == 0) return vector<TreeNode*>{};
	return subGenerateTrees(1, n);
}