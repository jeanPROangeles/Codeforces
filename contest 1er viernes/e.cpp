#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Función para eliminar espacios en blanco al inicio y al final de una cadena
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";  // Si la cadena está vacía o solo tiene espacios

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignorar el salto de línea después de leer N

    for (int i = 0; i < N; ++i) {
        string input;
        getline(cin, input);  // Leer toda la línea de entrada

        // Eliminar espacios en blanco al inicio y al final
        input = trim(input);

        if (input == "P=NP") {
            cout << "skipped" << endl;
        } else {
            size_t plus_sign = input.find('+');  // Encontrar la posición del '+'
            if (plus_sign != string::npos) {
                try {
                    int a = stoi(input.substr(0, plus_sign));  // Convertir la primera parte a entero
                    int b = stoi(input.substr(plus_sign + 1));  // Convertir la segunda parte a entero
                    cout << a + b << endl;
                } catch (const invalid_argument &e) {
                    cerr << "Error: invalid argument encountered" << endl;
                } catch (const out_of_range &e) {
                    cerr << "Error: number out of range" << endl;
                }
            } else {
                cerr << "Error: input format invalid" << endl;
            }
        }
    }
    return 0;
}
 