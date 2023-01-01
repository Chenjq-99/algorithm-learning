#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/minimum-number-of-moves-to-seat-everyone/
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size(), res = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for (int i = 0; i < n; ++i) res += abs(seats[i] - students[i]);
        return res;
    }
};