#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

string add (string& A, string& B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int t = 0;
    string C = "";
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i] - '0';
        if (i < B.size()) t += B[i] - '0';
        C += t % 10 + '0';
        t /= 10;
    }
    if (t) C += t + '0';
    reverse(C.begin(), C.end());
    return C;
}
int main() {
    string A, B;
    cin>>A>>B;
    cout<<add(A,B);
    return 0;
}