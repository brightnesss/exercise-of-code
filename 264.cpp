/*
 *	264. Ugly Number II
 *	Write a program to find the n-th ugly number.
 *	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 *	For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *	Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
 */

/*
 *	设bin来存放已有的ugly number, 则最新的一个ugly number的值肯定是之前某一个ugly number的2倍,或3倍,或5倍,因为要按顺序,所以需要求这三个数中的最小值
 *	设三个数p2,p3,p5来表示2倍数,3倍数,5倍数的位置,相当于指针
 *	若新的这个数是p2的2倍,则p2需要右移一位,同理对其他2个指针也是相同
 *	需要注意的是,因为某些数的不同倍数是相同的,比如:2的3倍=6,3的2倍也为6,所以对于每一个新的ugly number,对所有三个指针都需要进行判断,而不能只判断一个
 */

int nthUglyNumber(int n)
{
	if (n <= 0) return 0;
	vector<int> bin(n, 1);
	int p2(0), p3(0), p5(0);
	for (int i = 1;i != n;++i)
	{
		bin[i] = min(bin[p2] * 2, min(bin[p3] * 3, bin[p5] * 5));
		if (bin[i] == bin[p2] * 2) ++p2;	//这里不能用else if,否则对6这种数,就会跳过
		if (bin[i] == bin[p3] * 3) ++p3;
		if (bin[i] == bin[p5] * 5) ++p5;
	}
	return bin.back();
}