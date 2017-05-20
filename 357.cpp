//leetcode No.357 Count Numbers with Unique Digits 

/*
 *	Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 *	Example:
 *	Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
 */

//数学题
//C(1,10) + C(1,9)*C(1,9) + C(1,9)*C(1,9)*C(1,8) + ... + C(1,9)*C(1,9)*...*C(1,1)
int countNumbersWithUniqueDigits(int n)
{ 
	if (n == 0) return 1;
	if (n == 1) return 10;
	int ans(10), count(9), tmp(9);
	for (int i = 2;i <= n;++i)
	{
		count *= tmp;
		ans += count;
		--tmp;
	}
	return ans;
}