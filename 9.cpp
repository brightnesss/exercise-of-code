/*
 *	9. Palindrome Number
 *	Determine whether an integer is a palindrome. Do this without extra space.

 *	Could negative integers be palindromes? (ie, -1)
 *	If you are thinking of converting the integer to string, note the restriction of using extra space.
 *	You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
 	you know that the reversed integer might overflow. How would you handle such case?
 *	There is a more generic way of solving this problem.
 */

//创建一个x的翻转径向数ans,判断ans==x
//奇怪的是负数都不是回文的,我觉得负数也应该有回文
bool isPalindrome_9(int x)
{
	if (x < 0) return false;
	int right(x), ans(0);
	int divide(1);
	while (x / divide > 9)
	{
		divide *= 10;
	}
	while (right != 0)
	{
		ans += divide*(right % 10);
		divide /= 10;
		right /= 10;
	}
	return ans == x;
}