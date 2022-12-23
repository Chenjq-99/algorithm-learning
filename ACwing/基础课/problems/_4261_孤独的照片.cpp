#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 500010;

char s[N];
int l[N], r[N];
int n;
LL res;

int main() {
    cin >> n >> s;
    // ͳ��ÿ��ţ����ж��ٸ�������ͬ�����ţ
    int h, g = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') l[i] = h, h = 0, g++;
        else l[i] = g, g = 0, h++;
    }
    // ͳ��ÿ��ţ�ұ��ж��ٸ������Ĳ�ͬ�����ţ
    h = g = 0;
    for (int i = n -1; i >= 0; i--) {
        if (s[i] == 'G') r[i] = h, h = 0, g++;
        else r[i] = g, g = 0, h++;
    }
    for (int i = 0; i < n; i++) {
        if (l[i] + r[i] >= 2) {
            // �¶���ţ���м�����
            res += (LL)l[i] * r[i];
            // �¶���ţ����������
            if (l[i] > 0) res += l[i] - 1;
            if (r[i] > 0) res += r[i] - 1; 
        }
    }
    cout << res << endl;
    return 0;
}