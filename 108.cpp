//leetcode No.108. Convert Sorted Array to Binary Search Tree 

/*
 *	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		TreeNode* tmp = NULL;
		return tmp;
	}
	else if (nums.size() == 1)
	{
		TreeNode* tmp = new TreeNode(nums[0]);
		return tmp;
	}
	vector<int>::iterator mid = nums.begin() + nums.size() / 2;
	TreeNode* root = new TreeNode(*mid);
	vector<int> first(nums.begin(), mid);
	vector<int> second(mid + 1, nums.end());
	TreeNode* lchild = sortedArrayToBST(first);
	TreeNode* rchild = sortedArrayToBST(second);
	root->left = lchild;
	root->right = rchild;
	return root;
}