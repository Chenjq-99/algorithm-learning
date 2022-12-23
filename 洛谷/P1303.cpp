#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> mul(vector<int>& A, vector<int>& B) {
    vector<int> C(100000);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
            C[i + j + 1] += C[i + j] / 10;
            C[i + j] %= 10;
        }
    }
    int n = A.size() + B.size();
    while (n >= 1 && C[n] == 0) n--;
    return vector<int>(C.begin(), C.begin() + n + 1);
}

int main() {
    string a, b;
    cin>>a>>b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout<<C[i];
    return 0;
}