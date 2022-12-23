#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/combinations/
// »ØËÝ
class Solution {
    vector<int> hours = {8, 4, 2, 1};
    vector<int> minutes = {32, 16, 8, 4, 2, 1};
    vector<string> result;
    vector<int> hoursSum;
    vector<int> minutesSum;
    int sum = 0;
    int count = 0;
    void backtracking_hours(int size, int startIdx) {
        if(count == size){
            if(sum >= 0 && sum <= 11) hoursSum.push_back(sum);
            return;
        }
        for(int i = startIdx; i < 4; i++){
            sum += hours[i];
            count++;
            backtracking_hours(size, i + 1);
            count--;
            sum -= hours[i];
        }
    }
    void backtracking_minutes(int size, int startIdx) {
        if(count == size){
            if(sum >= 0 && sum <= 59) minutesSum.push_back(sum);
            return;
        }
        for(int i = startIdx; i < 6; i++){
            sum += minutes[i];
            count++;
            backtracking_minutes(size, i + 1);
            count--;
            sum -= minutes[i];
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        for(int i = 0; i <= 4; i++){
            int j = turnedOn - i;
            if(j >= 0 && j <= 6) {
                hoursSum.clear();
                minutesSum.clear();
                sum = 0;
                count = 0;
                backtracking_hours(i, 0);
                sum = 0;
                count = 0;
                backtracking_minutes(j, 0);
                for(int m = 0; m < hoursSum.size(); m++){
                    for(int n = 0; n < minutesSum.size(); n++){
                        string ans = "";
                        string hour = to_string(hoursSum[m]);
                        string minute = to_string(minutesSum[n]);
                        ans += hour;
                        ans += ':';
                        if(minute.size() == 1){
                            ans += '0';
                            ans += minute;
                        } else {
                            ans += minute;
                        }
                        result.push_back(ans);
                    }
                }
            }
        }
        return result;
    }
};
// Ã¶¾Ù
// class Solution {
// public:
//     vector<string> readBinaryWatch(int turnedOn) {
//         vector<string> ans;
//         for (int h = 0; h < 12; ++h) {
//             for (int m = 0; m < 60; ++m) {
//                 if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
//                     ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
//                 }
//             }
//         }
//         return ans;
//     }
// };