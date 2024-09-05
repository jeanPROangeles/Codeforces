#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int A[n];
    int Ans[n];
    int current = INT_MIN;
    int idx = 0;    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] > current) {
            current = A[i];
            Ans[idx++] = A[i];
        } 
    }
    cout << idx << endl;
    for (int i = 0; i < idx; ++i) {
        if (i) cout << ' ';
         cout << Ans[i];
    }   
    cout << endl;
}

