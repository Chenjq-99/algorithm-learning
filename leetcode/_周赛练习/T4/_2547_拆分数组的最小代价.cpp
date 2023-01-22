#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/minimum-cost-to-split-an-array/
class Solution {
    // ���̣���˼
    // 1.������һ����������зָʽ
    // ����, ö�ٷָ��λ��
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
    // ���ݱ�����һ�ֱ������������ݷ�Χͨ����10����
    // ������ǲ�����ÿ�ַ���������ʲô��ֻ����ĳ��״̬��һЩ����,�Ϳ���ʹ�ü��仯����
    // ����������� [1,2,1,2,1,3,3]
    // �����ַ���:[1,2] [1] 2,1,3,3 [1] [2,1] 2,1,3,3 
    // ����������ʣ�µĲ��ֵ�����ûʲô��ͬ��ֻ��Ҫ��һ�μ��ɣ������ʱ��������´�ֱ��ʹ��
    # if(0)
    static const int N = 1005, INF = 0x3f3f3f3f;
    int f[N];
    vector<int> nums;
    int n, k;
    int dfs(int i) {
        if (i == n) return 0;
        if (f[i] != -1) return f[i];
        // ѡ��ָ��λ��
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
        // ��̬�滮,���ʺͼ��仯����һ��
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