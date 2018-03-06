#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	int myAtoi(string str)
	{
		string str_max = "+2147483647";
		int int_max = 2147483647;
		string str_min = "-2147483648";
		int int_min = -2147483648;
		string str_result = "";
		int flag = 0;
		int rflag = 0;
		int len;
		int int_result = 0;
		int j, interval;
		int mflag = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if('0' <= str[i] && str[i] <= '9')
			{
				if(str[i] == '0' && flag != 1)
				{
					if(i == str.size() - 1 || str[i + 1] > '9' || str[i + 1] < '0')
					{
						str_result += '0';
						rflag = 1;
						flag = 1;
						break;
					}
					else
					{
						continue;
					}
				} 
				else				
				{
					flag = 1;
					str_result += str[i];
				}
			}
			else if(str[i] == '-' || str[i] == '+')
			{
				if(flag == 0)
				{
					flag = 2;
					str_result += str[i];
				}
				else if(flag == 1)
				{
					break;
				}
				else
				{
					rflag = 1;
					break;
				}				
			}
			else if(str[i] == ' ')
			{
				if(flag == 0)
				{
					continue;
				}
				else if(flag == 1)
				{
					break;
				}
				else
				{
					rflag = 1;
					break;
				}
			}
			else
			{
				if(flag == 1)
				{
					break;
				}
				else
				{
					rflag = 1;
					break;
				}
			}
		}
		if(rflag == 0 && flag == 1)
		{
			len = str_result.size();
			if(str_result[0] == '-')
			{
				if(len > str_min.size())
				{
					return int_min;
				}
				else if(len == str_min.size())
				{
					j = 1; 
					while(j < len)
					{
						if(str_result[j] > str_min[j] && mflag == 0)
						{
							return int_min;
						}
						else if(str_result[j] < str_min[j])
						{
							mflag = 1;
						}
						int_result = int_result * 10;
						int_result -=  (str_result[j] - 48);
						j++;
					}
					return int_result;
				}
				else
				{
					j = 1;
					interval = 1;
					while(len > j)
					{
						int_result += -1 * (str_result[len - j] - 48) * interval;
						interval = interval * 10;
						j++;
					}
					return int_result;
				}
			}
			else if(str_result[0] == '+')
			{
				if(len > str_max.size())
				{
					return int_max;
				}
				else if(len == str_max.size())
				{
					j = 1;
					while(j < len)
					{
						if(str_result[j] > str_max[j] && mflag == 0)
						{
							return int_max;
						}
						else if(str_result[j] < str_max[j])
						{
							mflag = 1;
						}
						int_result = int_result * 10;
						int_result +=  (str_result[j] - 48);
						j++;
					}
					return int_result;
				}
				else
				{
					j = 1;
					interval = 1;
					while(len > j)
					{
						int_result +=  (str_result[len - j] - 48) * interval;
						interval = interval * 10;
						j++;
					}
					return int_result;
				}
			}
			else
			{
				if(len > str_max.size() - 1)
				{
					return int_max;
				}
				else if(len == str_max.size() - 1)
				{
					j = 0;
					while(j < len)
					{
						if(str_result[j] > str_max[j + 1] && mflag == 0)
						{
							return int_max;
						}
						else if(str_result[j] < str_max[j + 1])
						{
							mflag = 1;
						}
						int_result = int_result * 10;
						int_result +=  (str_result[j] - 48);
						j++;
					}
					return int_result;
				}
				else
				{
					j = 1;
					interval = 1;
					while(len >= j)
					{
						int_result += (str_result[len - j] - 48) * interval;
						interval = interval * 10;
						j++;
					}
					return int_result;
				}
			}
			return 0;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	string str;
	cin >> str;
	int result;
	result = Solution().myAtoi(str);
	cout << result;
	return 0;
}