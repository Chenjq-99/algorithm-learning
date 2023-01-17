#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/russian-doll-envelopes/solutions/
class Solution {
private:
    int binary_search(vector<int>& heap, int tar) {
        int n = heap.size();
        if (n == 0) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (heap[mid] >= tar) r = mid;
            else l = mid + 1;
        }
        return heap[l] >= tar ? l : -1;
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        // ��һά���򣬵ڶ�ά����
        // �ȶԿ�� w ������������������� w ��ͬ����������ո߶� h ��������
        // ֮������е� h ��Ϊһ�����飬����������ϼ��� LIS �ĳ��Ⱦ��Ǵ𰸡�
        // LIS��������� ��̬�滮 Ҳ������ ���� + ֽ����Ϸ
        sort(env.begin(),env.end(),[](vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            return v1[1] > v2[1]; 
        });
        // �������� + ֽ����Ϸ O(nlogn)
        vector<int> heap;
        for (int i = 0; i < n; i++) {
            int idx = binary_search(heap, env[i][1]);
            if (idx != -1) heap[idx] = env[i][1];
            else heap.push_back(env[i][1]);
        } 
        return heap.size();

        // ��̬�滮 O(n^2) ��leetcode�ᳬʱ
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (env[j][1] < env[i][1]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};