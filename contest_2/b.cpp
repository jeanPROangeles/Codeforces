#include <bits/stdc++.h>
using namespace std;


/*
El código proporcionado resuelve el problema de colocar ocho reinas en un tablero de ajedrez de 8x8 de manera que ninguna se ataque entre sí, 
considerando que algunas casillas están reservadas y no pueden ser ocupadas por reinas. 
Primero, se inicializan las estructuras necesarias para llevar un seguimiento de las columnas y diagonales ocupadas. Luego, 
se define la función solve que intenta colocar una reina en cada fila, verificando que no haya conflictos en la columna y diagonales.
Si se encuentra una posición válida, se marca como ocupada y se procede a la siguiente fila. Si se completa una configuración válida, se incrementa el contador de soluciones.
*/

int board[8][8];
bool column[8], diag1[15], diag2[15];
int solutions = 0;

void solve(int row) {
    if (row == 8) {
        solutions++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == 0 && !column[col] && !diag1[row + col] && !diag2[row - col + 7]) {
            column[col] = diag1[row + col] = diag2[row - col + 7] = true;
            solve(row + 1);
            column[col] = diag1[row + col] = diag2[row - col + 7] = false;
        }
    }
}

int main() {
    memset(column, 0, sizeof(column));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    for (int i = 0; i < 8; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 8; j++) {
            board[i][j] = (line[j] == '*') ? 1 : 0;
        }
    }
    solve(0);
    cout << solutions << endl;
    return 0;
}
