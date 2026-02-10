#include<iostream>
#include<vector>
#include<climits>
#define MOD 1000000007
using namespace std;

//Question6: Count Derangements
//Approach1:By dynamic programming with memoization
//Time complexity: O(n)  Space complexity: O(n)
long long int solveMem(int n,vector<long long int>&dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=(((n-1)%MOD)*((solveMem(n-1,dp)%MOD)+(solveMem(n-2,dp)%MOD))%MOD);
    return dp[n];
}
long long int countDerangements(int n) {
    vector<long long int>dp(n+1,-1);
    return solveMem(n,dp);
}

//Approach2:By dynamic programming with tabulation
//Time complexity: O(n)  Space complexity: O(n)
long long solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1]= 0;
    dp[2]= 1;
    for(int i=3;i<=n;i++){
      long long int first=dp[i-1]%MOD;
      long long int second=dp[i-2]%MOD;
      long long int sum=(first+second)%MOD;
      long long int ans=((i-1)*sum)%MOD;
      dp[i]=ans; 
    }
    return dp[n];
}

long long int countDerangements2(int n) {
    return solveTab(n);
    
}

//Approach3:By dynamic programming with space optimization
//Time complexity: O(n)  Space complexity: O(1)
long long solveSO(int n){
    long long int prev2= 0;
    long long int prev1= 1;
    for(int i=3;i<=n;i++){
      long long int first=prev1%MOD;
      long long int second=prev2%MOD;
      long long int sum=(first+second)%MOD;
      long long int ans=((i-1)*sum)%MOD;
      prev2=prev1;
      prev1=ans; 
    }
    return prev1;
}
long long int countDerangements3(int n) {
    return solveSO(n);
}



//Question7: Painting Fence Algorithm
//Approach1:By recursion
//Time complexity: O(2^n)  Space complexity: O(n)
int add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

int solve(int n, int k){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));

    int ans=add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n,k);
}

//Approach2:By dynamic programming with memoization
//Time complexity: O(n)  Space complexity: O(n)
int solveMem(int n, int k,vector<int>&dp){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));

    if(dp[n]!=-1) return dp[n];

    dp[n]=add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}

int numberOfWays2(int n, int k) {
    vector<int>dp(n+1,-1);
    return solveMem(n,k,dp);
}

//Approach3:By dynamic programming with tabulation
//Time complexity: O(n)  Space complexity: O(n)
int solveTab(int n, int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int numberOfWays3(int n, int k) {
    return solveTab(n,k);
}

//Approach4:By dynamic programming with space optimization
//Time complexity: O(n)  Space complexity: O(1)
int solveSO(int n, int k){
    int prev2=k;
    int prev1=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        int ans=add(mul(prev2,k-1),mul(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;

}
int numberOfWays4(int n, int k) {
   
    return solveSO(n,k);
}





int main(){

    
//Question6: Count Derangements
//Approach1:By dynamic programming with memoization
    int n=5;
    cout<<countDerangements(n)<<endl;

//Appro2:By dynamic programming with tabulation
    cout<<countDerangements2(n)<<endl;

//Appro3:By dynamic programming with space optimization
    cout<<countDerangements3(n)<<endl;


//Question7: Painting Fence Algorithm
//Approach1:By recursion
    int m=3;
    cout<<numberOfWays(n,m)<<endl;
//Approach2:By dynamic programming with memoization
    cout<<numberOfWays2(n,m)<<endl;
//Approach3:By dynamic programming with tabulation
    cout<<numberOfWays3(n,m)<<endl;
//Approach4:By dynamic programming with space optimization
    cout<<numberOfWays4(n,m)<<endl;
    





    return 0;
}