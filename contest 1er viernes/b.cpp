/*
Verifico si la configuración de caballos en un tablero de ajedrez de 5x5 es válida.
La función isValidConfiguration recorre el tablero y cuenta los caballos (‘k’).
Si encuentra un caballo, verifica todas las posibles posiciones de ataque de un caballo en un movimiento de ajedrez.
Si alguna de estas posiciones contiene otro caballo, la configuración es inválida.
Finalmente, la función verifica si hay exactamente 9 caballos en el tablero.
*/

#include <bits/stdc++.h>
using namespace std;

const int moves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValidConfiguration(vector<string>& board) {
    int knightCount = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == 'k') {
                knightCount++;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + moves[k][0];
                    int nj = j + moves[k][1];
                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && board[ni][nj] == 'k') {
                        return false; 
                    }
                }
            }
        }
    }
    return knightCount == 9; 
}

int main() {
    vector<string> board(5);
    for (int i = 0; i < 5; ++i) {
        cin >> board[i];
    }

    if (isValidConfiguration(board)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}
