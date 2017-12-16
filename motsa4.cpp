#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int A = nums1.size();
        int B = nums2.size();
        int N = (A + B);
        double result;
        if( N & 0x01)
        {
          result = findKth(nums1, nums2, 0, 0, A, B, N / 2 + 1);
        }
        else
        {
          int a = findKth(nums1, nums2, 0, 0, A, B, N / 2);
          int b = findKth(nums1, nums2, 0, 0, A, B, N / 2 + 1);
          result = (a + b) / 2.0;
        }
        return result;
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int s1, int s2, int m, int n, int k)
    {
      if(m > n)
      {
        return findKth(nums2, nums1, s2, s1, n, m, k);
      }
      if(m == 0)
      {
        return nums2[s2 + k - 1];
      }
      if(k == 1)
      {
        return min(nums1[s1], nums2[s2]);
      }
      int x = min(k/2, m);
      int y = k - x;
      if(nums1[s1 + x - 1] < nums2[s2 + y - 1])
      {
        return findKth(nums1, nums2, s1 + x, s2, m - x, n, y);
      }
      else if(nums1[s1 + x - 1] = nums2[s2 + y - 1])
      {
        return nums1[s1 + x - 1];
      }
      else
      {
        return findKth(nums1, nums2, s1, s2 + y, m, n - y, x);
      }
    }
};

int main()
{
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  double result = Solution().findMedianSortedArrays(nums1, nums2);
  cout << result << endl;
  return 0;
}