#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/sort-the-students-by-their-kth-score/description/
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](auto &v1, auto &v2){return v1[k] > v2[k];});
        return score;
    }
};