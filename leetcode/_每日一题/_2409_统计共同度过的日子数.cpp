#include<string>
using namespace std;
// https://leetcode.cn/problems/count-days-spent-together
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i <= 12; i++) days[i] += days[i - 1];
        int arriveA = days[(arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0') - 1] 
                        + (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        int leaveA = days[(leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0') - 1] 
                        + (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
        int arriveB = days[(arriveBob[0] - '0') * 10 + (arriveBob[1] - '0') - 1] 
                        + (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        int leaveB = days[(leaveBob[0] - '0') * 10 + (leaveBob[1] - '0') - 1] 
                        + (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');
        if (arriveA > leaveB || leaveA < arriveB) return 0;
        return min({leaveB - arriveA + 1, leaveA - arriveA + 1, leaveA - arriveB + 1, leaveB - arriveB + 1});  
    }
};