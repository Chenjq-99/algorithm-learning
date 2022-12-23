#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/assign-cookies/description/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gIdx = g.size() - 1;
        int sIdx = s.size() - 1;
        int res = 0;
        while(gIdx >= 0 && sIdx >= 0){
            if(s[sIdx] >= g[gIdx]){
                res++;
                sIdx--;
            }
            gIdx--;
        }
        return res;
    }
};