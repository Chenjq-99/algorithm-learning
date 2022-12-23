#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n);
        for(auto edge : edges){
            inDegrees[edge[1]]++;
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(inDegrees[i] == 0) result.push_back(i);
        }
        return result;
    }
};