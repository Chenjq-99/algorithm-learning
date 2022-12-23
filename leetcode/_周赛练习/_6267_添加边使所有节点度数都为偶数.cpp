#include<vector>
#include<set>
using namespace std;
// https://leetcode.cn/problems/add-edges-to-make-degrees-of-all-nodes-even
typedef long long LL;
class Solution {
    LL get(int a, int b) {
        if (a > b) swap(a, b);
        return a * 1000000LL + b;
    }
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        set<LL> s;
        vector<int> degrees(n + 1, 0);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            degrees[x]++;
            degrees[y]++;
            s.insert(get(x,y));
        }
        vector<int> odds;
        for (int i = 1; i <= n; i++) {
            if (degrees[i] & 1) odds.emplace_back(i);
        }
        int m = odds.size();
        if (m > 4) return false;
        if (m == 0) return true; 
        if (m == 2) {
            int a = odds[0], b = odds[1];
            if (!s.count(get(a,b))) return true;
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b) {
                    if (!s.count(get(a,i)) && !s.count(get(b,i))) return true;
                }
            }
        } else {
            // m == 4
            int a = odds[0], b = odds[1], c = odds[2], d = odds[3];
            if (!s.count(get(a,b)) && !s.count(get(c,d))) return true;
            if (!s.count(get(a,c)) && !s.count(get(b,d))) return true;
            if (!s.count(get(a,d)) && !s.count(get(b,c))) return true;
        }
        return false;
    }
};