// https://leetcode.cn/problems/number-of-even-and-odd-bits/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int k = 0, even = 0, odd = 0;
        while (n){
            if (n & 1) {
                if (k & 1) odd++;
                else even++;
            } 
            n >>= 1;
            k++;
        }
        return {even, odd};
    }
};