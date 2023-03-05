// https://codeforces.com/problemset/problem/584/C
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, t;

char s1[N], s2[N], s3[N];

void add (int i) {
    for (int j = 0; j < 26; j++) {
        if ('a' + j != s1[i] && 'a' + j != s2[i]) {
            s3[i] = 'a' + j;
            break;
        }
    }
}
int main(){
    scanf("%d%d", &n, &t);
    scanf("%s%s",s1, s2);
    int cnt = n - t;
    for (int i = 0; i < n && cnt; i++) 
        if (s1[i] == s2[i]) s3[i] = s1[i], cnt--;
    t = cnt, cnt *= 2;
    for (int i = 0; i < n && cnt; i++) {
        if (!s3[i]) {
            if (cnt > t) s3[i] = s1[i], cnt--;
            else  s3[i] = s2[i], cnt--;
        }
    }
    if (!cnt) { 
        for (int i = 0; i < n; i++)
            if (!s3[i]) add(i);
        for (int i = 0; i < n; i++) printf("%c", s3[i]);
    } else puts("-1");
    return 0;
}