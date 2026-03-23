#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int,int>> meetings;

    // store (end, start)
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }

    // sort by end time
    sort(meetings.begin(), meetings.end());

    int count = 1;
    int lastEnd = meetings[0].first;

    for (int i = 1; i < n; i++) {
        if (meetings[i].second > lastEnd) {
            count++;
            lastEnd = meetings[i].first;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    int start[n], end[n];

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    cout << "Enter end times:\n";
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    int result = maxMeetings(start, end, n);

    cout << "Maximum meetings that can be performed: " << result << endl;

    return 0;
}