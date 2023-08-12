#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 15;
vector<int> g[N];
int nums[N];
int ans = N;
int n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool check(vector<int>& vec, int x)
{
    for (int i = 0; i < vec.size(); i++)
        if (gcd(vec[i], x) > 1) return false;
    return true;
}

void dfs(int u, int num)
{
    if (num + 1 >= ans) return;

    if (u >= n)
    {
        ans = min(ans, num + 1);
        return;
    }

    for (int i = 0; i <= num; i++)
    {
        if (check(g[i], nums[u]))
        {
            g[i].push_back(nums[u]);
            dfs(u + 1, num);
            g[i].pop_back();
        }
    }

    if (num + 1 <= n)
    {
        g[num + 1].push_back(nums[u]);
        dfs(u + 1, num + 1);
        g[num + 1].pop_back();
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    dfs(0, 0);

    printf("%d\n", ans);

    return 0;
}