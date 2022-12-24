#include<string>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

class Solution {
    typedef unsigned long long ULL;
    static const int N = 100010, P = 131;
    ULL h[N], p[N];
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }
        unordered_map<ULL,int> hash;
        for (int i = 1; i + 10 - 1 <= n; i++) {
            int j = i + 10 - 1;
            ULL t = h[j] - h[i - 1] * p[j - i + 1];
            if (++hash[t] == 2) res.push_back(s.substr(i - 1, 10));
        } 
        return res;
    }
};