#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& dp, vector<int>& height, int k) {
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int minCost = INT_MAX;
    for (int jump = 1; jump <= k; ++jump) {
        if (n - jump >= 0) {
            int cost = solve(n - jump, dp, height, k) + abs(height[n] - height[n - jump]);
            minCost = min(minCost, cost);
        }
    }

    return dp[n] = minCost;
}

int minCostClimbingStairs(vector<int>& cost, int k) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return solve(n - 1, dp, cost, k);
}

int main() {
    vector<int> height = {10, 30, 40, 20};
    int k = 3; // Maximum steps the frog can jump
    cout << "Minimum Cost: " << minCostClimbingStairs(height, k) << endl;
    return 0;
}