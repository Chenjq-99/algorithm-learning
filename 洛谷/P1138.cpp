#include<bits/stdc++.h>
using namespace std;

int n, k;
int q[10001], newq[10001];
bool f[30001];

int quick_select(int q[], int l, int r, int k) {
    if (l >= r) return q[l];
    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    int left = j - l + 1;
    if (k <= left) return quick_select(q, l, j, k);
    else return quick_select(q, j + 1, r, k - left);
}
int main () {
    cin>>n>>k;
    for (int i = 0; i < n; i++) cin>>q[i];
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (f[q[i]] == false) {
            newq[num++] = q[i];
            f[q[i]] = true;
        }
    }
    if (k > num) cout<<"NO RESULT";
    else cout<<quick_select(newq, 0, num-1, k);
    return 0;
}