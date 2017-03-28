#include "includelib.h"

// leetcode No.292 Nim Game

// 可以找规律，也可以当作动态规划来做
 

bool canWinNim(int n)
{
	if (n <= 3) return true;
	else
	{
		vector<bool> canWin(n + 1, true);
		for (int i = 1;i <= n;++i)
		{
			if (canWin[i - 1] && canWin[i - 2] && canWin[i - 3]) canWin[i] = false;
			else continue;
		}
		return canWin[n];
	}

	/*
	if (n % 4 == 0) return false;
    else return true;
	*/
}