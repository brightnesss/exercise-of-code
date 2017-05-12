//leetcode No.526 Beautiful Arrangement 

/*
 *	Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array: 
 *	The number at the ith position is divisible by i.
 *	i is divisible by the number at the ith position.

 *	Now given N, how many beautiful arrangements can you construct? 
 */


/*	对于一个由1~N的组成的共有N位的数
 *	设立一个N位的bool数组，若i位该数组的下标，代表i+1这个数有没有被使用
 *	从后往前计算，若i+1这个数可以放到N这个位置，那就将i设为true，继续遍历N-1的位置...直到N=1，说明这样一种组合是一个beatiful arrangement
 *	再将i设为false，进行其他组合的搜索	
 */

void dfsArrange(vector<bool> &bin, int N, int &ans)
{
	if (N == 1)
	{
		++ans;
		return;
	}
	else
	{
		for (int i = 0;i != bin.size();++i)
		{
			if (!bin[i])
			{
				if ((i + 1) % N == 0 || N % (i + 1) == 0)
				{
					bin[i] = true;
					dfsArrange(bin, N - 1, ans);
					bin[i] = false;
				}
				else continue;
			}
		}
	}
}

int countArrangement(int N)
{
	vector<bool> bin(N, false);
	int ans(0);
	dfsArrange(bin, N, ans);
	return ans;
}