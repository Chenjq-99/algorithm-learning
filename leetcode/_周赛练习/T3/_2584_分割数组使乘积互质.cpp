// https://leetcode.cn/problems/split-the-array-to-make-coprime-products/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> p;
    vector<vector<pair<int, int>>> primes;

    vector<pair<int, int>> get_divide(int x){
        vector<pair<int, int>> res;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                int t = 0;
                while (x % i == 0) {
                    t++;
                    x /= i;
                }
                res.push_back({i, t});
            }  
        }
        if (x > 1) res.push_back({x, 1});
        return res;
    }


    int findValidSplit(vector<int>& nums) {
        //�洢�ܹ���������������
        for (int i = 0; i < nums.size(); i++) {
            primes.push_back(get_divide(nums[i]));
        }
        for (auto x : primes) {
            for (auto y : x) {
                int a = y.first, b = y.second;
                p[a] += b;
            }
        }
        unordered_map<int, int> pre;
        for (int i = 0; i < primes.size() - 1; i++) {
            for (auto y : primes[i]) {
                int a = y.first, b = y.second;
                pre[a] += b;
            }
            //preʱǰ׺����������pʱ�ܵ�������
            bool flag = true;
            for (auto it : pre) {
                if (it.second != p[it.first]) {
                    flag = false; 
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;

    }
};