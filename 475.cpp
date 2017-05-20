//leetcode No.475 Heaters

/*
 *	Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
 *	Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
 *	So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
 *	Note:
 *	Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
 *	Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
 *	As long as a house is in the heaters' warm radius range, it can be warmed.
 *	All the heaters follow your radius standard and the warm radius will the same.

 *	Example 1:
 *	Input: [1,2,3],[2]
 *	Output: 1
 *	Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

 *	Example 2:
 *	Input: [1,2,3,4],[1,4]
 *	Output: 1
 *	Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
 */




/*
 *	先排序，之后的算法都基于两个数组是有序的情况下
 *	对于houses中的每一个坐标，都从heaters中去寻找其距离最近的，计算他们的半径，并于最大半径ans进行比较，取其中较大者
 *	关键在于不能从heaters的开头比较到末尾，否则效率会很低
 *	设一个index，记录houses中上一个元素离heaters中哪一个元素最近，index为heaters中最近的元素下标
 *	之后的元素都从index开始比较，因为数组是有序的，保证了算法的收敛
 *	比较的过程中，若遇到半径大于当前最小半径minlen，可以直接退出，因为之后的也一定大于minlen
 */


int findRadius(vector<int>& houses, vector<int>& heaters)
{
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());
	size_t h(0), index(0);
	int ans(0);
	for (;h != houses.size();++h)
	{
		int minlen = INT_MAX;
		for (size_t hea = index;hea != heaters.size();++hea)
		{
			if (abs(houses[h] - heaters[hea]) < minlen)
			{
				index = hea;
				minlen = abs(houses[h] - heaters[hea]);
			}
			else if (abs(houses[h] - heaters[hea]) > minlen) break;
		}
		ans = max(ans, minlen);
	}
	return ans;
}