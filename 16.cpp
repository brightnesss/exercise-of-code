/*
 *	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 *	Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *	For example, given array S = {-1 2 1 -4}, and target = 1.
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */


/*
 *	和15题类似,只是相等改成了接近,需要判断一个接近度diff
 */
int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	const int end(nums.size());
	int a(0), b(0), t(0), diff(INT_MAX), ans;
	for (int i = 0;i != end;++i)
	{
		a = i + 1;
		b = end - 1;
		t = target - nums[i];
		while (a < b)
		{
			if (nums[a] + nums[b] < t)
			{
				if (abs(t - nums[a] - nums[b]) < diff)
				{
					diff = abs(t - nums[a] - nums[b]);
					ans = nums[i] + nums[a] + nums[b];
				}
				++a;
			}
			else if (nums[a] + nums[b] > t)
			{
				if (abs(t - nums[a] - nums[b]) < diff)
				{
					diff = abs(t - nums[a] - nums[b]);
					ans = nums[i] + nums[a] + nums[b];
				}
				--b;
			}
			else
			{
				return target;
			}
		}
	}
	return ans;
}