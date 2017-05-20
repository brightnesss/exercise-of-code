//leetcode No.503 Next Greater Element II 

/*
 *	Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number. 
 
 *	Example:
 *	Input: [1,2,1]
 *	Output: [2,-1,2]
 *	Explanation: The first 1's next greater number is 2; 
 *	The number 2 can't find next greater number; 
 *	The second 1's next greater number needs to search circularly, which is also 2.
 */

vector<int> nextGreaterElements(vector<int>& nums, int flag = 2)
{
	map<int, int> intNum;
	vector<bool> hasGreat(nums.size(), false); //下标
	stack<pair<int, int>> bin; //pair<index,value>,因为nums中的数字可能有重复,所以采用它们在数组中的位置来表示
	for (int i = 0;i != 2 * nums.size();++i) //两遍肯定能够完成所有数字的搜索
	{
		int index = i%nums.size();
		while (!bin.empty() && (nums[index] > bin.top().second))
		{
			intNum[bin.top().first] = nums[index];
			hasGreat[bin.top().first] = true;
			bin.pop();
		}
		if (!hasGreat[index]) bin.push(make_pair(index, nums[index])); //如果这个数已经找到它的首个较大数,就不用继续找了
	}
	vector<int> ans;
	for (int index = 0;index != nums.size();++index)
	{
		map<int, int>::iterator it = intNum.find(index);
		ans.push_back(it == intNum.end() ? -1 : it->second); //如果再intNum中没有找到下标,说明这个数是最大的数,没有下一个较大数
	}
	return ans;
}