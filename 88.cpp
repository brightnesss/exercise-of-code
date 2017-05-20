//leetcode No.88 Merge Sorted Array 

/*
 *	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *	Note:
 *	You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
 *	The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	nums1.reserve(m + n);
	int i(m - 1), j(n - 1), pos(m + n - 1);
	while (i > -1 && j > -1)
	{
		if (nums1[i] < nums2[j])
		{
			nums1[pos] = nums2[j];
			--j;
		}
		else
		{
			nums1[pos] = nums1[i];
			--i;
		}
		--pos;
	}
	//如果是nums2先结束，则剩下的nums1不用再排列了，它们已经是有序的
	while (j > -1)
	{
		//只有nums1先结束时，需要对nums2进行处理
		nums1[pos] = nums2[j];
		--j;
		--pos;
	}
}