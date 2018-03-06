#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		int N = s.size();
		int M = p.size();
		set<int> pc;
		getReachPos(p, pc, 0);
		for(int i = 0; i < N; i++)
		{
			set<int> match;
			for(auto v : pc)
			{
				if(v < M)
				{
					if(p[v] == s[i] || p[v] == '.')
					{
						match.insert(v + 1);
					}
				}
			}
			if(match.empty())
			{
				return false;
			}
			pc.clear();
			for(auto v : match)
			{
				getReachPos(p, pc, v);
			}
		}
		for(auto v : pc)
		{
			if( v == M )
			{
				return true;
			}
		}
		return false;
    }
    
    void getReachPos(string p, set<int>& pc, int v)
    {
    	int M = p.size(); 
    	if(pc.find(v) != pc.end())
    	{
    		return;
		}
    	if(v == M)
    	{
    		pc.insert(M);
    		return;
		}
		pc.insert(v);
		if(p[v] != '*')
		{
			if(v < M - 1 && p[v + 1] == '*')
			{
				getReachPos(p, pc, v + 1);
			}
		}
		else
		{
			getReachPos(p, pc, v + 1);
			getReachPos(p, pc, v - 1);
		}
	}
};

int main()
{
	string s = "ab";
	string p = ".*c";
	bool result = Solution().isMatch(s, p);
	cout << result;
	return 0;
}