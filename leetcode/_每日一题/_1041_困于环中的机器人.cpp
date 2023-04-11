#include<string>
using namespace std;
// https://leetcode.cn/problems/robot-bounded-in-circle
class Solution {
public:
    bool isRobotBounded(string s) {
        int x = 0, y = 0, d = 0;
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'G') x += dx[d], y += dy[d];
            if (s[i] == 'L') d = (d + 1) % 4;
            if (s[i] == 'R') d = (d + 3) % 4;
        }
        return x == 0 && y == 0 || d;
    }
};