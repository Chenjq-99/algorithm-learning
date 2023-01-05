#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/count-pairs-with-xor-in-a-range
class Solution {
    static const int N = 20005;
    int trie[N * 15][2], cnt[N * 15], idx;
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return get(nums, high) - get(nums, low - 1);
    }
    int get(vector<int>& nums, int th) {
        idx = 0;
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += query(nums[i], th);
            insert(nums[i]); 
        }
        return ans;
    }
    void insert(int x) {
        int p = 0;
        for (int i = 14; i >= 0; i--) {
            int u = (x >> i)  & 1;
            if (trie[p][u] == 0) trie[p][u] = ++idx;
            p = trie[p][u]; //移动到下一个结点 
            cnt[p]++; // 个数增加，cnt[x]代表x结点出现的次数
        }
    }
    int query(int x, int th) {
        int sum = 0, p = 0;
        for  (int i = 14; i >= 0; i--) {
            int c = (th >> i) & 1;
            int b = (x >> i) & 1;
            int a = c ^ b; // 期望值
            if (c == 1) { 
                sum += cnt[trie[p][a ^ 1]];
                if (trie[p][a] == 0) return sum;
                p = trie[p][a]; 
            } else if (c == 0) { 
                if (trie[p][a] == 0) return sum; 
                p = trie[p][a]; 
            }
        }
        sum += cnt[p]; //加上走到最后的结点数
        return sum;
    }
};
