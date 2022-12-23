#include<iostream>
using namespace std;

/* 
d[x]��ʾx�����ڵ�ľ��룬d[x] % 3 == 0 ��ʾ x �� ���ڵ� ��ͬ�࣬
                                == 1 ��ʾ x �� ���ڵ�
                                == 2 ��ʾ ���ڵ� �� x
*/
const int N = 50010;
int p[N], d[N], n, k;

int find(int x) {
    if(x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]]; // �ۼӾ���
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
            if (t == 1) { // x y ��ͬ��
                if (px == py && (d[x] - d[y]) % 3 != 0) res++; // x �� y �й�ϵ������ͬ��
                else if (px != py) { // x �� y ��û�й�ϵ����Ϊ���滰��������ϵ
                    p[px] = py; // ��x���Ͻӵ�y�����ϣ�py �� �����˵ĸ��ڵ㣬��Ϊx��py�ľ������d[y]
                    d[px] = d[y] - d[x];
                }
            } else { // t == 2 x �� y 
                // ��һ����� x �� px ��ͬ�࣬y �� py�� d[x] % 3 = 0 , d[y] % 3 = 2
                // �ڶ������ x �� px��y �� py ��ͬ�� d[x] % 3 = 1 , d[y] % 3 = 0
                // ��������� x �� px �ԣ� y �� py, d[x] % 3 = 2, d[y] % 3 = 1
                // �������(d[x] - d[y] - 1) % 3 == 0 ��ʾ x �� y
                if (px == py && (d[x] - d[y] - 1) % 3 != 0) res++;
                else if (px != py) { // x �� y ��û�й�ϵ����Ϊ���滰��������ϵ
                    p[px] = py; // ��x���Ͻӵ�y�����ϣ�py �� �����˵ĸ��ڵ㣬��Ϊx��py�ľ������d[y] + 1
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
