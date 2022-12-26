#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        auto check = [&](int x) -> bool {
            int cnt = 1, a = price[0];
            for (int i = 0; i < n; i++) {
                if (price[i] >= a + x) {
                    cnt++;
                    a = price[i];
                }
            }
            return cnt >= k;
        };
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};