/*
 *	134. Gas Station
 *	There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
 	You begin the journey with an empty tank at one of the gas stations.
 *	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

 *	Note:
 *	The solution is guaranteed to be unique.
 */

/*
 *	暴力搜索,复杂度O(n2),超时
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	if (gas.size() != cost.size()) return -1;
	if (gas.empty()) return -1;
	int len(gas.size());
	for (int i = 0;i != len;++i)
	{
		int k(i);
		bool finish(true);
		int rest(0);
		for (int num = 0;num != len;++num)
		{
			rest = rest + gas[k] - cost[k];
			if (rest < 0)
			{
				finish = false;
				break;
			}
			else
			{
				k = (k + 1) % len;
			}
		}
		if (finish) return i;
		else continue;
	}
	return -1;
}

/*
 *	两点法,分别用begin,end来记录当前遍历的其实位置和目前位置
 *	若end能够走一圈回到begin,说明从begin开始能够成功走一圈,返回begin
 	若begin走了一圈回到了最初的出发位置0,则说明不存在一个其实位置begin,使得能够成功走一圈
 *	更新方法如下:
 		1)首先计算从end到end+1的油料情况,rest=rest+gas[end%len]-cost[end%len],++end;
 		2)若rest<0,说明从begin开始没法走到end,这时需要移动begin的位置,但注意,begin<=end,不能使得begin的位置在end之后
 		  因为后移了begin,所以begin位置的油料补给和消耗都没有了,需要恢复rest=rest-gas[begin%len]+cost[begin%len],++begin
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	if (gas.size() != cost.size()) return -1;
	if (gas.empty()) return -1;
	int len(gas.size()), begin(0), end(0), rest(0);
	while (end - begin != len && begin < len)	//end-begin==len说明end走了一圈,成功;begin>=len说明不存在这样的起始位置使得能够遍历一周,失败
	{
		rest = rest + gas[end%len] - cost[end%len];
		++end;
		while (rest < 0 && begin < end)
		{
			rest = rest - gas[begin%len] + cost[begin%len];
			++begin;
		}
	}
	if (begin >= len) return -1;
	else return begin;
}