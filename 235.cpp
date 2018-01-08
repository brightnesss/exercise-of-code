/*
 *	235. Lowest Common Ancestor of a Binary Search Tree
 *	Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *	According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the 
 *	lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

 *	For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
 *	since a node can be a descendant of itself according to the LCA definition.
 */

/*
 *	这个代码是建立在树中没有重复结点的基础上的,但同样通过了测试
 *	因为是二叉树,左右子树严格小于/大于根节点
 *	1)若p和q中有一个就是root节点,则他们的共同根肯定是root
 *	2)若p和q分别大于/小于root结点,即p和q分别在root结点的两端,则最低根节点也肯定是root
 *	3)若p和q不满足2),即他们在root的同一侧,则递归调用该函数
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == p || root == q) return root;	//1)
	if ((root->val - p->val)*(root->val - q->val) < 0) return root;	//2)
	if (p->val < root->val&&q->val < root->val) return lowestCommonAncestor(root->left, p, q);	//3)同在左子树
	else if (p->val > root->val&&q->val > root->val) return lowestCommonAncestor(root->right, p, q);	//3)同在右子树
}