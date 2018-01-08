/*
 *	202. Happy Number
 *	Write an algorithm to determine if a number is "happy".
 *	A happy number is a number defined by the following process: Starting with any positive integer, 
 	replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
 	or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

 *	Example: 19 is a happy number
	1^2 + 9^2 = 82
	8^2 + 2^2 = 68
	6^2 + 8^2 = 100
	1^2 + 0^2 + 0^2 = 1
 */

//通过set来记录已经到达过的数字,防止出现循环
bool isHappy(int n)
{
	set<int> s;
	int sum(0);
	while (n != 1)
	{
		if (s.find(n) != s.end()) return false;
		s.insert(n);
		sum = 0;
		while (n != 0)
		{
			sum += pow((n % 10), 2);
			n /= 10;
		}
		n = sum;
	}
	return true;
}

/*
 *	还可以通过类似链表快慢指针的方式,若两个相遇,则说明有环
 *	因为1的平方永远等于1,所以不论有没有环,两个指针都会相遇,只是看相遇点是不是1
 */
int digitSquare(int n)
{
	int sum(0);
	while(n!=0)
	{
		sum+=pow(n%10,2);
		n/=10;
	}
	return sum;
}

bool isHappy(int n)
{
	int slow(n),fast(n);
	while(true)
	{
		slow=digitSquare(slow);
		fast=digitSquare(fast);
		fast=digitSquare(fast);
		if (slow==fast) break;
	}
	return slow==1;
}