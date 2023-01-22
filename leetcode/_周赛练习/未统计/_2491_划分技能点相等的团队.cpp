#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int sum = skill[0] + skill[n-1];
        long long res = 0;
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n-1-i] == sum) {
                res += skill[i] * skill[n-1-i];
            } else {
                return -1;
            }
        }
        return res;
    }
};