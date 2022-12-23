#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/maximum-total-importance-of-roads/description/
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degrees(n);
        for(auto road : roads){
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        sort(degrees.begin(),degrees.end());
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            sum += degrees[i - 1] * i;
        }
        return sum;
    }
};