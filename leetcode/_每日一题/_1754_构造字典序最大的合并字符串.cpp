#include<string>
using namespace std;
// https://leetcode.cn/problems/largest-merge-of-two-strings/
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;
        int n = word1.size(), m = word2.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < n && idx2 < m) {
            if (word1[idx1] > word2[idx2]) merge += word1[idx1++];
            else if (word1[idx1] < word2[idx2]) merge += word2[idx2++];
            else {
                if (word1.substr(idx1) > word2.substr(idx2)) merge += word1[idx1++];
                else merge += word2[idx2++];
            }
        }
        while (idx1 < n) merge += word1[idx1++];
        while (idx2 < m) merge += word2[idx2++];
        return merge;
    }
};