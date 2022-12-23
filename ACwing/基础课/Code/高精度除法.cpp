// C++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// r 用引用传递
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    // 从最高位开始计算
    for (int i = A.size(); i >= 0; i++) {
        r = r * 10 + A[i]; // 本轮的被除数
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main() {
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    int r = 0;
    vector<int> C = div(A, b, r);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    printf("\n%d\n", r);
}
