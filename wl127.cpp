#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
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