/*
 *	190. Reverse Bits
 *	Reverse bits of a given 32 bits unsigned integer.
 *	For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 	return 964176192 (represented in binary as 00111001011110000010100101000000).

 *	Follow up:
 	If this function is called many times, how would you optimize it?

 *	Related problem: Reverse Integer
 */

/*
 *	相当于是将n向右移动的同时,将ans向左移动,相当于完成了swap
 */
uint32_t reverseBits(uint32_t n)
{
	int ans;
	for (int i = 0;i != 32;++i)
	{
		ans = (ans << 1) + (n >> i & 1);
	}
	return ans;
}