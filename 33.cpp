/*
 * 	33. Search in Rotated Sorted Array
 * 	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	You are given a target value to search. If found in the array return its index, otherwise return -1.
 *	You may assume no duplicate exists in the array.
 */

/*
 *	从右边开始找,找到所有的违反逆序规则的配对点,在这些配对点中间寻找到最靠右的点(最靠右的点即最小的改变)
 */
void nextPermutation(vector<int>& nums)
{
	int min_index, replace_index(-1), tmp_min_index, tmp_min_num, tmp_replace_index(0);
	bool is_find(false);
	for (int i = nums.size() - 1;i >= 0;--i)
	{
		tmp_min_index = i, tmp_min_num = nums[i];
		for (int j = i - 1; j >= 0;--j)
		{
			if (nums[j] < tmp_min_num)
			{
				tmp_replace_index = j;
				if (tmp_replace_index > replace_index)
				{
					replace_index = tmp_replace_index;
					min_index = tmp_min_index;
				}
				is_find = true;
			}
		}
	}
	if (is_find)
	{
		swap(nums[min_index], nums[replace_index]);
		sort(nums.begin() + replace_index + 1, nums.end(), less<int>());
	}
	else
	{
		sort(nums.begin(), nums.end());
	}
	return;
}



/*
 *	从右边开始,找到违反逆序的连续两个点,即nums[i-1] < nums[i]
 *	则 i-1 肯定是需要交换的
 *	从 i 开始向右找,找到大于nums[i-1]并且最接近nums[i-1]的点 j 
 *	交换nums[i-1]和nums[j]
 */
void nextPermutation_v2(vector<int>& nums)
{
	int replace_index_l(-1), replace_index_r(-1);
	for (int i = nums.size() - 1;i >= 1;--i)
	{
		if (nums[i - 1] < nums[i])
		{
			replace_index_l = i - 1;
			break;
		}
	}
	if (replace_index_l == -1)
	{
		sort(nums.begin(), nums.end());
		return;
	}
	for (int i = replace_index_l + 1;i < nums.size() - 1;++i)
	{
		if (nums[i + 1] <= nums[replace_index_l])
		{
			replace_index_r = i;
			break;
		}
	}
	if (replace_index_r == -1) replace_index_r = nums.size() - 1;
	swap(nums[replace_index_l], nums[replace_index_r]);
	sort(nums.begin() + replace_index_l + 1, nums.end(), less<int>());
	return;
}


/*
 *	1) everytime check if targe == nums[mid], if so, we find it.
 *	2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid]) 
 	and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
 *	3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), 
 	if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
 *	4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), 
 	if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;
 */