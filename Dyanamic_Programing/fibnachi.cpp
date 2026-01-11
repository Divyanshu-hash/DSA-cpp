#include<iostream>
#include<vector>
using namespace std;

void f(int n,vector<int> &dp){
    if(n==0){
        dp[0]=1;
        return;
    }
    if(n==1){
        dp[1]=1;
        return;
    }
    if(dp[n]!=-1){
        return;
    }
    f(n-1,dp);
    f(n-2,dp);
    dp[n]=dp[n-1]+dp[n-2];
    return;
}



int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    f(n,dp);
    cout<<dp[n-1]<<endl;
    return 0;
}