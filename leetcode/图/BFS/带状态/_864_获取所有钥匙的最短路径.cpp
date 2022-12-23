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
        // dist[x][y][mask] ��ʾ��mask״̬����(x,y)��Ҫ��С�Ĳ�����-1��ʾû�ѹ����λ��
        q.emplace(sx, sy, 0); // ��ʼ�㣬״̬��һ��Կ�׶�û�� 0
        dist[sx][sy][0] = 0;  
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) { // ���ĸ�������չ
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') { // ���Ҫ�ѵ�λ���ǿջ�����㣬״̬�ǲ�����
                        if (dist[nx][ny][mask] == -1) { 
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                    else if (islower(grid[nx][ny])) { // Ҫ�ѵ�λ����һ��Կ�ף�״̬Ҫ��
                        int idx = key2Index[grid[nx][ny]]; // �����ǵڼ���Կ��
                        if (dist[nx][ny][mask | (1 << idx)] == -1) { // ����ڼ�һ����Կ�׵�״̬��û�ѹ�
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;
                            if ((mask | (1 << idx)) == (1 << key2Index.size()) - 1) { // ����������Կ�׾�����
                                return dist[nx][ny][mask | (1 << idx)]; 
                            }
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    }
                    else { // �������� ״̬Ҳ�����
                        int idx = key2Index[tolower(grid[nx][ny])]; // �ҵ���ӦԿ�׵ı��
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) { //��������Կ�ף�����û�ѹ�
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