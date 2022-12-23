#include<vector>
#include<queue>
#include<tuple>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/shortest-path-to-get-all-keys/discussion/
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0;
        unordered_map<char, int> key2Index;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                else if (islower(grid[i][j])) {
                    if (!key2Index.count(grid[i][j])) {
                        int idx = key2Index.size();
                        key2Index[grid[i][j]] = idx;
                    }
                }
            }
        }

        queue<tuple<int, int, int>> q;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(1 << key2Index.size(), -1)));
        // dist[x][y][mask] 表示以mask状态到达(x,y)需要最小的步数，-1表示没搜过这个位置
        q.emplace(sx, sy, 0); // 起始点，状态：一把钥匙都没有 0
        dist[sx][sy][0] = 0;  
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) { // 向四个方向扩展
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') { // 如果要搜的位置是空或者起点，状态是不会变的
                        if (dist[nx][ny][mask] == -1) { 
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                    else if (islower(grid[nx][ny])) { // 要搜的位置是一把钥匙，状态要变
                        int idx = key2Index[grid[nx][ny]]; // 具体是第几把钥匙
                        if (dist[nx][ny][mask | (1 << idx)] == -1) { // 如果在加一把新钥匙的状态下没搜过
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;
                            if ((mask | (1 << idx)) == (1 << key2Index.size()) - 1) { // 如果加上这把钥匙就齐了
                                return dist[nx][ny][mask | (1 << idx)]; 
                            }
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    }
                    else { // 遇到了锁 状态也不会变
                        int idx = key2Index[tolower(grid[nx][ny])]; // 找到对应钥匙的编号
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) { //如果有这把钥匙，并且没搜过
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};