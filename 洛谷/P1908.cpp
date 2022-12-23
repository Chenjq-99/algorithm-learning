#include<iostream>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
int q[N], tmp[N];
int n;

ll merge_sort (int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1, i = l, j = mid + 1, k = 0;
    ll cnt = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            cnt += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k];
    return cnt;
}
int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    ll cnt = merge_sort(q, 0, n - 1);
    printf("%lld", cnt);
    return 0;
}