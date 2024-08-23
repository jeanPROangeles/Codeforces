#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int, int> votes;

    for (int i = 0; i < N; ++i) {
        int vote;
        cin >> vote;
        votes[vote]++;
    }

    int min_students = 0;
    for (const auto& pair : votes) {
        int group_size = pair.first + 1;
        int count = pair.second;
        min_students += ceil(static_cast<double>(count) / group_size) * group_size;
    }

    cout << min_students << endl;
    return 0;
}
