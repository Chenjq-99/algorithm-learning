#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/count-pairs-of-similar-strings

class Solution {
public:
    int similarPairs(vector<string>& words) {
        for (auto& w : words) { // ШЅжи
            sort(w.begin(), w.end());
            w.erase(unique(w.begin(), w.end()), w.end());
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) 
            for (int j = i + 1; j < words.size(); j++)
                if (words[i] == words[j]) res++;

        return res;
    }
};