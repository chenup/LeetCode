class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> res;
       int start = 0;
       int end;
       auto it = numbers.begin();
       int i;
       for(i = 1; i < numbers.size(); i++)
       {
       		if(*(start + it) + *(it + i) > target)
       		{
       			end = i;
       		}
       		else if(*(start + it) + *(it + i) == target)
       		{
       			res.push_back(start + 1);
       			res.push_back(i + 1);
       			return res;
       		}
       }
       end = i - 1;
       while(start < end)
       {
       		if(*(start + it) + *(it + end) == target)
       		{
       			res.push_back(start + 1);
       			res.push_back(end + 1);
       			return res;
       		}
       		else if(*(start + it) + *(it + end) < target)
       		{
       			start++;
       		}
       		else
       		{
       			end--;
       		}
       }
    }
};