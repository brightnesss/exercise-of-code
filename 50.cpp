/*
 *	50. Pow(x, n)
 *	Implement pow(x, n).

 *	Example 1:
 *	Input: 2.00000, 10
 *	Output: 1024.00000

 *	Example 2:
 *	Input: 2.10000, 3
 *	Output: 9.26100
 */

double myPow(double x, int n) 
{
    if (n==0) return 1.0;
    int nP=n>0?n:-n;
    double ans;
    if (nP==1) ans=x;
    else if (nP==2) ans=x*x;
    else if (nP%2==0)
    {
        ans=myPow(x*x,nP/2);
    }
    else 
    {
        ans=x*myPow(x*x,(nP-1)/2);
    }
    if (n>0) return ans;
    else
    {
        if (ans==0) return 0.0;
        else return 1.0/ans;
    }
}