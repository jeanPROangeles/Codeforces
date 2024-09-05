#include <bits/stdc++.h>

using namespace std;

long int sum[1000010];

int main() {
    long int n, m, i, j, k, number[1050], query, min, dist, t = 0, close;

    while (scanf("%ld", &n) == 1) {
        if (n == 0)
            break;
        t += 1;
        for (i = 0; i < n; i++)
            scanf("%ld", &number[i]);
        
        k = 0;
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
                sum[k++] = number[i] + number[j];

        scanf("%ld", &m);
        printf("Case %ld:\n", t);
        for (i = 1; i <= m; i++) {
            scanf("%ld", &query);
            min = 2147483647;
            for (j = 0; j < k; j++) {
                dist = abs(query - sum[j]);
                if (min > dist) {
                    min = dist;
                    close = sum[j];
                }
            }
            printf("Closest sum to %ld is %ld.\n", query, close);
        }
    }
    return 0;
}
