#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/smallest-sufficient-team/
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> hash;
        vector<int> f(1 << n, n + 1), g(m);
        vector<pair<int, int>> path(1 << n);
        vector<int> ans;
        for (int i = 0; i < n; i++) hash[req_skills[i]] = i;
        for (int i = 0; i < m; i++) {
            for (auto& s : people[i]) {
                g[i] |= 1 << hash[s];
            }
        }
        f[0] = 0;
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < m; j++) {
                int& v = f[i | g[j]];
                if (v > f[i] + 1) {
                    path[i | g[j]] = {i, j};
                    v = f[i] + 1;
                }
            }
        }
        for (int st = (1 << n) - 1; st; ) {
            ans.push_back(path[st].second);
            st = path[st].first;
        }
        return ans;
    }
};