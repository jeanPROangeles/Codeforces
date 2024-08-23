#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<vector<int>> a(4, vector<int>(2)); 
        for (int i = 0; i < 4; ++i) {
            cin >> a[i][0] >> a[i][1];
        }
        
        vector<int> x(4);
        for (int i = 0; i < 4; ++i) {
            x[i] = a[i][0];
        }
        
        int dx = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
        cout << dx * dx << endl;
    }
    
    return 0;
}
