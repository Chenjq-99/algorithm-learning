// C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 判断是否有 A >= B
bool cmp (vector<int>& A, vector<int>& B) {
    
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i++) {
        if(A[i] != B[i]) return A[i] > B[i];
    }

    return true;
}

// 一定要保证 A >= B
vector<int> sub (vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0; // 借位
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i]; 
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1; // 向上一位借位
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 去掉前导零
    return C;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    } else {
        auto C = sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
}
