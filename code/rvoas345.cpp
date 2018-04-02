class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
        	left = s.find_first_of(vowels, left);
        	right = s.find_last_of(vowels, right);
        	if(left < right)
        	{
        		swap(s[left++], s[right--]);
        	}
        }
        return s;
    }
};