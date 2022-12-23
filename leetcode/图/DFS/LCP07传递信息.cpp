#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/chuan-di-xin-xi/
class Solution {
    unordered_map<int,vector<int>> outDegrees;
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        for(vector<int> v : relation){
            outDegrees[v[0]].push_back(v[1]);
        }
        return dfs(0, k, n-1);
    }
    int dfs(int begin, int k, int target){
        int ans = 0;
        if(k < 0) return 0;
        if(begin == target && k == 0) return 1;
        for(int i : outDegrees[begin]){
            ans += dfs(i, k-1, target);
        }
        return ans;
    }
};