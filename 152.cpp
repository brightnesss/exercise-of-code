/*
 *	152. Maximum Product Subarray
 *	Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 *	For example, given the array [2,3,-2,4],
 *	the contiguous subarray [2,3] has the largest product = 6.
 */

/*
 *	因为nums中的都是整数,所以使得subnums中的乘积减小的情况只有2种:
 *	1. 有0,使得乘积直接变为0
 *	2. 有奇数个负数,使得乘积变为负数
 *	注意，如果有偶数个负数,依然会使整个乘积增大

 *	所以我的想法是先用0将nums分为若干段,求出每一段中的最大值,再比较每一段中的最大值,则为极大值

 *	在每一段中:
 *	1. 若该段有偶数个负数,则最大乘积就是该段所有数的乘积
 *	2. 若该段有奇数个负数,则最大乘积是max(从该段的开始到最后一个负数为止的乘积,从该段第一个负数到该段结尾为止的乘积)
 *	所以只需要求出该段第一个负数和最后一个负数的位置,在根据1,2求出该段的乘积即可
 */

int element_product(vector<int>& nums, int begin, int end)
{
	//给出begin和end,求这一段的乘积
	if (begin >= end) return INT_MIN;
	int product(1);
	for (;begin < end;++begin)
	{
		product *= nums[begin];
	}
	return product;
}

int maxProduct(vector<int>& nums)
{
	vector<int> zeros;
	int totalMax;
	for (int i = 0;i != nums.size();++i)
	{
		//求出0的位置
		if (nums[i] == 0) zeros.push_back(i);
	}
	int begin(0), end(nums.size()), curMax;
	if (zeros.empty())
	{
		//若果没有0
		int first(begin), last(begin);
		for (int i = 0;i != nums.size();++i)
		{
			if (nums[i] < 0)
			{
				first = i;
				break;
			}
		}
		for (int i = nums.size() - 1;i >= 0;--i)
		{
			if (nums[i] < 0)
			{
				last = i;
				break;
			}
		}
		totalMax = INT_MIN;
		totalMax = max(totalMax, element_product(nums, 0, nums.size()));	//整段
		totalMax = max(totalMax, element_product(nums, 0, last));	//从开始到最后一个负数为止
		totalMax = max(totalMax, element_product(nums, first + 1, nums.size()));	//从第一个负数到该段末尾为止
		return totalMax;
	}
	else
	{
		//如果存在0
		totalMax = 0;	//最小值至少是0,不会是个负数
		for (int i = 0;i <= zeros.size();++i)
		{
			//求每一段的最大值
			if (i == 0)
			{
				begin = 0;
				end = zeros[i];
			}
			else if (i == zeros.size())
			{
				begin = *zeros.rbegin() + 1;
				end = nums.size();
			}
			else
			{
				begin = zeros[i - 1] + 1;
				end = zeros[i];
			}
			int first(begin), last(begin);
			for (int j = begin;j < end;++j)
			{
				if (nums[j] < 0)
				{
					first = j;
					break;
				}
			}
			for (int j = end - 1;j >= begin;--j)
			{
				if (nums[j] < 0)
				{
					last = j;
					break;
				}
			}
			totalMax = max(totalMax, element_product(nums, begin, end));
			totalMax = max(totalMax, element_product(nums, begin, last));
			totalMax = max(totalMax, element_product(nums, first + 1, end));
		}
		return totalMax;
	}
}


int maxProduct(vector<int>& nums) 
{
    // store the result that is the max we have found so far
    int ans(nums[0]),len(nums.size());

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = ans, imin = ans; i != len; i++) 
    {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (nums[i] < 0) swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);

        // the newly computed max value is a candidate for our global result
        ans = max(ans, imax);
    }
    return ans;
}