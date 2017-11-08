/*
 *	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 *	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 *	Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *	Note: You may not slant the container and n is at least 2.
 */

//algorithm1: Brute Force : Accept
//暴力搜索加一些trick...

int maxArea(vector<int>& height)
{
	const int m(height.size());
	int max_area(0);
	for (int i = 1;i != m;++i)
	{
		int tmp(0);
		for (int j = 0;j < i;++j)
		{
			if (height[i] * (i - j) < max_area) break;
			if (height[j] >= height[i])
			{
				tmp = max(height[i] * (i - j), tmp);
				break;
			}
			else
			{
				tmp = max(height[j] * (i - j), tmp);
			}
		}
		max_area = max(max_area, tmp);
	}
	return max_area;
}

//algorithm2 : Two pointer
/*
 *	The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line. 
 *	Further, the farther the lines, the more will be the area obtained.

 *	We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. 
 *	Futher, we maintain a variable maxareamaxarea to store the maximum area obtained till now. At every step, we find out the area formed between them, update maxareamaxarea and move the pointer pointing to the shorter line towards the other end by one step.
 *	面积是由两端中较矮的那一端限制的
 *	长度越长,面积越大
 *	从数组的两端开始搜索,然后两端中较矮的那一端开始移动
 */

int maxArea_v2(vector<int>& height)
{
	int begin(0), end(height.size() - 1);
	int max_area(0);
	while (begin < end)
	{
		if (height[begin] < height[end])
		{
			max_area = max(max_area, height[begin] * (end - begin));
			++begin;
		}
		else
		{
			max_area = max(max_area, height[end] * (end - begin));
			--end;
		}
 	}
	return max_area;
}