#include<bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
        for (int i = 1; i < folder.size(); i++) {
            string p = res.back();
            if (folder[i].size() >= p.size() && folder[i].substr(0, p.size()) == p && folder[i][p.size()] == '/') continue;
            res.push_back(folder[i]);
        }
        return res;
    }
};