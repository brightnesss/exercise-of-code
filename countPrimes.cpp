//leetcode No.204 Count Primes 

/* 
 *	Count the number of prime numbers less than(not include) a non-negative number, n.
 */

//埃氏筛法
int countPrimes(int n)
{
	if (n < 3) return 0;
	int count(0);
	vector<bool> bin(n, true);
	int upper = sqrt(n);
	for (int i = 2;i <= upper;++i)
	{
		for (int j = i*i;j < n;j += i)
		{
			bin[j] = false;
		}
	}
	for (int i = 2;i < n;++i)
	{
		count += bin[i] ? 1 : 0;
	}
	return count;
}