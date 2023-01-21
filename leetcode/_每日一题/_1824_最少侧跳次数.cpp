#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-sideway-jumps/
class Solution {
    /*
    设f[i][j] 表示到达第i个位置的第j个跑道最小的侧跳次数
    最开始的想法是对于f[i][j] 取min{从同一跑道转移而来，从其他跑道侧跳而来}
    错误：如果这么做，更新同一个位置三条跑道相互依赖，不知道先更新哪一个，换句话说不满足无后效性
    改善：先横向更新，一定有跑道通过横向更新达到了最优值(反证法)
    对于没有达到最优值的跑道，可以通过已经达到最优值的跑道更新过来
    已经达到最优值的跑道则不会受其他跑道的影响
    这样就可以满足无后效性，不用考虑三条跑道的更新顺序
    */ 
public:
    int minSideJumps(vector<int>& obs) {
        int f[3] = {1, 0, 1};
        int n = obs.size() - 1;
        for (int i = 1; i <= n; i++) {
            // 横向更新
            for (int j = 0; j < 3; j++)
                if (obs[i] == j + 1) f[j] = 0x3f3f3f3f;
            // 纵向更新
            for (int j = 0; j < 3; j++) {
                if (obs[i] == j + 1) continue;
                for (int k : {(j + 1) % 3, (j + 2) % 3})
                    f[j] = min(f[j], f[k] + 1);
            }
        }
        return min(f[0], min(f[1], f[2]));
    }
};

class Solution {
    /*
    还有另外一种想法，
    如果第i个位置不是障碍物 f[i][j] = f[i - 1][j]
    对于另外两条跑道k，如果k没有障碍物则，
    f[i][j] = min(f[i][j], f[i - 1][k] + 1)
    其实本质上还是先横向更新，再纵向更新
    */ 
public:
    int minSideJumps(vector<int>& obs) {
        int f[3] = {1, 0, 1};
        int n = obs.size() - 1;
        for (int i = 1; i <= n; i++) {
            int pos = obs[i] - 1;
            for (int j = 0; j < 3; j++) {
                if (j == pos) {
                    f[j] = 0x3f3f3f3f;
                    continue;
                } 
                for (int k : {(j + 1) % 3, (j + 2) % 3}) 
                    if (k != pos) f[j] = min(f[j], f[k] + 1);
            }
        }
        return min(f[0], min(f[1], f[2]));
    }
};
