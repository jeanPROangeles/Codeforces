#include <bits/stdc++.h>
using namespace std;
struct Event {
    char team;
    int points;
    int time;
};

int convertToSeconds(const std::string& timeStr) {
    int minutes = stoi(timeStr.substr(0, timeStr.find(':')));
    int seconds = stoi(timeStr.substr(timeStr.find(':') + 1));
    return minutes * 60 + seconds;
}

string convertToTimeStr(int seconds) {
    int minutes = seconds / 60;
    seconds = seconds % 60;
    std::ostringstream oss;
    if (minutes < 10) {
        oss << minutes << ":" << setw(2) << setfill('0') << seconds;
    } else {
        oss << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    }
    return oss.str();
}

int main() {
    int N;
    cin >> N;
    vector<Event> events(N);

    for (int i = 0; i < N; ++i) {
        string team;
        int points;
        string timeStr;
        cin >> team >> points >> timeStr;
        events[i] = {team[0], points, convertToSeconds(timeStr)};
    }

    int homeScore = 0, awayScore = 0;
    int lastTime = 0;
    int homeLeadTime = 0, awayLeadTime = 0;
    char leadingTeam = 'N';

    for (const auto& event : events) {
        if (leadingTeam == 'H') {
            homeLeadTime += event.time - lastTime;
        } else if (leadingTeam == 'A') {
            awayLeadTime += event.time - lastTime;
        }

        if (event.team == 'H') {
            homeScore += event.points;
        } else {
            awayScore += event.points;
        }

        if (homeScore > awayScore) {
            leadingTeam = 'H';
        } else if (awayScore > homeScore) {
            leadingTeam = 'A';
        } else {
            leadingTeam = 'N';
        }

        lastTime = event.time;
    }

    if (leadingTeam == 'H') {
        homeLeadTime += 32 * 60 - lastTime;
    } else if (leadingTeam == 'A') {
        awayLeadTime += 32 * 60 - lastTime;
    }

    string winner = (homeScore > awayScore) ? "H" : "A";
    cout << winner << " " << convertToTimeStr(homeLeadTime) << " " << convertToTimeStr(awayLeadTime) << endl;

    return 0;
}
