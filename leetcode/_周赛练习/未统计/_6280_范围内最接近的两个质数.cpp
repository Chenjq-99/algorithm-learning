#include<cstring>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/closest-prime-numbers-in-range/discussion/
class Solution {
    static const int N = 1e6 + 10;
    int primes[N], cnt = 0;
    bool st[N];
    void get_primes(int n) {
        memset(st, false, sizeof st);
        for (int i = 2; i <= n; i++) {
            if(!st[i]) primes[cnt++] = i;
            for (int j = 0; primes[j] <= n / i; j++) {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2,-1);
        int min = 0x3f3f3f3f;
        get_primes(right);
        for (int i = 1; i < cnt; i++) {
            int a = primes[i-1], b = primes[i];
            if (a >= left && b - a < min) res[0] = a, res[1] = b, min = b - a;
        }
        return res;
    }
};