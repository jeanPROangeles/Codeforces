#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, a1, a2, b1, b2, suneetwin;
    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        suneetwin = 0;
        if (a1 > b1 && a2 > b2) suneetwin++;
        if (a1 == b1 && a2 > b2) suneetwin++;
        if (a1 > b1 && a2 == b2) suneetwin++;
        if (a1 > b2 && a2 > b1) suneetwin++;
        if (a1 == b2 && a2 > b1) suneetwin++;
        if (a1 > b2 && a2 == b1) suneetwin++;
        if (a2 > b1 && a1 > b2) suneetwin++;
        if (a2 == b1 && a1 > b2) suneetwin++;
        if (a2 > b1 && a1 == b2) suneetwin++;
        if (a2 > b2 && a1 == b1) suneetwin++;
        if (a2 > b2 && a1 > b1) suneetwin++;
        if (a2 == b2 && a1 > b1) suneetwin++;
        cout << suneetwin << endl;
    }
}