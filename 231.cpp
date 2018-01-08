/*
 *	231. Power of Two
 *	Given an integer, write a function to determine if it is a power of two.
 */

/*
 *	最简单的思路,一直除以2直到不是2的倍数
 *	判断n此时是否为1,若为1,说明是2的倍数,否则不是
 */
bool isPowerOfTwo(int n)
{
	if (n<=0) return false;
	while(n%2==0) n/=2;
	return n==1;
}

/*
 *	若是2的倍数,则二进制中只有一位为1
 *	根据这一点进行判断
 *	使用n&(n-1)判断含有几个1
 */
bool isPowerOfTwo_v2(int n)
{
	if (n<=0) return false;
	return !(n&(n-1));
}