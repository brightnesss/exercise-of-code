// leetcode No.504 Base 7

/*
 *	Given an integer, return its base 7 string representation.
 */

string convertToBase7(int num)
{
	if (num == 0) return string("0");
	string ans;
	int x = abs(num);
	while (x)
	{
		int tmp = x % 7;
		ans = to_string(tmp) + ans;
		x /= 7;
	}
	if (num < 0) ans = "-" + ans;
	return ans;
}