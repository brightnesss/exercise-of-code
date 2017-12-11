/*
 *	69. Sqrt(x)
 *	Implement int sqrt(int x).
 *	Compute and return the square root of x.
 *	x is guaranteed to be a non-negative integer.

 *	Example 1:
 *	Input: 4
 *	Output: 2

 *	Example 2:
 *	Input: 8
 *	Output: 2
 *	Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
 */

int mySqrt(int x) 
{
    if (x==0 || x==1) return x;
    int begin(1),end(x/2),mid;
    while(begin<end)
    {
        mid=begin+(end-begin)/2;
        if (mid>x/mid) end=mid-1;	//通过将mid*mid>x变为mid>x/mid,可以消除越界错误
        else
        {
            if ((mid+1)>x/(mid+1)) return mid;
            else begin=mid+1;
        }
    }
    return begin;
}