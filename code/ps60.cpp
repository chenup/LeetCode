#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int count = 0;
        vector<string> tmp;
        //vector<string> result
        for(int i = 1; i <= n; i++)
        {
        	tmp.push_back(to_string(i));
        }
        string result = func(tmp, k, n);
        return result;
    }

    void func(vector<string>& tmp, int k, int n)
    {
    	int l = computeNFactorial(n - 1);
    	int a = k / l;
    	int b = k % l;
    	string c = tmp[a];
    	tmp.erase(tmp.begin() + a);
    	return str + func(tmp, b, n - 1);
    	/*
    	if(count == k)
    	{
    		return;
    	}
    	if(tmp.size() == 0)
    	{
    		count++;
    		result.push_back(str);
    		return;
    	}
    	for(int i = 0; i < tmp.size(); i++)
    	{
    		string s;
    		string c = tmp[i];
    		s = str + c;
    		tmp.erase(tmp.begin() + i);
    		func(tmp, k, s, result);
    		tmp.insert(tmp.begin() + i, c);
    	}
    	*/
    }

    int computeNFactorial(int n)
    {
    	int mul = 1;
    	if(n == 0)
    	{
    		return 1;
    	}
    	for(int i = n; i >= 1; i--)
    	{	
    		mul *= i;
    	}
    	return mul;
    }
};


int main()
{
	int n = 3;
	int k = 4;
	string result = Solution().getPermutation(n, k);
	cout << result << endl;
	return 0;
}