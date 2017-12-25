#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        auto it = intervals.begin();
        while(it < intervals.end())
        {
        	if((it + 1) != intervals.end())
        	{
        		if((*(it + 1)).start > (*it).end)
        		{
        			it++;
        		}
        		else
        		{
        			if((*(it + 1)).end > (*it).end)
        			{
        				(*it).end = (*(it + 1)).end;
        			}
        			it = intervals.erase(it + 1);
        			it = it - 1;
        		}
        	}
        	else
        	{
        		break;
        	}
        }
        return intervals;
    }

    bool cmp(vector<Interval> a, vector<Interval> b)
    {
    	return start.start > start.start;
    }
};

int main()
{
	vecotr<Interval> intervals;
	Interval i1 = Interval(1, 3);
	intervals.push_back(i1);
	Interval i2 = Interval(2, 6);
	intervals.push_back(i2);
	Interval i3 = Interval(8, 10);
	intervals.push_back(i3);
	Interval i4 = Interval(15, 18);
	intervals.push_back(i4);
	vector<Interval> result = Solution().merge(intervals);
	for(auto v : result)
	{
		cout << v.start << " " << v.end << endl;
	}
	return 0;
}