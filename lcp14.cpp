#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        auto first = strs.begin();
        if(strs.size() == 1)
        {
            return (*first);
        }
        for(int i = 0; i < (*first).length(); i++)
        {
            char c = (*first)[i];
            for(auto it = strs.begin() + 1; it != strs.end(); it++)
            {
                if(c != (*it)[i])
                {
                    return (*first).substr(0, i); 
                }
            }
        }
        return (*first); 
    }
};

int main()
{
    vector<string> v = {};
    string result;
    result = Solution().longestCommonPrefix(v);
    cout << result;
}