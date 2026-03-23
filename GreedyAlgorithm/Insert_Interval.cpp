#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;

    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    res.push_back(newInterval);

    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cout << "Enter new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    cout << "Result intervals:\n";
    for (auto &it : result) {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}