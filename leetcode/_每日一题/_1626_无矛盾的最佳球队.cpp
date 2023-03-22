// https://leetcode.cn/problems/best-team-with-no-conflicts/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; i++) {
            a[i] = {ages[i], scores[i]};
        }
        sort(a, a + n);
        int f[n];
        for (int i = 0; i < n; i++) {
            f[i] = a[i].second;
            for (int j = 0; j < i; j++) {
                if (a[j].second <= a[i].second){
                    f[i] = max(f[i], f[j] + a[i].second);
                }
            }
        }
        return *max_element(f, f + n);
    }
};