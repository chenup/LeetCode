#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator == 0)
        {
        	return "0";
        }
        if(denominator == 0)
        {
        	return "";
        }
        if(numerator > 0 ^ denominator > 0)
        {
        	res += '-';
        }
        long long int n = numerator;
        long long int d = denominator;
		n = abs(n);
		d = abs(d); 
        long long int part1 = n / d;
        res += to_string(part1);
        long long int left = n % d;
        if(left == 0)
        {
        	return res;
        }
        res += '.';
        unordered_map<int, int> tmp;
        while(left)
        {
        	if(tmp.find(left) != tmp.end())
        	{
        		int idx = tmp[left];
        		res.insert(idx, 1, '(');
        		res += ')';
        		return res;
        	}
        	tmp[left] = res.size();
        	left *= 10;
        	res += to_string(left / d);
        	left %= d;
        }
    	return res;
    }
};

int main()
{
	int n = -1;
	int d = -2147483648;
	cout << Solution().fractionToDecimal(n, d) << endl;
	return 0;
}