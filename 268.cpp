/*
 *	268. Missing Number
 *	Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

 *	For example,
 *	Given nums = [0, 1, 3] return 2.

 *	Note:
 *	Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

//利用等差数列求和公式
int missingNumber(vector<int>& nums)
{
	int minElement(INT_MAX),maxElement(0), sum(0);
	for (int num : nums)
	{
		sum += num;
		if (num > maxElement) maxElement = num;
		else if (num < minElement) minElement = num;
	}
	int idealSum = (0 + maxElement)*(maxElement + 1) / 2;
	if (idealSum - sum == 0)
	{
		if (minElement == 0) return maxElement + 1;
		else return minElement-1;
	}
	else return idealSum - sum;
}