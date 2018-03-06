#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == -1)
        {
            return result;
        }
        int n = 1;
        while(n <= rowIndex + 1)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int i = 2; i < n; i++)
            {
                tmp.push_back(result[i - 2] + result[i - 1]);
            }
            if(n > 1)
            {
                tmp.push_back(1);
            }
            result = tmp;
            n++;
        }
        return result;
    }
};

int main()
{
	vector<int> result;
	int n = 5;
	result = Solution().getRow(n);
	for(auto it = result.begin(); it != result.end(); it++)
	{			
        cout << *it << endl;
	}
	return 0;
}