//leetcode No.350. Intersection of Two Arrays II 

/*
 *	Given two arrays, write a function to compute their intersection. 
 *	Example:
 *	Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2]. 
 *	Note:
 *	Each element in the result should appear as many times as it shows in both arrays.
 *	The result can be in any order.
 *	
 *	Follow up:
 *	What if the given array is already sorted? How would you optimize your algorithm?
 *	What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *	What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */

//使用map来计数
//时间复杂度是O(max(nums1.size(),nums2.size()))
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> bin;
	for (int i = 0;i != nums1.size();++i) ++bin[nums1[i]];
	vector<int> ans;
	for (int i = 0;i != nums2.size();++i)
	{
		if (bin[nums2[i]] > 0)
		{
			--bin[nums2[i]];
			ans.push_back(nums2[i]);
		}
		else continue;
	}
	return ans;
}

//若nums1和nums2已经有序，可以直接比较(假设是增序)
//时间复杂度是O(min(nums1.size(),nums2.size()))
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
	vector<int> ans;
	while (it1 != nums1.end() && it2 != nums2.end())
	{
		if (*it1 < *it2) ++it1;
		else if (*it1 > *it2) ++it2;
		else
		{
			ans.push_back(*it1);
			++it1;
			++it2;
		}
	}
	return ans;
}

//若nums1的长度远小于nums2，肯定第二种要好一点