// leetcode No.258 Add Digits

/*
 *	Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. 
 *	For example: 
 *	Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 
 *	Follow up:
 *	Could you do it without any loop/recursion in O(1) runtime? 
 */

#include "inlcudelib.h"

int addDigits(int num)
{
	int numAdd(num);
	while (numAdd > 9)
	{
		string numStr(to_string(numAdd));
		int count(0);
		for (size_t pos = 0;pos != numStr.size();++pos)
		{
			count += numStr[pos] - '0';
		}
		numAdd = count;
	}
	return numAdd;
}

//如何达到O(1)的复杂度还没有想到