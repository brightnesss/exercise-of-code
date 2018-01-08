/*
 *	135. Candy
 *	There are N children standing in a line. Each child is assigned a rating value.
 *	You are giving candies to these children subjected to the following requirements:
		Each child must have at least one candy.
		Children with a higher rating get more candies than their neighbors.
 *	What is the minimum candies you must give?
 */

/*
 *	1.每个孩子都要至少有一个
 	2.每个排分高的比邻居多就好了(并不一定要全局小,只是局部小就可以),因为求最少的糖果,所以只需要多一个就好了

 *	Example: ratings=[4,2,3,4,1]
 	则每个孩子对应拿到的糖果数为[2,1,2,3,1]

 *	这样肯定是按照rating的高低,先给rating低的孩子分配糖果,再给rating高的分配,给每个人分配几个,取决于它邻居的糖果数
 	1)首先给rating排序,因为还需要邻居的位置,所以需要记录邻居的位置,所以使用pair来排序
 	2)排序后开始遍历,分别按rating的从低到高的顺序
 		若这个孩子的rating比邻居的某一个或两个高,则求邻居的最大糖果数,这个孩子的糖果就是最大糖果数+1
 		若这个孩子的rating比邻居都低,那它拿一个糖果就行了,即使他的rating可能并不是1或最小的
 */
int candy(vector<int>& ratings)
{
	int len(ratings.size()), index;
	vector<int> vec(len, 1);
	vector<pair<int, int>> vecP;
	for (int i = 0;i != len;++i) vecP.push_back(make_pair(ratings[i], i));	//first是rating,second是真正的位置
	sort(vecP.begin(), vecP.end());
	for (int i = 0;i != len;++i)
	{
		index = vecP[i].second;
		int maxNum(0);
		if (index - 1 >= 0 && ratings[index] > ratings[index - 1]) maxNum = max(maxNum, vec[index - 1]);
		if (index + 1 < len&&ratings[index] > ratings[index + 1]) maxNum = max(maxNum, vec[index + 1]);
		if (maxNum == 0) continue;	//比邻居都小,跳过
		else vec[index] = maxNum + 1;	//最大值+1
	}
	return accumulate(vec.begin(), vec.end(), 0);
}