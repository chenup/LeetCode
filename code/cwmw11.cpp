#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    /*
    	int max = 0;
    	int l = height.size();
    	for(int i = 0; i < l; i++)
    	{
    		for(int j = i + 1; j < l; j++)
    		{
    			int h = min(height[i], height[j]);
    			int tmp = h * (j - i);
    			if(tmp > max)
    			{
    				max = tmp;
    			}
    		}
    	}
        return max;
    }
    */
		int max = 0;
		if(height.size() <= 1)
		{
			return 0;
		}
		auto s = height.begin();
		auto e = height.end() - 1;
		while(s != e)
		{
			int tmp;
			if(*s <= *e)
			{
				tmp = *s * (e - s);
				s++;
				
			}
			else
			{
				tmp = *e * (e - s);
				e--;
			}
			if(tmp > max)
			{
				max = tmp;
			}
		}
		return max;
	}
};

int main()
{
	vector<int> height = {1, 2, 3, 4, 5};
	int vol = Solution().maxArea(height);
	cout << vol << endl;
	return 0;
}