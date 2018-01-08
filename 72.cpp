/*
 *	72. Edit Distance
 *	Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *	You have the following 3 operations permitted on a word:
 *	a) Insert a character
 *	b) Delete a character
 *	c) Replace a character
 */

/*
 *	This is a classic problem of Dynamic Programming. We define the state dp[i][j] to be the minimum number of operations to 
 *	convert word1[0..i - 1] to word2[0..j - 1]. The state equations have two cases: the boundary case and the general case. 
 *	Note that in the above notations, both i and j take values starting from 1.

 *	For the boundary case, that is, to convert a string to an empty string, it is easy to see that the mininum number of operations to 
 *	convert word1[0..i - 1] to "" requires at least i operations (deletions). In fact, the boundary case is simply:
		dp[i][0] = i;
		dp[0][j] = j.

 *	Now let's move on to the general case, that is, convert a non-empty word1[0..i - 1] to another non-empty word2[0..j - 1]. 
 *	Well, let's try to break this problem down into smaller problems (sub-problems). Suppose we have already known how to 
 *	convert word1[0..i - 2] to word2[0..j - 2], which is dp[i - 1][j - 1]. Now let's consider word[i - 1] and word2[j - 1]. 
 *	If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]. Well, what if they are not equal?

 *	If they are not equal, we need to consider three cases:
 *	Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
 *	Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
 *	Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
 
 *	Make sure you understand the subtle differences between the equations for deletion and insertion. For deletion, 
 *	we are actually converting word1[0..i - 2] to word2[0..j - 1], which costs dp[i - 1][j], and then deleting the word1[i - 1], which costs 1. 
 *	The case is similar for insertion.

 *	Putting these together, we now have:
		dp[i][0] = i;
		dp[0][j] = j;
		dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
		dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
 */

//算法设计很复杂,但代码还是很简单
int minDistance_72(string word1, string word2)
{
	int m(word1.size()), n(word2.size());
	vector<vector<int>> bin(m + 1, vector<int>(n + 1, 0));
	for (int i = 1;i != m + 1;++i) bin[i][0] = i;
	for (int j = 1;j != n + 1;++j) bin[0][j] = j;
	for (int i = 1;i != m + 1;++i)
	{
		for (int j = 1;j != n + 1;++j)
		{
			if (word1[i - 1] == word2[j - 1]) bin[i][j] = bin[i - 1][j - 1];
			else bin[i][j] = min(bin[i - 1][j - 1], min(bin[i][j - 1], bin[i - 1][j])) + 1;
		}
	}
	return bin[m][n];
}

/*
 *	由于每一次更新都只涉及到bin[i-1][j-1],bin[i][j-1],bin[i-1][j]这三个数,即只涉及两列,所以不需要O(mn)的空间复杂度,可以降低为O(m)
 *	设两个数组分别表示前一列pre和当前列cur
 *	初始时,将pre的每一个值初始化,相当于 for (int j = 1;j != n + 1;++j) bin[0][j] = j;
 *	之后,每次都按行更新,循环次数为列数
 */

int minDistance_72(string word1, string word2)
{
	int m(word1.size()), n(word2.size());
	vector<int> pre(m + 1, 0), cur(m + 1, 0);
	for (int i = 1;i != m + 1;++i) pre[i] = i;	//初始化第一列
	for (int j = 1;j != n + 1;++j)	//循环这么多次,相当于将矩阵mn的每一列都遍历一次
	{
		cur[0] = j;	//相当于初始化第一行 for (int i = 1;i != m + 1;++i) bin[i][0] = i;
		for (int i = 1;i != m + 1;++i)	
		{
			//按行更新
			if (word1[i - 1] == word2[j - 1]) cur[i] = pre[i - 1];	//cur[i]相当于bin[i][j], cur[i-1]相当于bin[i-1][j], pre[i-1]相当于bin[i-1][j-1],pre[i]相当于bin[i][j-1]
			else cur[i] = min(cur[i - 1], min(pre[i], pre[i - 1])) + 1;
		}
		swap(pre, cur);	//交换两列
	}
	return pre[m];
}