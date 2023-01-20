#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// https://leetcode.cn/problems/finding-the-users-active-minutes/
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto &log : logs) mp[log[0]].insert(log[1]);
        vector<int> res(k, 0);
        for (auto &item : mp) 
            if (item.second.size() > 0 && item.second.size() <= k)
                res[item.second.size() - 1]++;
        return res;
    }
};