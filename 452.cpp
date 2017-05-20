//leetcode No.452 Minimum Number of Arrows to Burst Balloons 

/*
 *	There are a number of spherical balloons spread in two-dimensional space.
 *	For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
 *	Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
 *	Start is always smaller than end. There will be at most 104 balloons.
 *	An arrow can be shot up exactly vertically from different points along the x-axis. 
 *	A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. 
 *	An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons. 

 *	Example: 
 *	Input:
 *	[[10,16], [2,8], [1,6], [7,12]]

 *	Output:
 *	2

 *	Explanation:
 *	One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
 */

int findMinArrowShots(vector<pair<int, int>>& points) 
{
	//如果两个气球有重叠,则可以一起扎破
	//如果有重叠,计算它们的重叠区域,并保存,之后用这个重叠区域与其他气球再比较
	sort(points.begin(), points.end());
    vector<pair<int, int>> bin;
	for (int i = 0;i != points.size();++i)
	{
		if (i == 0) bin.push_back(points[i]);
		else
		{
			bool isfind(false);
			for (int j = 0;j != bin.size();++j)
			{
				if (points[i].first > bin[j].second || bin[j].first > points[i].second) continue;
				else
				{
					bin[j].first = max(bin[j].first, points[i].first);
					bin[j].second = min(bin[j].second, points[i].second);
					isfind = true;
				}
			}
			if (!isfind) bin.push_back(points[i]);
		}
	}
	return bin.size();
}

//同样的思路,用贪心法
//只记录一个重叠区域的末尾
//若points[i]与之前的末尾有交集,则可以一起扎破,再更新末尾
//若没有交集,则定义新的末尾为points[i]的末尾
int findMinArrowShots(vector<pair<int, int>>& points)
{
	if (points.empty()) return 0;
	sort(points.begin(), points.end());
	int ans(1); //最少需要一针扎破
	int end = points[0].second; //初始的末尾为points[0].second
	for (int i = 1;i != points.size();++i)
	{
		if (points[i].first > end)
		{
			//若没有交集
			++ans; 
			end = points[i].second; //定义新的末尾
		}
		else end = min(end, points[i].second); //否则更新末尾
	}
	return ans;
}