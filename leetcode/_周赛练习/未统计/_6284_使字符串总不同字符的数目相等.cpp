#include<string>
using namespace std;
// https://leetcode.cn/problems/make-number-of-distinct-characters-equal/
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int h1[26] = {0}, h2[26] = {0};
        int len1 = 0, len2 = 0;
        for (auto& c : word1) h1[c - 'a']++;
        for (auto& c : word2) h2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (h1[i] != 0) len1++;
            if (h2[i] != 0) len2++;
        }
        for (int i = 0; i < 26; i++) {
            if (h1[i] == 0) continue;
            for (int j = 0; j < 26; j++) {
                if (h2[j] == 0) continue;
                int t1 = len1, t2 = len2;
                h1[i]--, h2[j]--;
                if (h1[i] == 0) len1--;
                if (h2[j] == 0) len2--;
                if (h1[j] == 0) len1++;
                if (h2[i] == 0) len2++;
                if (len1 == len2) return true;
                else len1 = t1, len2 = t2, h1[i]++, h2[j]++;
            }
        }
        return false;
    }
}; 