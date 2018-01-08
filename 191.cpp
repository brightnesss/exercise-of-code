/*
 *	191. Number of 1 Bits
 *	Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *	For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */

/*
 *	只要n!=0,n中肯定存在1
 *	n-1使得从右向左数第一个1变为0,这个1后面的0变为1
 	两个数做与操作,使得这个数及之后的数都变为0
 */
int hammingWeight(uint32_t n)
{
	int ans(0);
	while (n != 0)
	{
		++ans;
		n &= n - 1;
	}
	return ans;
}