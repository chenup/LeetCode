#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		int N = s.szie();
		int M = p.size();
		set<int> pc;
		pc.insert(0);
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
			pc.clear();
			for(auto v : match)
			{
				if(p[v] == '*')
				{
					pc.insert(v + 1);
					pc.insert(v - 1);
				}
				else
				{
					pc.insert(v);
				}
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
};

int main()
{
	string s = "adaab";
	string p = "c*.*a*b";
	bool result = Solution().isMatch(s, p);
	cout << result;
	return 0;
}