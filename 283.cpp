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