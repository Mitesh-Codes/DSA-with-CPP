#include<iostream>
#include<vector>
using namespace std;


//Question0: Count Ways To Reach The N-th Stairs
//Time complexity: O(n)  Space complexity: O(1)
int countDistinctWays(int n) {
    const long long MOD = 1000000007;
    
    if(n == 0 || n == 1) return 1;
    
    long long prev2 = 1; // dp[0]
    long long prev1 = 1; // dp[1]
    
    for(int i = 2; i <= n; i++) {
        long long curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

//Question1: Minimum Cost of Climbing Stairs

//Appraoch1:By recursion
//Time complexity: O(2^n)  Space complexity: O(n)
// this method give TLE error for large input because of repeated calculations
int solve(int n,vector<int>&cost){
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    int ans=cost[n]+min(solve(n-1,cost),solve(n-2,cost));
    return ans;
}
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    return min(solve(n-1,cost),solve(n-2,cost));
}

//Appraoch2:By Dynamic Programming
//Time complexity: O(n)  Space complexity: O(n)
int solve2(int n,vector<int>&cost,vector<int>&dp){
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    if(dp[n]!=-1) return dp[n];

    dp[n]=cost[n]+min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
    return dp[n];
}
int minCostClimbingStairs2(vector<int>& cost) {
    int n=cost.size();
    vector<int>dp(n+1,-1);
    return min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
}

//Appraoch3:By Dynamic Programming with Tabulation
//Time complexity: O(n)  Space complexity: O(n)
int solve3(int n,vector<int>&cost){
    vector<int>dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int minCostClimbingStairs3(vector<int>& cost) {
    int n=cost.size();
    return solve3(n,cost);

}

//Appraoch4:By Dynamic Programming with Tabulation and Space Optimization
//Time complexity: O(n)  Space complexity: O(1)
int solve4(int n,vector<int>&cost){
    int prev1=cost[1];
    int prev2=cost[0];
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int minCostClimbingStairs4(vector<int>& cost) {
    int n=cost.size();
    return solve4(n,cost);
}

int main(){


//Question0: Count Ways To Reach The N-th Stairs
    //By Dynamic Programming with Space Optimization
    //cout<<countDistinctWays(5)<<endl;

    
//Question1: Minimum Cost of Climbing Stairs
    //By recursion
    vector<int>cost={10,15,20,25,3};
    //cout<<minCostClimbingStairs(cost)<<endl;

    //By Dynamic Programming
    //cout<<minCostClimbingStairs2(cost)<<endl;

    //By Dynamic Programming with Tabulation
    //cout<<minCostClimbingStairs3(cost)<<endl;

    //By Dynamic Programming with Tabulation and Space Optimization
    cout<<minCostClimbingStairs4(cost)<<endl;


    return 0;
}