#include<vector>
#include<queue>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/
class Solution {
public:
#if 0
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        // 建图
        vector<int> e[n];
        for (auto &road : roads) {
            e[road[0]].push_back(road[1]);
            e[road[1]].push_back(road[0]);
        }

        long long ans = 0;
        // DFS 统计子树大小，同时统计答案
        function<int(int, int)> dfs = [&](int sn, int fa) {
            int ret = 1;
            for (int fn : e[sn]) if (fn != fa) {
                int t = dfs(fn, sn);
                // 更新子树大小
                ret += t;
            }
            // 计算 sn -> fa 这条边的贡献 0->-1 不计算
            if(sn) ans += (ret + seats - 1) / seats;
            return ret;
        };
        dfs(0, -1);
        return ans;
    }
#endif

    // 拓扑排序
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0LL;
        queue<int> q;
        vector<vector<int>> e(roads.size() + 1);
        vector<int> d(roads.size() + 1); //度
        vector<long long> s(roads.size() + 1); //当前节点有多少人
        for(auto t : roads){
            e[t[0]].emplace_back(t[1]);
            e[t[1]].emplace_back(t[0]);
            d[t[0]]++;
            d[t[1]]++;
        }
        for(int i = 1;i<d.size();i++){
            if(d[i] == 1 ){
                q.emplace(i);
            }
            s[i] = 1LL;
        }
        while(!q.empty()){
            int n = q.size();
            auto f = q.front();
            q.pop();
            ans += ceil((double)s[f]/(double)seats) * 1LL; // 把当前节点的所有人送到父节点需要多少车
            for(auto t:e[f]){
                d[t]--;
                s[t] += s[f] * 1LL;
                if(t && d[t] == 1){
                    q.emplace(t);
                }
            }
        }
        return ans;
    }
};
