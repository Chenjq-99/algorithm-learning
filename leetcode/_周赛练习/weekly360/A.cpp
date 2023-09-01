// https://leetcode.cn/problems/furthest-point-from-origin/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (moves[i] == 'L') a++;
            else if (moves[i] == 'R') b++;
            else c++;
        }
        return abs(a - b) + c;
    }
};