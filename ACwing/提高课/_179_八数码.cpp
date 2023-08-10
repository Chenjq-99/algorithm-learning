#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<unordered_map>

#define x first
#define y second

using namespace std;

string start = "", ed = "12345678x";
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

int h(const string& s) {
    int res = 0;
    for (int i = 0; i <= 8; i++) {
        if (s[i] == 'x') continue;
        int t = s[i] - '1';
        res += abs(i % 3 - t % 3) + abs(i / 3 - t / 3);
    }
    return res;
}

int f(const string& s) {
    return dist[s] + h(s);
}

void A_star() {
    using PIS = pair<int, string>;

    priority_queue<PIS, vector<PIS>, greater<PIS>> pq;
    pq.emplace(f(start), start);

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    string ops = "uldr";

    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        auto state = t.y;
        if (state == ed) return;
        int xx, yy;
        for (int i = 0; i <= 8; i++) {
            if (state[i] == 'x') {
                xx = i / 3, yy = i % 3;
                break;
            }
        }

        auto source = state;

        for (int i = 0; i < 4; i++) {
            int a = xx + dx[i], b = yy + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            swap(state[xx * 3 + yy], state[a * 3 + b]);
            if (!dist.count(state) || dist[state] > dist[source] + 1) {
                dist[state] = dist[source] + 1;
                pq.emplace(f(state), state);
                pre[state] = {ops[i], source};
            }
            state = source;
        }
    }
}

int main() {
    
    string seq = "";
    
    for (int i = 0; i <= 8; i++) {
        char ch;
        cin >> ch;
        start += ch;
        if (ch != 'x') seq += ch;
    }
    
    dist[start] = 0;
    
    int t = 0;
    for (int i = 0; i < seq.size(); i ++ )
        for (int j = i + 1; j < seq.size(); j ++ )
            if (seq[i] > seq[j])
                t ++ ;

    if (t & 1) puts("unsolvable");
    else {
        
        A_star();
        
        string options = "";
        while (ed != start) {
            options += pre[ed].x;
            ed = pre[ed].y;
        }
        reverse(options.begin(), options.end());
        cout << options << endl;
        
    } 
    
    return 0;
}
