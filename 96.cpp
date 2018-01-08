/*
 *	96. Unique Binary Search Trees

 *	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 *	For example,
 *	Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

/*
 *	动态规划,设置一个数组bin来存储当有i个结点时,存在的独一的二叉搜索树的个数
 *	思路如下:
 		1)对于任意一个[1,2,3,...,n-1,n]构成的二叉搜索树,都可以看作由每一个结点作为根节点构成数的叠加,即由1作为根节点与2作为根节点...n作为根节点
 		  即若F(i,n)为对于以上数组,有数字i作为根节点构成二叉树的个数,则bin[n]=F(1,n)+F(2,n)+...+F(n,n)
 		2)但任何一个根节点都可以将数组分为两部分,即小于根节点的[1,2,3,...,i-1]和大于根节点的[i+1,i+2,...,n-1,n],如此递归循环,既可以的到最后的解
 		3)但是在比较的过程中,每一个数字的最对大小意义不重要,主要是比较相对大小,则2)中左子树[1,2,3,...,i-1]实际上和bin[i-1]是相同的
		  同理,2)中右子树[i+1,i+2,...n]和bin[n-i]是相同的
		4)所以F(i,n)=bin[i-1]*bin[n-i]
 */

int numTrees(int n)
{
	if (n == 0) return 0;
	vector<int> bin(n + 1, 1);
	bin[0] = 1, bin[1] = 1;
	int left, right, cur;
	for (int i = 2;i <= n;++i)
	{
		cur = 0;
		for (int j = 1;j <= i;++j)
		{
			left = j - 1;	//左子树
			right = i - j;	//右子树
			cur += bin[left] * bin[right];	//F(j,i)
		}
		bin[i] = cur;
	}
	return bin[n];
}