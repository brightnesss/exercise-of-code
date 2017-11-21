/*
 *	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *	You may assume that the intervals were initially sorted according to their start times.

 *	Example 1:
 *	Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 *	Example 2:
 *	Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *	This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */


//由于初始时intervals数组内是有序的,并且一定是互不相交的
//所以相交的情况完全由插入的新的newInterval引入,所以总共只相交一次,即newInterval把所有能相交的数组合并后,之前之后都是独立的不能与newInterval相交的数组
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	int i(0), n(intervals.size());
	vector<Interval> ans;
	while (i < n)
	{
		if (newInterval.end < intervals[i].start) break;	//说明后面的都不会再和newInterval相交了
		else if (newInterval.start > intervals[i].end)
		{
			//说明还没有找到能够相交的,需要继续向后遍历
			ans.push_back(intervals[i]);
			++i;
		}
		else
		{
			//相交,更新newInterval
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
			++i;
		}
	}
	ans.push_back(newInterval);	//将newInterval压入
	for (;i < n;++i) ans.push_back(intervals[i]); //如果i<n,说明后面还有不相交的,压入vector
	return ans;
}