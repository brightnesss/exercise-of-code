/*
 *	150. Evaluate Reverse Polish Notation
 *	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *	Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 *	Some examples:
  	["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  	["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

//用一个栈来存储数字就好了,遇到运算符就弹出两个数字进行运算
int evalRPN(vector<string>& tokens)
{
	if (tokens.empty()) return 0;
	stack<int> nums;
	string s;
	int num1, num2;
	for (int i = 0;i != tokens.size();++i)
	{
		s = tokens[i];
		if (s == "+" || s == "-" || s == "*" || s == "/")
		{
			num2 = nums.top();
			nums.pop();
			num1 = nums.top();
			nums.pop();
			if (s == "+") nums.push(num1 + num2);
			else if (s == "-") nums.push(num1 - num2);
			else if (s == "*") nums.push(num1*num2);
			else nums.push(num1 / num2);
		}
		else nums.push(atoi(s.c_str()));
	}
	return nums.top();
}