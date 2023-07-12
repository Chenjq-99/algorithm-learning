
// exkmp
// s[1..n] Ϊģʽ����t[1..m] Ϊ����
// z[i] ��ʾ s[i..n] �� t �������ǰ׺

int z[100010], n, m;
char s[100010], t[100010];

void exkmp() {
    int L = 1, R = 1;
    z[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= R) 
            z[i] = min(R - i + 1, z[i - L + 1]);
        while (i + z[i] <= n && s[i + z[i]] == t[1 + z[i]]) 
            z[i]++;
        if (i + z[i] - 1 > R) 
            L = i, R = i + z[i] - 1;
    }
}