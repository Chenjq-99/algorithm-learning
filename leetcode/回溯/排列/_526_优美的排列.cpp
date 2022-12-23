#include<vector>
using namespace std;

// https://leetcode.cn/problems/beautiful-arrangement/description/
class Solution {
private:
    int res = 0;
    vector<vector<int>> record;
    vector<bool> used;
    void backtracking(int index, int n) {
        if(index == n + 1){
            res++;
            return;
        }
        for(int i : record[index]){
            if(used[i] == false){
                used[i] = true;
                backtracking(index + 1, n);
                used[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        record.resize(n + 1);
        used.resize(n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i % j == 0 || j % i == 0){
                    record[i].push_back(j);
                }
            }
        }
        backtracking(1, n);
        return res;
    }
};
