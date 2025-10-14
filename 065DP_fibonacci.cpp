#include<bits/stdc++.h>
#include<vector>
using namespace std;



//Method1: TopDown Approach( Recursion + Memoization)
//TC: O(N) SC:O(N)+O(N)
int fib(int n,vector<int>&dp){
    if(n<=1){
            return n;
    }

    if(dp[n]!=-1){
            return dp[n];
    }

    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];

}

int main()
{
    
    //Method1: TopDown Approach( Recursion + Memoization)
    // int n;
    // cin>>n;
    // vector<int>dp(n+1);
    // for(int i=0;i<=n;i++){
    //         dp[i]=-1;
    // }
    // cout<<fib(n,dp)<<endl;


    //Method2: BottomUp Approach (Tabulation)
    //TC: O(N) SC:O(N)
    // int n;
    // cin>>n;

    // vector<int>dp(n+1);
    // dp[1]=1;
    // dp[0]=0;

    // for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;


    //Now By Space Optimization
    //TC: O(N) SC:O(1)
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;

    if(n==0){
        cout<<0<<endl;
        return 0;
    }

    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;


    return 0;
}