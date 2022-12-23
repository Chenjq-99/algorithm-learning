#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/h-index/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        if (citations.back() == 0) return 0;
        int n = citations.size(), l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (citations[mid] >= n - mid) r = mid;
            else l = mid + 1;
        }
        return n - l;
    }
};