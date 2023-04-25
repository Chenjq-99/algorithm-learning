#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/sort-the-people/description/
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        vector<string> ans;
        for (int i = 0; i < names.size(); i++) {
            v.push_back(make_pair(heights[i], names[i]));
        }
        sort(v.begin(), v.end(), greater());
        for (auto&[h, n] : v) {
            ans.push_back(n);
        }
        return ans;
    }
};