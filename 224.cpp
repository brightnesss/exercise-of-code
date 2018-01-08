/*
 *	224. Basic Calculator
 *	Implement a basic calculator to evaluate a simple expression string.
 *	The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 *	You may assume that the given expression is always valid.

 *	Some examples:
	"1 + 1" = 2
	" 2-1 + 2 " = 3
	"(1+(4+5+2)-3)+(6+8)" = 23
 */

/*
 *	一个超级繁琐的逻辑,确实不够好
 *	就是挨个遍历s
 		1)若是+-(这样的符号,压入符号库operater
 		2)若是空格' ',则直接跳过
 		3)若是数字字符,需要一个个找到所有的数字字符组成的数字,压入数字库num
 		4)若是遇到了),则需要开始做计算,直到遇到和他匹配的(,也就是operater中遇到的第一个(
 		  因为在一个括号内,所有的+-运算都是同级运算,需要从左到右进行.但因为目前是用stack存储数据,造成了从右到左的运算顺序,所以需要再在一个括号内进行一次反序
 */
int calculate_224(string s)
{
	stack<char> operater, opertmp;
	stack<int> num, numtmp;
	if (s.empty()) return 0;
	operater.push('(');	//先压入一个(,这就相当于在开始加入一个(,在最后加入一个),将整个计算式子用括号包起来
	char op;
	int begin(0), end(0);
	int num1, num2;
	while (end < s.size())
	{
		if (s[end] == ' ')
		{
			++end;
			continue;
		}
		if (s[end] == '(')
		{
			operater.push('(');
			++end;
		}
		else if (s[end] == '+')
		{
			operater.push('+');
			++end;
		}
		else if (s[end] == '-')
		{
			operater.push('-');
			++end;
		}
		else if (s[end] == ')')	//做运算
		{
			while (true)	//进行反序操作
			{
				op = operater.top();
				operater.pop();
				if (op == '(') break;
				else opertmp.push(op);
			}
			for (int i = 0;i != opertmp.size() + 1;++i)	//操作数总比操作符多一个
			{
				numtmp.push(num.top());
				num.pop();
			}

			while (!opertmp.empty())	//进行计算
			{
				op = opertmp.top();
				opertmp.pop();
				int num1 = numtmp.top();
				numtmp.pop();
				int num2 = numtmp.top();
				numtmp.pop();
				switch (op)
				{
				case '+':
					numtmp.push(num2 + num1);
					break;
				case '-':
					numtmp.push(num2 - num1);
					break;
				default:
					break;
				}
			}
			num.push(numtmp.top());
			numtmp.pop();
			++end;
		}
		else
		{
			int count(1);
			begin = end;
			while (end + 1 < s.size() && s[end + 1] >= '0'&&s[end + 1] <= '9')
			{
				++end;
				++count;
			}
			num.push(atoi(s.substr(begin, count).c_str()));
			++end;
		}
	}
	while (!operater.empty())
	{
		while (true)
		{
			op = operater.top();
			operater.pop();
			if (op == '(') break;
			else opertmp.push(op);
		}
		for (int i = 0;i != opertmp.size() + 1;++i)
		{
			numtmp.push(num.top());
			num.pop();
		}
		while (!opertmp.empty())
		{
			op = opertmp.top();
			opertmp.pop();
			int num1 = numtmp.top();
			numtmp.pop();
			int num2 = numtmp.top();
			numtmp.pop();
			switch (op)
			{
			case '+':
				numtmp.push(num2 + num1);
				break;
			case '-':
				numtmp.push(num2 - num1);
				break;
			default:
				break;
			}
		}
		num.push(numtmp.top());
		numtmp.pop();
	}
	return num.top();
}

/*
 *	一个更适用于本题的做法,因为只有+-这样的同级运算,严格执行从左到右的顺序运算
 *	使用num来记录一个操作数,sign来记录上一个操作符(只有+-,而且是上一个,不是当前的操作符)
 	result来记录一个作用域内的结果(这里的一个作用域通常指同一对括号内)
 *	例如:2+3-5+(4-1)-(2+3)
 */
int calculate_224(string s)
{
	stack<int> ops, nums;
	int num(0), sign(1), result(0);	//上一个操作符默认为+,因为不存在负数,所以第一个数是正数,可以认为是+
	for (char c : s)
	{
		if (isdigit(c)) num = num * 10 + c - '0';	//若是数字字符,则组合为操作数
		else
		{
			//不是操作数,肯定是某种操作符中的一种,则先计算之前的运算,使用上一个操作符
			result += num*sign;	//result是之前的结果,需要对上一个操作符和新的操作数进行运算.如
			num = 0;	//操作数归0
			if (c == ' ') continue;
			else if (c == '+') sign = 1;	//若这个操作符是+,则符号位为1
			else if (c == '-') sign = -1;	//若这个操作符为-,则符号位为-1
			else if (c == '(')
			{
				//若操作符为'(',则保存当前作用域的结果,开启一个新的作用域.然后将result归0,符号位归1
				nums.push(result);
				ops.push(sign);
				result = 0;
				sign = 1;
			}
			else if (c == ')')
			{
				//若是')',说明这个作用域内的运算已经完全结束了,需要复原到上一个作用域,从nums和ops中恢复上一个作用域内的结果,恢复计算
				result = nums.top() + result*ops.top();
				nums.pop();
				ops.pop();
			}
		}
	}
	result += num*sign;	//防止s以一个操作数结尾
	return result;
}