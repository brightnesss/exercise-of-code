/*
 *	149. Max Points on a Line
 *	Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

/*
 *	时间复杂度O(n2)
 *	但这个算法并步能通过测试,因为对于按照斜率存储的rate来说,有时候会发生截断误差,使得并不在同一直线上的点被误判为在同一直线
 	可以通过另一种方式来存储斜率,比如使用 unordered_map<pair<int,int>,int> rate,其中的pair<int,int>来存储斜率的dx和dy
 */

int maxPoints(vector<Point>& points)
{
	int ans(0), len(points.size()), localresult(0), samePoint(0);
	unordered_map<double, int> rate;
	double slope;
	for (int i = 0;i < len;++i)
	{
		localresult = 0;
		samePoint = 1;
		rate.clear();
		for (int j = i + 1;j < len;++j)
		{
			if (points[i].x == points[j].x&&points[i].y == points[j].y) ++samePoint;
			else if (points[i].x == points[j].x) ++rate[INT_MAX];
			else
			{
				slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
				++rate[slope];
			}
		}
		for (auto item : rate) localresult = max(localresult, item.second);
		ans = max(ans, localresult + samePoint);
	}
	return ans;
}