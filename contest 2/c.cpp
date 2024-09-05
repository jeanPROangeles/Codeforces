#include <bits/stdc++.h>
using namespace std;
int main() {

    int n, s, r;
    cin >> n >> s >> r;

    vector<bool> works(n, true);

    for(int i = 0; i < s; i++) {
        int t;
        cin >> t;
        t--;
        works[t] = false;
    }

    set<int> extra;
    for(int i = 0; i < r; i++) {
        int t;
        cin >> t;
        t--;
        extra.insert(t);
    }

    for(int i = 0; i < n; i++) {
        if(works[i]) continue;

        if(extra.count(i-1) > 0) {
            works[i] = true;
            extra.erase(i-1);
            continue;
        }
        if(extra.count(i) > 0) {
            works[i] = true;
            extra.erase(i);
            continue;
        }
        if(extra.count(i+1) > 0) {
            works[i] = true;
            extra.erase(i+1);
            continue;
        }
    }

    int bad = 0;
    for(auto i : works) {
        if(!i) {
            bad++;
        }
    }

    cout << bad << endl;
    return 0;
} 