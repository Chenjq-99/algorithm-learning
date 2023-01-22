#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/maximum-number-of-groups-getting-fresh-donuts
class Solution {
    typedef long long LL;
    int batch, n;
    unordered_map<LL, int> memo;
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        batch = batchSize, n = groups.size();
        // count 记录每个batch有几个元素
        vector<int> count(batch, 0);
        for (auto& g : groups) count[g % batch]++;
        // 用state记录count数组状态
        // 因为count[i] ≤ 30，所以用每5个bit记录一个count[i], 最多5 * 9 = 45位，所以用LL
        LL state = 0;
        // count[0]中的元素肯定是happy，直接从1开始计算状态
        for (int i = 1; i < batch; i++) state += (LL)count[i] << (i * 5);
        return count[0] + dfs(state, 0, count[0]); // state, preSum, 选择第几位
    }

    int dfs(LL state, int preSum, int i) {
        if (i == n) return 0;
        if (memo.count(state)) return memo[state];
        int bonus = (preSum % batch == 0);
        int res = 0;
        for (int j = 0; j < batch; j++) {
            if((state >> (j * 5) ) % 32 == 0) continue;
            state -= 1LL << (j * 5);
            res = max(res, dfs(state, (preSum + j) % batch, i + 1));
            state += 1LL << (j * 5);
        }
        return memo[state] = bonus + res;
    }
};