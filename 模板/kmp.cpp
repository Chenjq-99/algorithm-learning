
// kmp
int nxt[100010], f[100010]; // nxt[i]��ʾp[1~i]�������ǰ��׺���ȣ�f[i]��ʾs[1~i]�������ǰ��׺����
int m, n; // mΪp�ĳ��ȣ�nΪs�ĳ���
char s[100010], p[100010]; // sΪ������pΪģʽ��

void kmp() {
    //�ַ����±��1��ʼ
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    for (int i = 1, j= 0; i <= n; i++) {
        while (j == m || j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
            f[i] = j;
    }
}

void kmp() {
    // pҪ��������С
    p[m + 1] = '#'; // ��������s��p
    for (int i = m + 2, j = 1; i <= m + n + 1; i++, j++) 
        p[i] = s[j];
    for (int i = 2, j = 0; i <= m + n + 1; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    // �ӵ�m + 2�±꿪ʼ����s����Ӧ��ƥ�䳤��
}