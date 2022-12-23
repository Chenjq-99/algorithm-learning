#include<vector>
using namespace std;

// https://leetcode.cn/problems/maximal-network-rank/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n);
        vector<vector<int>> graph(n,vector<int>(n));
        for(auto road : roads){
            degrees[road[0]]++;
            degrees[road[1]]++;
            graph[road[0]][road[1]] = 1;
            graph[road[1]][road[0]] = 1;
        }
        int maxRank = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                maxRank = max(maxRank,degrees[i] + degrees[j] - graph[i][j]);
            }
        }
        return maxRank;
    }
};