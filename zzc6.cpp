#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        if(numRows == 1)
        {
            return s;
        }
        int len = s.size();
        for(int i = 0; i < numRows; i++)
        {
            if(i == 0 || i == numRows - 1)
            {
                int tmp = i;
                while(tmp < len)
                {
                    result += s[tmp];
                    tmp += 2 * (numRows - 1);
                }
            }
            else
            {
                int tmp = i;
                while(tmp < len)
                {
                     result += s[tmp];
                     tmp += 2 * (numRows - i - 1);
                     if(tmp < len)
                     {
                         result += s[tmp];
                         tmp += 2 * i;
                     }
                     else
                     {
                        break;
                     }
                }
            }
        }
        return result;
    }
};

int main()
{
    string input = "PAYPALISHIRING";
    int num = 4;
    string result = Solution().convert(input, num);
    cout << result;
    return 0;
}