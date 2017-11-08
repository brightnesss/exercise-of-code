/*
 *	4. Median of Two Sorted Arrays
 *	There are two sorted arrays nums1 and nums2 of size m and n respectively.

	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	Example 1:
	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
	Example 2:
	nums1 = [1, 2]
	nums2 = [3, 4]

	The median is (2 + 3)/2 = 2.5
 */

/*
 *	将nums1和nums2分为两部分，左边部分和右边部分,使得:
 *	1.左边部分的长度=右边部分的长度
 *	2.左边部分的最大值(最右边的数)<右边部分的最小值(最左边的数)

 *	假设nums1从i处划分开,nums2从j处划分开,则
 *	总长度为奇数时:
 *	1. i + j = m - i + n - j + 1
 *	2. nums1[i-1] < nums2[j] && nums2[j-1] < nums1[i]

 *	总长度为偶数时:
 *	1. i + j = m - i + n - j
 *	2. nums1[i-1] < nums2[j] && nums2[j-1] < nums1[i]
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len = nums1.size() + nums2.size();
	if (nums1.size() > nums2.size()) swap(nums1, nums2); //len(nums2) >= len(nums1)
	int begin(0), end(nums1.size()), i(0), j(0);
	const int m(end), n(nums2.size());
	if (len % 2 == 0)
	{
		while (begin <= end)
		{
			i = (begin + end) / 2;
			j = len / 2 - i;
			if (i > 0 && nums1[i - 1] > nums2[j]) end = i - 1;
			else if (i<m && nums2[j - 1]>nums1[i]) begin = i + 1;
			else
			{
				double maxLeft, minRight;
				if (i == 0) maxLeft = nums2[j - 1];
				else if (j == 0) maxLeft = nums1[i - 1];
				else maxLeft = max(nums1[i - 1], nums2[j - 1]);

				if (i == m) minRight = nums2[j];
				else if (j == n) minRight = nums1[i];
				else minRight = min(nums1[i], nums2[j]);
				return (maxLeft + minRight) / 2.0;
			}
		}
	}
	else
	{
		while (begin <= end)
		{
			i = (begin + end) / 2;
			j = (len + 1) / 2 - i;
			if (i > 0 && nums1[i - 1] > nums2[j]) end = i - 1;
			else if (i<m && nums2[j - 1]>nums1[i]) begin = i + 1;
			else
			{
				if (i == 0) return nums2[j - 1] / 1.0;
				else if (j == 0) return nums1[i - 1] / 1.0;
				else return (max(nums1[i - 1], nums2[j - 1])) / 1.0;	//因为左边长度长，所以总长度为奇数时中间值是左边的最大值
			}
		}
	}
}