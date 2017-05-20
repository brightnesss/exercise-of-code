//leetcode No.413 Arithmetic Slices 

/*
 *	A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 *	A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 *	A slice (P, Q) of array A is called arithmetic if the sequence:
 *	A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 *	The function should return the number of arithmetic slices in the array A. 
 */

//暴力解
int numberOfArithmeticSlices(vector<int>& A)
{
	if (A.size() < 3) return 0;
	int ans(0);
	for (int i = 0;i != A.size() - 2;++i)
	{
		double real = A[i] + A[i + 1];
		int count(2);
		int diff = A[i + 1] - A[i];
		double sum;
		for (int j = i + 2;j != A.size();++j)
		{
			++count;
			real += A[j];
			sum = (A[i] + A[j])*count / 2.0;
			if (real == sum)
			{
				++ans;
				continue;
			}
			else break;
		}
	}
	return ans;
}

//动态规划
int numberOfArithmeticSlices(vector<int>& A)
{
	if (A.size() < 3) return 0;
	int ans(0);
	std::vector<int> tmp(A.size(), 0);
	if (A[2] - A[1] == A[1] - A[0]) tmp[2] == 1; //tmp[2]表示以下标2为结尾arithmetic组有多少
	ans += tmp[2];
	for (int i = 3;i != A.size();++i)
	{
		if (A[i] - A[i-1] == A[i-1] - A[i-2])
		{
			//tmp[i]等于tmp[i-1](因为之前的数组加上当前数字A[i]也是arithmetic)再加1(这个1是A[i],A[i-1],A[i-2]这三个数组成的新arithmetic)
			tmp[i] = tmp[i-1] + 1;
		}
		ans += tmp[i]; //所有的相加就是总数
	}
	return ans;
}