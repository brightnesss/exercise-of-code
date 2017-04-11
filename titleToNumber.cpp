// leetcode No.171 Excel Sheet Column Number 

/*
 *	Related to question Excel Sheet Column Title
 *	Given a column title as appear in an Excel sheet, return its corresponding column number.
 *	For example:
 *  A -> 1
 *  B -> 2
 *  C -> 3
 *  ...
 *  Z -> 26
 *  AA -> 27
 *  AB -> 28 
 */

#include "includelib.h"

int titleToNumber(string s)
{
	int length = s.size();
	int ans(0);
	for (int i = 0;i != length;++i)
	{
		ans += pow(26, length - i - 1) * (s[i] - 'A' + 1);
	}
	return ans;
}