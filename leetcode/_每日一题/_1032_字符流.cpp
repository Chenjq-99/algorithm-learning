#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int N = 100000;
int son[N][26];
int idx;
int cnt[N];

class StreamChecker {
public:
    string str;

    void insert(string& s)
    {
        int p = 0;
        for (int i = 0; s[i]; i ++)
        {
            int u = s[i] - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }
    
    StreamChecker(vector<string>& words) {
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
        for (auto& w : words)
        {
            reverse(w.begin(), w.end());
            insert(w);
        }
    }

    bool query(char letter) {
        str += letter;
        int p = 0;
        for (int i = str.size() - 1; i >= 0; i --)
        {
            int u = str[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
            if (cnt[p]) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
