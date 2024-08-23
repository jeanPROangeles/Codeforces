#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    if (n < 26) {
        cout << "NO";
    } else {
        string a;
        cin >> a;
        set<char> s;
        
        for (int i = 0; i < n; i ++ ) {
            if (a[i] >= 'A' && a[i] <= 'Z')
                a[i] = a[i] - 'A' + 'a';
            s.insert(a[i]);
        }
        
        if (s.size() == 26) puts("YES");
        else puts("NO");
    }
    
    return 0;
}