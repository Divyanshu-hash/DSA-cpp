#include <bits/stdc++.h>
using namespace std;

long long solve(int i, vector<int>& arr, vector<long long>& dp) {
    // Base case
    if (i < 0) return 0;

    // Already computed
    if (dp[i] != -1) return dp[i];

    // Choices
    long long take = arr[i] + solve(i - 2, arr, dp);
    long long skip = solve(i - 1, arr, dp);

    return dp[i] = max(take, skip);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> dp(n, -1);

    cout << solve(n - 1, arr, dp) << endl; 
    return 0;
}