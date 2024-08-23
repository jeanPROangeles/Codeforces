#include <bits/stdc++.h>
using namespace std;
char a;
int b[18];
int main()
{
    int k,f=1;
    cin >> k;
        memset(b,0,sizeof(b));
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                cin>>a;
                if(a!='.')
                    b[a-'0']++;
            }
        for(int i=1; i<18; i++)
        {
            if(b[i]>2*k)
                f=0;
        }
        if(f)
            puts("YES");
        else
            puts("NO");
    return 0;
}
 