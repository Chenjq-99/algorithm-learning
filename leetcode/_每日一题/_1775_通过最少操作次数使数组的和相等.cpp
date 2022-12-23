#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0); 
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0); 
        if (sum1 < sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end(), greater<>());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0, dif = sum1 - sum2, res = 0;
        while ((idx1 < n || idx2 < m) && dif > 0) {
            if (idx2 >= m || (idx1 < n && nums1[idx1] - 1 > 6 - nums2[idx2])) {
                dif -= nums1[idx1] - 1;
                idx1++;
            } else {
                dif -= 6 - nums2[idx2];
                idx2++;
            }
            res++;
        }
        return dif > 0 ? -1 : res;
    }
};