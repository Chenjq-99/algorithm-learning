/*
https://codeforces.com/problemset/problem/600/C

�����ַ��� s�����Ȳ����� 2e5����Сд��ĸ��ɡ�

������޸Ķ�� s[i]��ʹ���޸ĺ�� s��ͨ���������У����Եõ����Ĵ���
�������޸� x �Ρ�����޸� x �������ź��ֵ�����С�Ļ��Ĵ���
*/

/*
��ʾ 1���޸ĳ��ִ���Ϊ�������ַ���

��ʾ 2��Ϊ�����ֵ�����С����Щ������ĸҲҪ��Ӧƥ�䡣�� adef �����������Σ���ô�� f �ĳ� a��e �ĳ� d�� 

��ʾ 3��ע�����������������������ʱ���������ǲ���Ҫ�޸ĵġ�
*/
#include<bits/stdc++.h>
using namespace std;
 
string str;
int h[26];
 
int main() {
    cin >> str;
    for (auto &ch : str) h[ch - 'a']++;
    int l = 0, r = 25;
    while (l < r) {
        if ((h[l] & 1) && (h[r] & 1)) h[l++]++, h[r--]--;
        if ((h[l] & 1) == 0) l++;
        if ((h[r] & 1) == 0) r--;
    }
    str = "";
    string s = "";
    for (int i = 0; i < 26; i++) {
        int t = h[i] / 2;
        str += string(t, 'a' + i);
        if (h[i] & 1) s += 'a' + i;
    }
    cout << str + s + string(str.rbegin(), str.rend()) << endl;
    return 0;
}