#include <bits/stdc++.h>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

Time parseTime(const string& timeStr) {
    Time t;
    sscanf(timeStr.c_str(), "%d:%d:%d", &t.hours, &t.minutes, &t.seconds);
    return t;
}

int toSeconds(const Time& t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time toTime(int totalSeconds) {
    Time t;
    t.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    t.minutes = totalSeconds / 60;
    t.seconds = totalSeconds % 60;
    return t;
}

Time calculateTimeDifference(const Time& currentTime, const Time& explosionTime) {
    int currentSeconds = toSeconds(currentTime);
    int explosionSeconds = toSeconds(explosionTime);

    int diffSeconds = explosionSeconds - currentSeconds;
    if (diffSeconds <= 0) {
        diffSeconds += 24 * 3600; 
    }

    return toTime(diffSeconds);
}

int main() {
    string currentTimeStr, explosionTimeStr;
    cin >> currentTimeStr >> explosionTimeStr;

    Time currentTime = parseTime(currentTimeStr);
    Time explosionTime = parseTime(explosionTimeStr);

    Time timeDifference = calculateTimeDifference(currentTime, explosionTime);

    cout << setfill('0') << setw(2) << timeDifference.hours << ":"
         << setfill('0') << setw(2) << timeDifference.minutes << ":"
         << setfill('0') << setw(2) << timeDifference.seconds << endl;

    return 0;
}
    