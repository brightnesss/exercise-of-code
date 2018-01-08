/*
 *	227. Basic Calculator II
 *	Implement a basic calculator to evaluate a simple expression string.
 *	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 *	You may assume that the given expression is always valid.

 *	Some examples:
	"3+2*2" = 7
	" 3/2 " = 1
	" 3+5 / 2 " = 5
 *	Note: Do not use the eval built-in library function.
 */

/*
 *	又是一个超级繁琐的方法,但很顺利的通过了
 *	从左到右顺序执行,第一遍先进行乘除法的计算,第二遍进行加减法计算
 	如果遇到加减法,就压入栈中,等待第二遍执行
 	如果遇到乘除法,就继续往后找第二个操作数,进行计算
 	最后,乘除法全部计算完毕后,进行加减法的顺序计算
 */
int calculate_227(string s)
{
	stack<int> nums;
	stack<char> ops;
	int end(0), num(-1), len(s.size());	//num=-1用来标记num此时不是个数
	while (end < len)
	{
		if (s[end] == ' ') ++end;
		else if (isdigit(s[end]))
		{
			if (num == -1) num = s[end] - '0';
			else num = num * 10 + s[end] - '0';
			++end;
		}
		else
		{
			if (s[end] == '+' || s[end] == '-')	//遇到加减法,压入栈中等待计算
			{
				nums.push(num);
				num = -1;
				ops.push(s[end]);
				++end;
			}
			else if (s[end] == '*' || s[end] == '/')	//遇到乘除法,继续向后找第二个操作数,立刻计算
			{
				nums.push(num);
				num = 0;
				ops.push(s[end]);
				++end;
				while (end < len)
				{
					if (s[end] == ' ') ++end;
					else if (isdigit(s[end]))
					{
						num = num * 10 + s[end] - '0';
						++end;
					}
					else break;
				}
				switch (ops.top())
				{
				case '*':
					num = nums.top()*num;
					break;
				case '/':
					num = nums.top() / num;
					break;
				default:
					break;
				}
				nums.pop();
				ops.pop();
			}
		}
	}
	if (num != -1) nums.push(num);	//防止以一个数结尾
	stack<int> reversnums;
	stack<int> reversops;	//顺序计算加减法(即需要反序)
	while (!nums.empty())
	{
		reversnums.push(nums.top());
		nums.pop();
	}
	while (!ops.empty())
	{
		reversops.push(ops.top());
		ops.pop();
	}
	while (!reversops.empty())
	{
		int num1 = reversnums.top();
		reversnums.pop();
		int num2 = reversnums.top();
		reversnums.pop();
		switch (reversops.top())
		{
		case '+':
			reversnums.push(num1 + num2);
			break;
		case '-':
			reversnums.push(num1 - num2);
			break;
		default:
			break;
		}
		reversops.pop();
	}
	return reversnums.top();

	/*
	 *	看discuss发现,完成加减法的顺序操作不需要进行反序
	 *	只需要把所有的操作当作加法,若有减法,将减号后面的数当作负数即可
	 *	前提是需要提前在ops中压入一个'+',当作第一个数的符号
	 *	以下的假设ops中提前压入了一个'+'
	 	ops.push('+');
	 	...
	 	...
	 	...
	 	int ans(0);
    	while(!ops.empty())
    	{
			ans+=ops.top()=='+'?nums.top():-nums.top();
			nums.pop();
			ops.pop();
		}
		return ans;
	 */
}

//这个是discuss中完成了包含加减乘除和括号的计算器,但是所有操作数还必须是正数
int calculate(string s) {
   stack<char> opS;
   stack<int>  numS;
   s = '(' + s + ')';

   int i, curNum = 0, len = s.size();
   for(i=0; i<len; ++i)
   {
       if(isdigit(s[i])) curNum = curNum*10 + s[i] -'0';
       else if(isspace(s[i])) continue;
       else if(s[i] == '(')
       {
            opS.push('(');
            opS.push('+');
       }
       else
       {
            switch(opS.top())
            {
                case '*':
                case '/':
                    curNum = opS.top()=='/'?numS.top()/curNum : numS.top()*curNum;
                    opS.pop();
                    numS.pop();
            }
            switch(s[i])
            {
                case ')':
                    if('-'== opS.top()) curNum = -curNum;
                   opS.pop();

                   while(opS.top()!='(') 
                   {
                       curNum += (opS.top()=='-')? -numS.top(): numS.top(); 
                       opS.pop(); 
                       numS.pop();
                   }
                   opS.pop(); // skip '('
                   break;
                default: //+,-,*,/
                    opS.push(s[i]);
                    numS.push(curNum);
                    curNum = 0;
            }
       }
   }
   return curNum;
}