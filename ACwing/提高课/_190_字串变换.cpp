#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 10;

int n;
string A, B;
string a[N], b[N];
unordered_map<string, int> dist_a, dist_b;

vector<string> transform(const string& s, const string a[], const string b[])
{
    vector<string> res;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < s.size(); j++) {
            if (s.substr(j, a[i].size()) == a[i]) {
                res.push_back(s.substr(0, j) + b[i] + s.substr(j + a[i].size()));
            }
        }

    return res;
}

int extend(queue<string>& q, unordered_map<string, int>& d1, unordered_map<string, int>& d2,
            const string a[], const string b[]) 
{

    int d = d1[q.front()];
    while (q.size() && d1[q.front()] == d) { // 每次只扩展一层
        auto t = q.front();
        q.pop();

        auto v = transform(t, a, b);
        
        for (auto& s : v) {
            if (d2.count(s)) return d1[t] + d2[s] + 1;
            if (d1.count(s)) continue;
            q.push(s);
            d1[s] = d1[t] + 1;            
        }
    }
    return -1;
}

int bfs() {

    if (A == B) return 0;
    dist_a[A] = 0, dist_b[B] = 0;
    queue<string> qa, qb;
    qa.push(A);
    qb.push(B);

    int cnt = 0;
    while (qa.size() && qb.size()) {
        int t = 0;
        if (qa.size() < qb.size())
            t = extend(qa, dist_a, dist_b, a, b);
        else 
            t = extend(qb, dist_b, dist_a, b, a);

        if (t == -1) ++cnt; // 暂时没找到
        else if (t <= 10) return t; // 找到了且小于等于10
        else return -1; // 找到了但大于10

        if (cnt > 10) return -1;
    }
    return -1;
}
int main() {

    cin >> A >> B;
    while (cin >> a[n] >> b[n]) n++;

    int res = bfs();

    if(res == -1) puts("NO ANSWER!");
    else printf("%d\n", res);

    return 0;
}

