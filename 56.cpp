/*
 *	56. Merge Intervals
 *	Given a collection of intervals, merge all overlapping intervals.

 *	For example,
 *	Given [1,3],[2,6],[8,10],[15,18],
 *	return [1,6],[8,10],[15,18].
 */


// Definition for an interval.
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
 

vector<Interval> merge(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) -> bool {return a.start < b.start ? true : false;});
	int i(0), n(intervals.size());
	vector<Interval> ans;
	while (i < n)
	{
		int start(intervals[i].start), end(intervals[i].end);
		while (i + 1 < n && end >= intervals[i + 1].start)
		{
			end = max(end, intervals[i + 1].end);
			++i;
		}
		++i;
		ans.push_back(Interval(start, end));
	}
	return ans;
}