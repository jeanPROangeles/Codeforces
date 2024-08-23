#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int cnt = 0;
    cin >> T;
    while (T--) {
        int a, b, c, least, most;
        vector <int> v(2);
        cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        least = min(min(a,b),c);
        most = max(max(a,b),c);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
        v.erase(remove(v.begin(),v.end(),least), v.end());
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
        v.erase(remove(v.begin(),v.end(),most), v.end());
        cout << "Case " << ++cnt << ": " << v[2] << endl;
    }
}