//leetcode No.386 Lexicographical Numbers 

/*
 *	Given an integer n, return 1 - n in lexicographical order. 
 *	For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. 
 *	Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
 */

vector<int> lexicalOrder(int n) 
{	
	vector<int> ans(n);
	int curr = 1;
	for (int i = 0;i != n;++i)
	{
		ans[i] = curr;
		if (curr * 10 <= n) curr *= 10;
		else
		{
			if (curr >= n) curr /= 10;
		    curr += 1;
            while (curr % 10 == 0) curr /= 10;
		}
	}
	return ans;
}