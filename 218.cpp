/*
 *	218. The Skyline Problem
 *	A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
 	Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), 
 	write a program to output the skyline formed by these buildings collectively (Figure B).
 *	The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
 	where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
 	and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
 	You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

 *	For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
	The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
	A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, 
	is merely used to mark the termination of the skyline, and always has zero height. 
	Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

 *	For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

 *	Notes:
	The number of buildings in any input list is guaranteed to be in the range [0, 10000].
	The input list is already sorted in ascending order by the left x position Li.
	The output list must be sorted by the x position.
	There must be no consecutive horizontal lines of equal height in the output skyline. 
	For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
	the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
 */

//详细的解释参考https://briangordon.github.io/2014/08/the-skyline-problem.html

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
{
	vector<pair<int, int>> height;
	for (auto item : buildings)
	{
		//对于每一个建筑物,对其起始位置,标记高度为-;终止位置,标记高度为+(这很重要,在后面的排序总会有影响)
		height.push_back(make_pair(item[0], -item[2]));
		height.push_back(make_pair(item[1], item[2]));
	}
	sort(height.begin(), height.end());	//进行排序,主要是按照x的顺序进行,若x的位置相同(即在一点上有建筑物结束,也有建筑物开始)的地方,建筑物开始的在前(因为高度为-)
	multiset<int> mset;	//用来表示截至到当前x,所有的建筑物的高度
	int prev(0), cur;	//prev表示之前一个关键点的高度,cur表示当下关键点的高度
	vector<pair<int, int>> ans;
	mset.emplace(0);
	for (auto h : height)
	{
		if (h.second < 0) mset.emplace(-h.second);	//若是负的,说明建筑物开始,插入其高度
		else mset.erase(mset.find(h.second));	//若是正的,说明建筑物结束,删除其高度
		cur = *mset.rbegin();	//得到当下最高的建筑物
		if (cur == prev) continue;	//若相同,说明当前的关键点并不是答案中的一个
		else
		{
			prev = cur;	//更新prev
			ans.push_back(make_pair(h.first, cur));	//插入关键点
		}
	}
	return ans;
}