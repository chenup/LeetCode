#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle) {
        int R = 256;
        int M = needle.size();
        if(M == 0)
        {
        	return -1;
		}
    	int dfa[R][M] = {0};
    	dfa[needle[0]][0] = 1;
    	for(int X = 0, j = 1; j < M; j++)
    	{
    		for(int c = 0; c < R; c++)
    		{
    			dfa[c][j] = dfa[c][X];
    		}
    		dfa[needle[j]][j] = j + 1;
    		X = dfa[needle[j]][X];
    	}
		int i;
		int j;
    	int N = haystack.size();
    	for(i = 0, j = 0; i < N && j < M; i++)
    	{
    		j = dfa[haystack[i]][j];
    	}
    	if(j == M)
    	{
    		return i - M;
    	}
    	else
    	{
    		return -1;
    	}
    }


};

int main()
{
	string haystack = "aaaaa";
	string needle = "bba";
	int result = Solution().strStr(haystack, needle);
	cout << result << endl;
	return 0;
}