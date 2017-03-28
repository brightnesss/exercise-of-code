// leetcode No. 136 Single Number

/*
 *	Given an array of integers, every element appears twice except for one. Find that single one.
 *	Note:
 *	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
 */

#include "includelib.h"

int binary2int(const string &s)
{
	//将二进制的bitset通过string类型转换为有符号的int型
	//因为bitset的自身方法只能将其转换为unsigned long类型
 	int ans(0);
	size_t m = s.size() - 1;
	for (size_t pos = m;pos != -1;--pos)
	{
		if (s[pos] == '1')	ans += pow(2, m - pos);
		else continue;
	}
	return ans;
}

int singleNumber(vector<int>& nums)
{
	/*
	 *	通过将所有的数转换为二进制，并利用二进制数的异或方法来完成
	 *	异或是满足交换律的
	 *	所有相同的数经异或后都为0
	 *	0与单独的数异或后为该数的各位取反
	 *	再与0异或后，就可以得到该数。通过令记录初始值为0来完成这一步
	 *	通过计数负数的个数，若负数个数为奇数，则单一数为奇数，否则单一数为偶数
	 *	通过将负数取绝对值转换为整数进行异或，最后通过计数的情况来决定单一数的正负性
	 *	我认为应该是一个O(n)的复杂度，但开了额外的空间
	 */
	if (nums.size() == 1) return *nums.begin();
	else
	{
		bitset<32> single(0);
		int count(0);
		for (vector<int>::iterator intIter = nums.begin();intIter != nums.end();++intIter)
		{
			if (*intIter < 0)
			{
				++count;
				*intIter *= -1;
			}
			bitset<32> temp(*intIter);
			single = single ^= temp;
		}
		int ans(0);
		string temp = single.to_string();
		if (count % 2 == 0) ans = binary2int(temp);
		else ans = -1 * binary2int(temp);
		return ans;
	}
}