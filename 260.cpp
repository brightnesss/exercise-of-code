//leetcode No.260 Single Number III 

/*
 *	Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
 *	For example: 
 *	Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 
 *	Note:
 *	1. The order of the result is not important. So in the above example, [5, 3] is also correct.
 *	2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

vector<int> singleNumber(vector<int>& nums, int version = 3)
{
	//设两个只出现一次的数分别为a,b
	vector<int> ans;
	if (nums.size() < 1) return ans;
	else if (nums.size() < 3) return nums;
	int num(0); 
	for (auto i : nums) num ^= i;	//先求出所有数的异或,得到的结果是a^b
	int count(0);
	while (!(num & 1))
	{
		//求出a^b中最右边的1的位置,最右边的1的位置是a和b第一次出现不同的位置,可以用以区分a和b
		++count;
		num >>= 1;
	}
	count = 1 << count;	//求出是第几位后,将count变为该位为1,其余为皆为0的数
	int ans1(0), ans2(0);
	for (int i : nums)
	{
		if (i&count) ans1 ^= i; //如果i该位为1,那就是a
		else ans2 ^= i; //若该位不为1,则为b
	}
	ans = { ans1,ans2 };
	return ans;
}

//时间复杂度O(n),空间复杂度O(n/2)
vector<int> singleNumber(vector<int>& nums) 
{
    vector<int> ans;
    if (nums.empty()) return ans;
    unordered_set<int> uset;
    for (int num:nums)
    {
        if (uset.find(num)!=uset.end()) uset.erase(num);
        else uset.insert(num);
    }
    for (int num:uset) ans.push_back(num);
    return ans;
}