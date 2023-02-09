#include<bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/design-authentication-manager
class AuthenticationManager {
private:
    unordered_map<string, int> mp;
    int _timeToLive;
public:
    AuthenticationManager(int timeToLive) : _timeToLive(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp[tokenId] == 0) return;
        if (currentTime >= mp[tokenId] + _timeToLive) return;
        mp[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for (auto &it : mp)
            if (it.second != 0 && it.second + _timeToLive > currentTime) 
                cnt++;
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */