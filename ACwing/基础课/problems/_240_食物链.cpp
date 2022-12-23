#include<iostream>
using namespace std;

/* 
d[x]表示x到根节点的距离，d[x] % 3 == 0 表示 x 和 根节点 是同类，
                                == 1 表示 x 吃 根节点
                                == 2 表示 根节点 吃 x
*/
const int N = 50010;
int p[N], d[N], n, k;

int find(int x) {
    if(x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]]; // 累加距离
        p[x] = t;
    }
    return p[x];
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0;
    while (k--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (x > n || y > n) res++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) { // x y 是同类
                if (px == py && (d[x] - d[y]) % 3 != 0) res++; // x 和 y 有关系但不是同类
                else if (px != py) { // x 和 y 还没有关系，认为是真话，建立关系
                    p[px] = py; // 把x集合接到y集合上，py 是 所有人的根节点，认为x到py的距离等于d[y]
                    d[px] = d[y] - d[x];
                }
            } else { // t == 2 x 吃 y 
                // 第一种情况 x 和 px 是同类，y 被 py吃 d[x] % 3 = 0 , d[y] % 3 = 2
                // 第二种情况 x 吃 px，y 和 py 是同类 d[x] % 3 = 1 , d[y] % 3 = 0
                // 第三种情况 x 被 px 吃， y 吃 py, d[x] % 3 = 2, d[y] % 3 = 1
                // 综上如果(d[x] - d[y] - 1) % 3 == 0 表示 x 吃 y
                if (px == py && (d[x] - d[y] - 1) % 3 != 0) res++;
                else if (px != py) { // x 和 y 还没有关系，认为是真话，建立关系
                    p[px] = py; // 把x集合接到y集合上，py 是 所有人的根节点，认为x到py的距离等于d[y] + 1
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
