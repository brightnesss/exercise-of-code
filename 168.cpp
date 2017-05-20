// leetcode No.168 Excel Sheet Column Title 

/*
 *	Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *	For example:
 *	   1 -> A
 *	   2 -> B
 *	   3 -> C
 *	   ...
 *	   26 -> Z
 *	   27 -> AA
 *	   28 -> AB 
 */


//可以认为是10进制转26进制，只不过是从1开始计数的，所以要(n-1)
string convertToTitle(int n)
{
	string ans;
	while (n)
	{
		int tmp = (n - 1) % 26;
		char digit = 'A' + tmp;
		ans = digit + ans;
		n = (n - 1) / 26;
	}
	return ans;
}