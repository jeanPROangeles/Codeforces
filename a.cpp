#include <bits/stdc++.h>
using namespace std;
int main() {
int t, n, unidades, decenas;
cin >> t;
while (t--) {
    cin >> n;
        unidades = n%10;
        decenas = n/10;
        cout << unidades + decenas << endl; 
    }
}