#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;   // train arrives
            i++;
        } else {
            platforms--;   // train departs
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    cout << maxPlatforms << endl;
    return 0;
}