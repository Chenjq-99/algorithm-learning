#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> res;
    unordered_map<string, multimap<string, bool>> g;
    void dfs(string u) {
        for (auto& p : g[u]) {
            if (p.second) {
                p.second = false;
                dfs(p.first);
                res.push_back(p.first);
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            g[t[0]].emplace(t[1], true);
        }
        dfs("JFK");
        res.push_back("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};