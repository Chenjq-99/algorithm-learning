#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        long long j = x;
        while(i <= j){
            long long k = (i + j)/2;
            if(k * k <= x ){
                if((k + 1) * (k + 1) > x) return k;
                i = k + 1;
            }else{
                j = k - 1;
            }
        }
        return 0;
    }
};