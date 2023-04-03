#include<vector>
using namespace std;
// https://leetcode.cn/problems/previous-permutation-with-one-swap/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int k = arr.size() - 1;
        while (k > 0 && arr[k - 1] <= arr[k]) k--;
        if (k <= 0) return arr;
        int t = k;
        while (t < arr.size() && arr[t] < arr[k - 1]) t++;
        while (t >= 2 && arr[t - 1] == arr[t - 2]) t--;
        swap(arr[k - 1], arr[t - 1]);
        return arr;
    }
};