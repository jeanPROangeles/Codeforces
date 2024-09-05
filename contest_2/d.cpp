#include <bits/stdc++.h>
using namespace std;

/*
Para verificar si un número es válido, convierto el número a una cadena y utilizo un mapa que define los movimientos permitidos para cada dígito.
Luego, recorro la cadena del número y verifico que cada dígito puede ser seguido por el siguiente según las restricciones del mapa.
Si el número ingresado no es válido, el programa busca el número más cercano sumando o restando un desplazamiento (offset). 
Este proceso se repite hasta encontrar un número válido. Finalmente, el programa imprime el número válido más cercano.
*/
bool isValid(int number) {
    string numStr = to_string(number);
    unordered_map<char, string> keypad = {
        {'1', "1234567890"},
        {'2', "2356890"},
        {'3', "369"},
        {'4', "4567890"},
        {'5', "56890"},
        {'6', "69"},
        {'7', "7890"},
        {'8', "890"},
        {'9', "9"},
        {'0', "0"}
    };
    bool valid = true;
    for (int i = 0; i < numStr.length() - 1; ++i) {
        valid = valid && (keypad[numStr[i]].find(numStr[i + 1]) != string::npos);
    }
    return valid;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int inputNumber;
        cin >> inputNumber;
        int offset = 0;
        while (!isValid(inputNumber + offset) && !isValid(inputNumber - offset)) {
            ++offset;
        }
        if (isValid(inputNumber + offset)) {
            cout << inputNumber + offset << endl;
        } else {
            cout << inputNumber - offset << endl;
        }
    }
    return 0;
}
