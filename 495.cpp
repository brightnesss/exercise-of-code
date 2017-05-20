//leetcode No.495 Teemo Attacking 

/*
 *	In LLP world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition. 
 *	You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.
 *	Example 1:
 *	Input: [1,4], 2
 *	Output: 4
 *	Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
 *	This poisoned status will last 2 seconds until the end of time point 2. 
 *	And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
 *	So you finally need to output 4.

 *	Example 2:
 *	Input: [1,2], 2
 *	Output: 3
 *	Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
 *	This poisoned status will last 2 seconds until the end of time point 2. 
 *	However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
 *	Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3. 
 *	So you finally need to output 3.
 */

int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
	if (timeSeries.empty()) return 0;
	int begin, end, total(0);	//begin和end分别代表一次连续攻击的开始和结束时间
	begin = timeSeries[0];	//第一次共计开始
	end = begin + duration - 1;	//第一次共计理想的结束时间
	for (int i = 1;i != timeSeries.size();++i)
	{
		if (timeSeries[i] > end)
		{
			//下一次攻击是在上一次共计结束后开始的
			total += end - begin + 1;
			begin = timeSeries[i];
			end = begin + duration - 1;
		}
		else
		{
			//上一次攻击还没结束，下一次就开始了
			end = timeSeries[i] + duration - 1;
		}
	}
	total += end - begin + 1;
	return total;
}