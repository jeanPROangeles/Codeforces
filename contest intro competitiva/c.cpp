#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, s, m;
    cin >> t;
    while (t--) {
        cin >> n >> s >> m;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end()); 
        bool possible = false;
        for (int i = 0; i < n; i++) {
            int dist = 0;
            if (i == 0) {
                dist = arr[i].first; 
            } else {
                dist = arr[i].first - arr[i-1].second;
            } 
            if (dist >= s) {
                cout  << "YES" << endl;
                possible = true;
                break; 
            }
        }
        if (!possible && (m - arr[n-1].second >= s)) cout << "YES" << endl; 
        else if (!possible) cout << "NO" << endl;
    }
    return 0;
}   