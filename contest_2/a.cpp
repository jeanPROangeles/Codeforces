/*Creo un vector sumCounts de tamaño N + M + 1 inicializado en 0. Este vector se usará para contar cuántas veces aparece cada posible suma de los dos dados.
Utilizo dos bucles anidados para simular el lanzamiento de los dos dados. Para cada combinación de caras (i, j), incremento el contador correspondiente en sumCounts[i + j].
Utilizo max_element para encontrar el valor máximo en el vector sumCounts, que representa el número máximo de ocurrencias de cualquier suma.
Finalmente recorre el vector sumCounts e imprimo las sumas que tienen el número máximo de ocurrencias*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> sumCounts(N + M + 1, 0);

    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            sumCounts[i + j]++;
        }
    }

    
    int maxCount = *max_element(sumCounts.begin(), sumCounts.end());

    
    for (int sum = 2; sum <= N + M; ++sum) {
        if (sumCounts[sum] == maxCount) {
            cout << sum << endl;
        }
    }

    return 0;
}