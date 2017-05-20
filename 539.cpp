//leetcode No.539 Minimum Time Difference 

/*
 *	Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
 *	Example 1:
 *	Input: ["23:59","00:00"]
 *	Output: 1
 */

int findMinDifference(vector<string>& timePoints)
{
	if (timePoints.size() < 2) return 0;
	sort(timePoints.begin(), timePoints.end());
	int ans(1440);
	string time0 = timePoints[timePoints.size() - 1];
	int tim0 = 600 * (time0[0] - '0') + 60 * (time0[1] - '0') + 10 * (time0[3] - '0') + time0[4] - '0';
	for (int i = 0;i != timePoints.size() - 1;++i)
	{
		string time1 = timePoints[i], time2 = timePoints[i + 1];
		int tim1 = 600 * (time1[0] - '0') + 60 * (time1[1] - '0') + 10 * (time1[3] - '0') + time1[4] - '0';
		int tim2 = 600 * (time2[0] - '0') + 60 * (time2[1] - '0') + 10 * (time2[3] - '0') + time2[4] - '0';
		int tmp1 = min(abs(tim1 - tim2), 1440 - abs(tim1 - tim2));
		int tmp2 = min(abs(tim1 - tim0), 1440 - abs(tim1 - tim0));
		int tmp3 = min(tmp1, tmp2);
		ans = ans < tmp3 ? ans : tmp3;
	}
	return ans;
}