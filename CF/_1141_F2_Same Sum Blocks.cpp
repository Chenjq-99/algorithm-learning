#include<bits/stdc++.h>
using namespace std;

const int N = 1510, INF = 0x3f3f3f3f;
int s[N];
typedef vector<pair<int,int>> VPII;
unordered_map<int, VPII> mp;


/*
https://codeforces.com/problemset/problem/1141/F2

���� n(��1500) �ͳ�Ϊ n ������ a(-1e5��a[i]��1e5)���±�� 1 ��ʼ��

����Ҫ�� a ��ѡ��������ķǿ����������飬��Щ�����鲻���ص�����Ԫ�غ���ȡ�
���������ĸ��� k��Ȼ����� k �У�ÿ����������ʾ����������Ҷ˵㡣
���԰�����˳����������ַ��������������һ�֡�

����
7
4 1 2 2 1 5 3
���
3
7 7
2 3
4 5
*/

/*
����ͳ��ÿ��������ĺͣ��ù�ϣ��Ѻ���ͬ�����������Ҷ˵��¼������
����ÿһ�飬��������಻�ص��߶θ�����
���Ǹ�����̰�ģ������Ҷ˵��С��������+������һ��������˵������һ����¼���Ҷ˵㣬�𰸼�һ�������Ҷ˵㡣
*/
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    for (int r = 1; r <= n; r++)
        for (int l = 1; l <= r; l++)
            mp[s[r] - s[l - 1]].push_back({l, r});
            
    int res = 0;
    VPII record;
    for (auto &it : mp) {
        int cnt = 0, end = -INF;
        VPII tempRecord;
        for (auto &[l, r] : it.second)
            if (l > end) cnt++, end = r, tempRecord.push_back({l, r});
        if (res < cnt) {
            res = cnt;
            record = move(tempRecord);
        }
    }
    cout << res <<endl;
    for (auto &[l, r] : record) cout << l << " " << r << endl;
    return 0;
}