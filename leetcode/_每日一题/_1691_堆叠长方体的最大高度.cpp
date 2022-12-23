#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/maximum-height-by-stacking-cuboids/description/
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // h�ó����
        for (int i = 0; i < n; i++) sort(cuboids[i].begin(), cuboids[i].end());
        // ��w���򣬽�ά
        sort(cuboids.begin(), cuboids.end());
        // ��l �� h ����ά����LIS ���⣬ �����ٽ���һά��
        vector<int> f(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            f[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    f[i] = max(f[i], f[j] + cuboids[i][2]);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};