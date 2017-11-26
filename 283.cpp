// leetcode No.283 Move Zeroes

#include "inlcudelib.h"

//把所有的零先删掉，再在后面加上

void moveZeroes(vector<int>& nums)
{
	vector<int>::iterator intIter = nums.begin();
	int count(0);
	while (intIter != nums.end())
	{
		if (*intIter == 0)
		{
			if (intIter == nums.begin())
			{
				nums.erase(intIter, intIter + 1);
				intIter = nums.begin();
			}
			else
			{
				vector<int>::iterator pos = intIter - 1;
				nums.erase(intIter, intIter + 1);
				intIter = pos;
			}
			++count;
		}
		else
		{
			++intIter;
		}
	}
	while (count != 0)
	{
		nums.push_back(0);
		--count;
	}
}

/*
 *	用一个数组记下当前位置之前有多少个0
 *	则对于nums中每一个不为0的数,都只需要向前移动zeros[i]个位置就可以到达最终位置
 *	最后用0把位置补上
 */
void moveZeroes(vector<int>& nums)
{
	vector<int> zeros(nums.size());
	zeros[0] = nums[0] == 0 ? 1 : 0;
	for (int i = 1;i < nums.size();++i)
	{
		if (nums[i] == 0) zeros[i] = zeros[i - 1] + 1;
		else zeros[i] = zeros[i - 1];
	}
	int num = *zeros.rbegin();
	for (int i = 0;i != nums.size();++i)
	{
		if (nums[i] != 0) nums[i - zeros[i]] = nums[i];
	}
	for (auto it = nums.rbegin();num > 0;++it,--num)
	{
		*it = 0;
	}
}