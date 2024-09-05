
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c, x, y, z;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        int xmax = sqrt(c) ;
        int flag = 0;
        for(x = -xmax; x <= xmax; x++) {
            int x2 = x * x;
            if(x2 <= c) {
                for(y = x + 1; y <= xmax; y++) {
                    int y2 = y * y;
                    if(x2 + y2 <= c) {
                        z = a - x - y;
                        if(y < z && x * y * z == b && x2 + y2 + z * z == c) {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
        }
        if(flag)
            cout << x << " " << y << " " << z << endl;
        else
            cout << "No solution.\n";
    }

    return 0;
}
