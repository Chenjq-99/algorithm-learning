#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/minimum-cost-to-split-an-array/
class Solution {
    // 复盘，反思
    // 1.如何求出一个数组的所有分割方式
    // 回溯, 枚举分割的位置
    # if(0)
    vector<int> nums;
    int n;
    vector<vector<int>> path;
    void out() {
        for (auto &v : path) {
            cout << "[";
            for (auto &x : v) cout << x << " " ;
            cout << "]";
        }
        cout << endl;
    }
    void dfs(int i) {
        if (i == n) {
            out();
            return;
        }
        for (int j = i; j < n; j++) {
            path.push_back(vector<int>(nums.begin() + i, nums.begin() + j + 1));
            dfs(j + 1);
            path.pop_back();
        }
    }
    #endif
    // 回溯本质是一种暴力搜索，数据范围通常在10左右
    // 如果我们不关心每种方案具体是什么，只关心某个状态的一些性质,就可以使用记忆化搜索
    // 比如对于数组 [1,2,1,2,1,3,3]
    // 这两种方案:[1,2] [1] 2,1,3,3 [1] [2,1] 2,1,3,3 
    // 对于我们求剩下的部分的性质没什么不同，只需要求一次即可，将性质保存起来下次直接使用
    # if(0)
    static const int N = 1005, INF = 0x3f3f3f3f;
    int f[N];
    vector<int> nums;
    int n, k;
    int dfs(int i) {
        if (i == n) return 0;
        if (f[i] != -1) return f[i];
        // 选择分割的位置
        int res = INF, cost = 0;
        int cnt[N] = {0};
        for (int j = i; j < n; j++) {
            cnt[nums[j]]++;
            if (cnt[nums[j]] == 2) cost += 2; 
            if (cnt[nums[j]] > 2)  cost += 1;
            res = min(res, dfs(j + 1) + k + cost);
        }
        return f[i] = res;
    }
    #endif
public:
    int minCost(vector<int>& nums, int k) {
        // test 1
        // this->nums = nums, n = nums.size();
        // dfs(0);
        
        // test 2
        // memset(f, -1, sizeof(f));
        // this->nums = nums, n = nums.size(), this->k = k;
        // return dfs(0);

        // test 3
        // 动态规划,本质和记忆化搜索一样
        // f[i] = min(f[j] + cost + k)
        int f[1005];
        int n = nums.size();
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int cnt[1005] = {0}, cost = 0;
            for (int j = i; j >= 0; j--) {
                cnt[nums[j]]++;
                if (cnt[nums[j]] == 2) cost += 2; 
                if (cnt[nums[j]] > 2)  cost += 1;
                f[i + 1] = min(f[i + 1], f[j] + cost + k);
            }
        }
        return f[n];
    }
};