#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    for (int i = 0; i < N; ++i) {
        string input;
        getline(cin, input);

        if (input == "P=NP") {
            cout << "skipped" << endl;
        } else {
            size_t plusPos = input.find('+');
            int a = stoi(input.substr(0, plusPos));
            int b = stoi(input.substr(plusPos + 1));
            cout << a + b << endl;
        }
    }

    return 0;
}
