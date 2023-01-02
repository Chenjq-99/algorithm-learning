#include<vector>
#include<queue>
using namespace std;
// https://leetcode.cn/problems/number-of-orders-in-the-backlog
class Solution {
    typedef pair<int,int> PII;
    const int MOD = 1e9 + 7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII,vector<PII>,less<>> buy;
        priority_queue<PII,vector<PII>,greater<>> sell;
        for (auto& ord : orders) {
            if (ord[2] == 0) { // buy
                while (ord[1] && sell.size() && ord[0] >= sell.top().first) {
                    auto [price, amoumt] = sell.top();
                    sell.pop();
                    if (amoumt >= ord[1]) {
                        amoumt -= ord[1];
                        ord[1] = 0;
                        if (amoumt > 0) sell.emplace(price, amoumt);
                    } else {
                        ord[1] -= amoumt;
                    }
                }
                if (ord[1] > 0) buy.emplace(ord[0], ord[1]);
            }
            else { // sell
                while (ord[1] && buy.size() && ord[0] <= buy.top().first) {
                    auto [price, amoumt] = buy.top();
                    buy.pop();
                    if (amoumt >= ord[1]) {
                        amoumt -= ord[1];
                        ord[1] = 0;
                        if (amoumt > 0) buy.emplace(price, amoumt);
                    } else {
                        ord[1] -= amoumt;
                    }
                }
                if (ord[1] > 0) sell.emplace(ord[0], ord[1]);
            }
        }
        int res = 0;
        while (buy.size()) res = (res + buy.top().second) % MOD, buy.pop();
        while (sell.size()) res = (res + sell.top().second) % MOD, sell.pop();
        return res;
    }
};