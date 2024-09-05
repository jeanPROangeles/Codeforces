/*
El código proporcionado resuelve el problema de determinar si existe una asignación de dígitos a letras que haga que la suma de dos palabras sea igual a una tercera palabra.
Primero, se define la función isValidMapping que verifica si una asignación específica de dígitos a letras cumple con la condición de suma.
Luego, la función solve genera todas las permutaciones posibles de dígitos para las letras únicas en las tres palabras y verifica cada permutación usando isValidMapping.
Si se encuentra una asignación válida, se imprime la asignación y se retorna true. Si no se encuentra ninguna asignación válida, se imprime “UNSOLVABLE”.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidMapping(const string &s1, const string &s2, const string &s3, const vector<int> &mapping) {
    if (mapping[s1[0] - 'a'] == 0 || mapping[s2[0] - 'a'] == 0 || mapping[s3[0] - 'a'] == 0) {
        return false; 
    }
    long long n1 = 0, n2 = 0, n3 = 0;
    for (char c : s1) n1 = n1 * 10 + mapping[c - 'a'];
    for (char c : s2) n2 = n2 * 10 + mapping[c - 'a'];
    for (char c : s3) n3 = n3 * 10 + mapping[c - 'a'];
    return n1 + n2 == n3;
}

bool solve(const string &s1, const string &s2, const string &s3) {
    vector<bool> used(26, false);
    for (char c : s1 + s2 + s3) used[c - 'a'] = true;

    vector<int> unique_chars;
    for (int i = 0; i < 26; ++i) {
        if (used[i]) unique_chars.push_back(i);
    }
    if (unique_chars.size() > 10) return false;

    vector<int> digits(10);
    iota(digits.begin(), digits.end(), 0);
    do {
        vector<int> mapping(26, -1);
        for (int i = 0; i < unique_chars.size(); ++i) {
            mapping[unique_chars[i]] = digits[i];
        }
        if (isValidMapping(s1, s2, s3, mapping)) {
            for (char c : s1) cout << mapping[c - 'a'];
            cout << endl;
            for (char c : s2) cout << mapping[c - 'a'];
            cout << endl;
            for (char c : s3) cout << mapping[c - 'a'];
            cout << endl;
            return true;
        }
    } while (next_permutation(digits.begin(), digits.end()));
    return false;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (!solve(s1, s2, s3)) {
        cout << "UNSOLVABLE" << endl;
    }
    return 0;
}
