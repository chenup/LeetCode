class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n)
        {
        	n = n - 1;
     		char c = n % 26 + 'A';
        	n = n / 26;
        	s = c + s;
        }
        return s;
    }
};