#include<iostream>
#include <vector>
using namespace std;


int solve(int n, vector<int>& dp, vector<int>& height) {
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    int jumpOne = solve(n-1,dp,height) + abs(height[n]-height[n-1]);
    int jumpTwo = solve(n-2,dp,height) + abs(height[n]-height[n-2]);

    return dp[n] = min(jumpOne,jumpTwo);
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1,-1);
    return solve(n-1,dp,cost);
}

int main(){
    vector<int> height = {10, 30, 40, 20};
    cout << "Minimum Cost: " << minCostClimbingStairs(height) << endl;
    return 0;
}