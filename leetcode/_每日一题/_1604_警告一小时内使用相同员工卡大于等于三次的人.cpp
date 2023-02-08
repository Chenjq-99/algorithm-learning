#include<bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i <keyName.size(); i++) {
            int time = ((keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0')) * 60 + ((keyTime[i][3] - '0') * 10 + (keyTime[i][4] - '0'));
            mp[keyName[i]].push_back(time);
        }
        vector<string> res;
        for (auto &it : mp) {
            vector<int> times = it.second;
            if (times.size() < 3) continue;
            sort(times.begin(), times.end());
            for (int i = 2; i < times.size(); i++) {
                int diff = times[i] - times[i - 2];
                if (diff <= 60) {
                    res.push_back(it.first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};