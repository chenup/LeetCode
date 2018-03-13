enum Status{Valid = 0, InValid};

int runStatus = Valid;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0)
        {
        	runStatus = InValid;
        	return 0;
        }
        vector<int> res(1, 1);
        int pos1 = 0;
        int pos2 = 0;
        int pos3 = 0;
        int minN;
        while(res.size() < n)
        {
        	int n1 = res[pos1] * 2;
        	int n2 = res[pos2] * 3;
        	int n3 = res[pos3] * 5;
        	int tmp = min(n1, min(n2, n3));
        	if(tmp == n1) {pos1++;}
        	if(tmp == n2) {pos2++;}
        	if(tmp == n3) {pos3++;}
        	res.push_back(tmp);
        }
        return res.back();
    }
};