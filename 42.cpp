/*
 *	42. Trapping Rain Water
 *	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 *	For example, 
 *	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

/*
 *	先找到开始的点,即第一个高度大于0的点beginIndex
 *	从beginIndex开始向后数,找到第一个高度大于它的柱子:endIndex
 *	若endIndex不存在,则找到高度最接近beginIndex且位置靠后的点tmpIndex
 *	统计从beginIndex到endIndex(或tmpIndex)之间的存水量
 */
int trap(vector<int>& height)
{
	int ans(0), beginIndex(0), endIndex(0), tmpNum(INT_MIN), tmpIndex(0);
	//找到第一个beginIndex
	for (int i = 0;i != height.size();++i)
	{
		if (height[i] > 0)
		{
			beginIndex = i;
			break;
		}
	}
	while (beginIndex + 1 < height.size())
	{
		tmpNum = INT_MIN, tmpIndex = 0;
		endIndex = 0;
		for (int i = beginIndex + 1;i < height.size();++i)
		{
			//若找到了endIndex,直接跳出循环,开始计算存水量
			if (height[i] >= height[beginIndex])
			{
				endIndex = i;
				break;
			}
			if (height[i] >= tmpNum)	//>=保证了找到最靠后的tmpNum
			{
				tmpNum = height[i];
				tmpIndex = i;
			}
		}
		//若endIndex不存在
		if (endIndex == 0)
		{
			int minHeight = min(height[beginIndex], height[tmpIndex]);
			for (int i = beginIndex;i < tmpIndex;++i)
			{
				ans += (minHeight - height[i]) > 0 ? (minHeight - height[i]) : 0;
			}
			beginIndex = tmpIndex;	//更新beginIndex
		}
		//若endIndex存在
		else
		{
			int minHeight = min(height[beginIndex], height[endIndex]);
			for (int i = beginIndex;i < endIndex;++i)
			{
				ans += (minHeight - height[i]);
			}
			beginIndex = endIndex;	//更新beginIndex
		}
	}
	return ans;
}

/*
 *	两点法
 *	使用leftMax和rightMax分别记录当前从左数和从右数最高的柱子
 *	只要被这两个柱子夹住的区域是肯定可以存水的
 *	用left和right分别记录当前从左边和右边遍历到的柱子
 *	总是对低的一边进行更新
 *	O(n)
 */
int trap_v2(vector<int>& height)
{
	int left(0), right(height.size() - 1), leftMax(0), rightMax(0), ans(0);
	while (left < right)	//当left<right时才行
	{
		if (height[left] < height[right])	//若左边比右边低,该对左边进行更新
		{
			if (height[left] > leftMax) leftMax = height[left];
			else
			{
				ans += leftMax - height[left];
				++left;
			}
		}
		else	//若左边比右边高,该更新右边
		{
			if (height[right] > rightMax) rightMax = height[right];
			else
			{
				ans += rightMax - height[right];
				--right;
			}
		}
	}
	return ans;
}