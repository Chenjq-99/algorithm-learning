// https://leetcode.cn/problems/count-symmetric-integers/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
    bool check(int x) {
        vector<int> v;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        if (v.size() & 1) return false;
        return accumulate(v.begin(), v.begin() + v.size() / 2, 0) == accumulate(v.begin() + v.size() / 2, v.end(), 0);
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; x++)
            if (check(x)) ans++;
        return 0;
    }
};