/*
El código proporcionado resuelve el problema de encontrar la mayor expresión aritmética posible con cuatro cartas que no exceda 24. 
Primero, se inicializa maxValue a 0 y se define un multiset para las cartas. La función findMaxValue toma una mano de cartas y,
si solo queda una carta, actualiza maxValue si esta es mayor que el valor actual y menor o igual a 24. Si hay más de una carta, 
la función itera sobre todas las combinaciones posibles de dos cartas, realiza operaciones aritméticas (suma, resta, multiplicación y división entera)
y llama recursivamente a sí misma con la nueva mano resultante. 
*/

#include <bits/stdc++.h>
using namespace std;

int maxValue = 0;
multiset<int> cards;

void findMaxValue(multiset<int> currentHand) {
    if (currentHand.size() == 1) {
        int value = *currentHand.begin();
        if (value > maxValue && value <= 24) {
            maxValue = value;
        }
    } else {
        for (auto it1 = currentHand.begin(); it1 != currentHand.end(); ++it1) {
            auto it2 = next(it1);
            for (; it2 != currentHand.end(); ++it2) {
                int num1 = *it1;
                int num2 = *it2;

                multiset<int> tempHand = currentHand;
                tempHand.erase(tempHand.find(num1));
                tempHand.erase(tempHand.find(num2));

                vector<int> results = {num1 + num2, num1 - num2, num2 - num1, num1 * num2};
                if (num2 != 0 && num1 % num2 == 0) results.push_back(num1 / num2);
                if (num1 != 0 && num2 % num1 == 0) results.push_back(num2 / num1);

                for (int result : results) {
                    tempHand.insert(result);
                    findMaxValue(tempHand);
                    tempHand.erase(tempHand.find(result));
                }
            }
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        for (int i = 0; i < 4; ++i) {
            int card;
            cin >> card;
            cards.insert(card);
        }

        findMaxValue(cards);

        cout << maxValue << '\n';

        maxValue = 0;
        cards.clear();
    }

    return 0;
}
