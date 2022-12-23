#include<vector>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int m = 30000000;
        for(int i = 0; i < points.size(); i++){
            int a = points[i][0], b = points[i][1];
            if(a == x || b == y){
                int t = abs(x - a) + abs(y - b);
                if(t < m){
                    m = t;
                    ans = i;
                }
            }
        }
        return ans;
    }
};