//leetcode No.343 Integer Break 

/*
 *	Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
 *	Return the maximum product you can get. 
 *	For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4). 
 *	Note: You may assume that n is not less than 2 and not larger than 58. 
 */

/*
 *	一个数被分解的加数越多,乘积会先上升后下降,利用这个性质,找到最大的乘积
 */
int integerBreak(int n)
{
	int product;
	int num = n / 2; 	//先直接分为两个加数
	int by = n - num;
	product = num*by;
	int tmp;
	for (int i = 3;i < n;++i)
	{
		//从三个加数开始继续分界
		if (n%i == 0)
		{
			//若这个数可以分解为连续的by个n/i相加,即n/i没有余数
			by = n / i;
			tmp = pow(i, by);
		}
		else
		{
			//若相除有余数,要先将余数取出
			num = n%i;
			num = num == 1 ? num + i : num; 	//如果余数是1,我们肯定不希望这种情况,因为1对乘积没有任何贡献,所以将余数取大一点,为1+i
			by = (n - num) / i;
			tmp = pow(i, by)*num; //最后要乘以余数
		}
		if (tmp > product) product = tmp; //如果乘积继续增大,就继续
		else break; //若乘积开始减小了,说明已经到了由上升到下降的拐点,即最大点,返回
	}
	return product;
}