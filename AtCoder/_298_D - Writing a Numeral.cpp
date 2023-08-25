#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 6e5 + 10, MOD = 998244353;

int n, q[N];
int p[N];

int myMod(long long x)
{
    if (x >= 0) return x % MOD;
    return MOD - (labs(x) % MOD);\
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        if (!i) p[i] = 1;
        else p[i] = myMod((LL)p[i - 1] * 10);
    }
    int hh = 1, tt = 0;
    q[++tt] = 1;
    long long ans = 1; 
    while (n--)
    {
        int opt, x;
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &x);
            ans = ans * 10 + x;
            q[++tt] = x;
            ans = myMod(ans);
        }
        else if (opt == 2) 
        {
            int len = tt - hh;
            x = q[hh++];
            ans = ans - (LL) x * p[len];
            ans = myMod(ans); 
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}