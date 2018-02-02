#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> visit;
        vector<string> next;
        int depth = 2;
        if(beginWord.size() == 0)
        {
        	return 0;
        }
        visit.push_back(beginWord);
        while(true)
        {
        	for(auto it : visit)
        	{
        		auto v = wordList.begin();
        		while(v != wordList.end())
        		{
        			if(helper(*v, it))
        			{
        				if(*v == endWord)
        				{
        					return depth;
        				}
        				next.push_back(*v);
        				v = wordList.erase(v);
        			}
        			else
        			{
        				v++;
        			}
        		}
        	}
        	visit.clear();
        	if(next.size() == 0)
        	{
        		break;
        	}
        	for(auto it : next)
        	{
        		visit.push_back(it);
        	}
        	next.clear();
        	depth++;
        }
        return 0;
    }

    bool helper(string a, string b)
    {
    	int sum = 0;
    	for(int i = 0; i < a.size(); i++)
    	{
    		if(a[i] != b[i])
    		{
    			sum++;
    		}
    	}
    	if(sum == 1)
    	{
    		return true;
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	string beginWord = "hit";
	string endWord = "cog";
	int result = Solution().ladderLength(beginWord, endWord, wordList);
	cout << result << endl;
	return 0;
}