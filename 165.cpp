/*
 *	165. Compare Version Numbers
 *	Compare two version numbers version1 and version2.
 *	If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 *	You may assume that the version strings are non-empty and contain only digits and the . character.
 *	The . character does not represent a decimal point and is used to separate number sequences.
 *	For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

 *	Here is an example of version numbers ordering:
	0.1 < 1.1 < 1.2 < 13.37
 */

/*
 *	因为会出现"01"和"1"这种测试样例,所以直接比较字符串是不行的
 *	前面的比较都好说,就是按照'.'分割字符串,将数字转为int型进行比较
 *	若version1和version2有一个或者两个都到了末尾,这种情况就比较复杂了
 		1)都到了末尾,说明相等,直接返回0即可
 		2)有一方到了末尾,这个就比较麻烦,因为会出现"1"和"1.0"这种测试样例以及"1"和"1.0.1"这种测试样例
 		所以只能对之后的字符串进行比较,若除了'0'就是'.',说明它们还是相等的,否则是不相等的
 */
int compareVersion(string version1, string version2)
{
	int begin1(0), end1(0), begin2(0), end2(0);
	int num1, num2;
	while (end1 != string::npos&&end2 != string::npos)
	{
		end1 = version1.find_first_of('.', begin1);
		end2 = version2.find_first_of('.', begin2);
		num1 = atoi(version1.substr(begin1, end1 - begin1).c_str());
		num2 = atoi(version2.substr(begin2, end2 - begin2).c_str());
		if (num1 < num2) return -1;
		else if (num1 > num2) return 1;
		begin1 = version1.find_first_not_of('.', end1);
		begin2 = version2.find_first_not_of('.', end2);
	}
	if (end1 == string::npos&&end2 == string::npos) return 0;
	else if (end1 == string::npos)
	{
		version2 = version2.substr(begin2);
		bool allzero(true);
		for (char c : version2)
		{
			if (c == '0' || c == '.') continue;
			else
			{
				allzero = false;
				break;
			}
		}
		if (allzero) return 0;
		else return -1;
	}
	else
	{
		version1 = version1.substr(begin1);
		bool allzero(true);
		for (char c : version1)
		{
			if (c == '0' || c == '.') continue;
			else
			{
				allzero = false;
				break;
			}
		}
		if (allzero) return 0;
		else return 1;
	}
}