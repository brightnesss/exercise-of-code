/*
 *	279. Perfect Squares
 *	Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *	For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 */

/*
 *	对每一个数x,可以认为,x是这样构成的：
 *	y + square = x, 若x由最少的平方数构成,则y也由最少的平方数构成
 *	设置bin来记录x最少可以由几个平方数构成
 *	则对于任何小于x的square,遍历x-square,并寻找最小的bin[x-square],则bin[x]=min(bin[x-square])+1
 */

int numSquares(int n)
{
	vector<int> bin(n + 1, INT_MAX);
	bin[0] = 0;
	vector<int> square;
	for (int i = 1;i <= sqrt(n);++i) square.push_back(i*i);
	for (int i = 1;i != n + 1;++i)
	{
		for (int j = 0;j != square.size()&&square[j] <= i;++j)
		{
			bin[i] = min(bin[i - square[j]] + 1, bin[i]);
		}
	}
	return bin[n];
}