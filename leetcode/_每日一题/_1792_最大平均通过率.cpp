#include<queue>
#include<vector>
#include<tuple>
using namespace std;
// https://leetcode.cn/problems/maximum-average-pass-ratio/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> heap;
        int n = classes.size();
        for(int i = 0; i < n; i++)
        {
            int p = classes[i][0];
            int t = classes[i][1];
            double add = (double)(p + 1) / (t + 1) - (double)p / t;
            heap.push({add,i});
            
        }

        while(extraStudents-- && !heap.empty())
        {
            auto cls = heap.top();
            heap.pop();
            int i = cls.second;
            int p = classes[i][0] += 1;
            int t = classes[i][1] += 1;
            double add = (double)(p + 1) / (t + 1) - (double)p / t;
            heap.push({add,i});
        }

        double res = 0.0;
        for(auto &p:classes) res += (double)p[0] / p[1];
        return res / n;
    }
};