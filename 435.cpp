//leetcode No.435 Non-overlapping Intervals

/*
 *	Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 *	Note:
 *	You may assume the interval's end point is always bigger than its start point.
 *	Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

 *	Example 1:
 *	Input: [ [1,2], [2,3], [3,4], [1,3] ]

 *	Output: 1

 *	Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

 *	Example 2:
 *	Input: [ [1,2], [1,2], [1,2] ]

 *	Output: 2

 *	Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

 *	Example 3:
 *	Input: [ [1,2], [2,3] ]

 *	Output: 0

 *	Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 */


/*
 *	若当前currend大于start,则认为两个重叠,ans+1,同时为了达到remove数量最小,取最小的end为currend
 *	否则,不重叠时,更新currend为目前Interval的end
 */
int eraseOverlapIntervals(vector<Interval>& intervals)
{
	if (intervals.empty()) return 0;
	sort(intervals.begin(), intervals.end(), [](Interval first, Interval second) {return first.start == second.start ? first.end >= second.end : first.start < second.start;});
	int ans(0);
	int currend = intervals[0].end;
	for (int i = 1;i != intervals.size();++i)
	{
		if (intervals[i].start < currend)
		{
			++ans;
			currend = min(end, intervals[i].end);
		}
		else
		{
			currend = intervals[i].end;
		}
	}
	return ans;
}