//leetcode No.338 Counting Bits 

/*
 *	Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array. 
 *	Example:
 *	For num = 5 you should return [0,1,1,2,1,2]. 
 */


/*
 *	0的二进制中有0个1
 *	如果一个数是奇数,则它的上一个数肯定是偶数,且只在上一个数的基础上在最后一位加1,故f(n)=f(n-1)+1 iff n is odd
 *	如果一个数是偶数,则它和它的一半含1个数相同,因为它可以通过它的一半左移一位得到
 */
vector<int> countBits(int num)
{
	vector<int> ans(num + 1, 0);
	for (int i = 1;i != num + 1;++i)
	{
		if (i & 1)	ans[i] = ans[i - 1] + 1; //若是奇数
		else ans[i] = ans[i >> 1]; //若是偶数
	}
	return ans;
}