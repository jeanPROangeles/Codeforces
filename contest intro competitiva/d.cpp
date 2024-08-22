#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                if (idx < t.size()) {
                    s[i] = t[idx++];
                } else {
                    s[i] = 'j';
                }
            } else if (s[i] == t[idx]) {
                idx++;
            }
        }
        if (idx >= t.size()) {
            cout << "YES" << endl << s << endl;
        } else cout << "NO" << endl;
    }
}