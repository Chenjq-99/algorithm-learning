#include<vector>
#include<deque>
using namespace std;

// https://leetcode.cn/problems/delivering-boxes-from-storage-to-ports/
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> p(n + 1), w(n + 1), neg(n + 1);
        vector<long long> W(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if (i > 1) {
                neg[i] = neg[i - 1] + (p[i] != p[i - 1]); 
            }
            W[i] = W[i - 1] + w[i];
        }
        deque<int> opt = {0};
        vector<int> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; i++) {
            while (i - opt.front() > maxBoxes || W[i] - W[opt.front()] > maxWeight) {
                opt.pop_front();
            }
            f[i] = g[opt.front()] + neg[i] + 2;
            if (i != n) {
                g[i] = f[i] - neg[i + 1];
                while (!opt.empty() && g[opt.back()] >= g[i]) {
                    opt.pop_back();
                }
                opt.push_back(i);
            }
        }
        return f[n];
    }
};

