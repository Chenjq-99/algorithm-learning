#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/online-majority-element-in-subarray/description/
class MajorityChecker {
    vector<int> a;
    unordered_map<int, int> cnt;
    unordered_map<int, vector<int>> s;
    int n, len;
public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        len = sqrt(2 * n);
        a = arr;
        for (auto& x : a) cnt[x]++;
        for (auto& [k, v] : cnt) {
            if (v > len / 2) {
                s[k] = vector<int>(n + 1);
                for (int i = 1; i <= n; i++) {
                    s[k][i] =  s[k][i - 1] + (a[i - 1] == k);
                }
            }
        }
    }
    
    int query(int left, int right, int threshold) {
        if (right - left + 1 <= len) {
            cnt.clear();
            for (int i = left; i <= right; i++) {
                if (++cnt[a[i]] >= threshold) return a[i];
            }
        } else {
            for (auto& [k, v] : s) {
                if (v[right + 1] - v[left] >= threshold) return k;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */