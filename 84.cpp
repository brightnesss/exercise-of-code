/*
 *	84. Largest Rectangle in Histogram
 *	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 *	find the area of largest rectangle in the histogram.
 */

//初始想用动态规划,计算任意两个柱子间的最低高度,完毕后再遍历一遍,area=minHeight * (right - left + 1)计算得到面积
//超时

/*
 *	分治法
 *	面积最大只有三种可能：左边，右边和横跨中间的情况
 */

int combineLargestRectangleArea(vector<int>& heights, int s, int m, int e)
{
	//解决横跨中间的情况
	int left(m), right(m + 1); //left(m)是原来左边的右边界,right(m+1)是原来右边的左边界
	int minHeight = min(heights[left], heights[right]);
	int area(0);
	while (left >= s&&right <= e)
	{
		minHeight = min(minHeight,min(heights[left], heights[right]));
		area = max(area, minHeight*(right - left + 1));
		if (left == s) ++right;	//若left已经到头了
		else if (right == e) --left;	//若right已经到头了
		else
		{
			//若两边都没到头
			//向外侧高的那一端移动
			if (heights[left-1] > heights[right+1]) --left;	//注意这里一定要是left-1和right+1比较,left-1比right高,left移动
			else ++right;	//否则right移动
		}
	}
	return area;
}

int sublargestRectangleArea(vector<int>& heights, int s, int e)
{
	//处理左边和右边的情况
	if (s == e) return heights[s];	//如果数组里只剩下一个柱子了，面积就是这个柱子的高度
	int m = s + (e - s) / 2;	//计算中点
	int area = sublargestRectangleArea(heights, s, m);//左边：s->m
	area = max(area, sublargestRectangleArea(heights, m + 1, e)); //右边：m+1->e
	area = max(area, combineLargestRectangleArea(heights, s, m, e)); //中间
	return area;
}

int largestRectangleArea(vector<int>& heights)
{
	if (heights.empty()) return 0;
	int len(heights.size());
	return sublargestRectangleArea(heights, 0, len - 1);
}

/*
 *	利用栈构造升序数组

 *	1、如果已知height数组是升序的，应该怎么做？
 *	比如1,2,5,7,8
 *	那么就是(1*5) vs. (2*4) vs. (5*3) vs. (7*2) vs. (8*1)
 *	也就是max(height[i]*(size-i))

 *	2、使用栈的目的就是构造这样的升序序列，按照以上方法求解。
 *	但是height本身不一定是升序的，应该怎样构建栈？
 *	比如2,1,5,6,2,3

 *		（1）2进栈。s={2}, result = 0
 *		（2）1比2小，不满足升序条件，因此将2弹出，并记录当前结果为2*1=2。
 *			 将2替换为1重新进栈。s={1,1}, result = 2
 *		（3）5比1大，满足升序条件，进栈。s={1,1,5},result = 2
 *		（4）6比5大，满足升序条件，进栈。s={1,1,5,6},result = 2
 *		（5）2比6小，不满足升序条件，因此将6弹出，并记录当前结果为6*1=6。s={1,1,5},result = 6
 *			 2比5小，不满足升序条件，因此将5弹出，并记录当前结果为5*2=10（因为已经弹出的5,6是升序的）。s={1,1},result = 10
 *			 2比1大，将弹出的5,6替换为2重新进栈。s={1,1,2,2,2},result = 10
 *		（6）3比2大，满足升序条件，进栈。s={1,1,2,2,2,3},result = 10
 *			 栈构建完成，满足升序条件，因此按照升序处理办法得到上述的max(height[i]*(size-i))=max{3*1, 2*2, 2*3, 2*4, 1*5, 1*6}=8<10
 *			 综上所述，result=10
 */

int largestRectangleArea(vector<int> &height) 
{
    int area = 0;
    stack<int> stk;
    for(int i = 0; i < height.size(); ++i)
    {
        if(stk.empty() || stk.top() <= height[i])
            stk.push(height[i]);
        else
        {
            int count = 0;
            while(!stk.empty() && stk.top() > height[i])
            {
                count ++;
                area = max(area, stk.top()*count);
                stk.pop();
            }
            while(count--) stk.push(height[i]);
            stk.push(height[i]);
        }
    }
    //此时栈里都是升序的
    //此时也可以通过在height后加一个0,来通过上面的循环就把所有的情况解决了,因为高度最低不会小于1
    int count = 1;	//因为stack是从后往前的,所以count从1开始;若是从前往后,则count应该从height.size()开始往下减,如1中所说
    while(!stk.empty())
    {
        area = max(area, stk.top()*count);
        stk.pop();
        ++count;
    }
    return area;
}

int largestRectangleArea_v2(vector<int>& heights)
{
    stack<int> bin;
    int count(1), area(0), tmp;
    heights.push_back(0);   //加一个0使得通过一次循环就可以解决
    for (int i = 0;i != heights.size();++i)
    {
        tmp = heights[i];
        if (bin.empty() || tmp >= bin.top()) bin.push(tmp);
        else
        {
            while (!bin.empty() && bin.top() > tmp)
            {
                area = max(area, bin.top()*count);
                bin.pop();
                ++count;
            }
            while (count)
            {
                bin.push(tmp);
                --count;
            }
            count = 1;
        }
    }
    heights.pop_back(); //最后把加入的0弹出
    return area;
}