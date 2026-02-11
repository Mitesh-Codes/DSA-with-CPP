#include<iostream>
#include<vector>
#include<climits>
using namespace std;


//Question9: Combination Sum IV
//Approach1: By Recursion
//Time Complexity: O(n^tar), Space Complexity: O(tar)
int solve(vector<int>&nums,int tar){
    if(tar==0) return 1;
    if(tar<0) return 0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=solve(nums,tar-nums[i]);
    }
    return ans;
    
}
int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

//Approach2: By Dynamic Programming
//Time Complexity: O(n*tar), Space Complexity: O(tar)
int solveMem(vector<int>&nums,int tar,vector<int>&dp){
    if(tar==0) return 1;
    if(tar<0) return 0;
    
    if(dp[tar]!=-1) return dp[tar];

    int ans=0;

    for(int i=0;i<nums.size();i++){
        ans+=solveMem(nums,tar-nums[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
    
}

int findWays2(vector<int> &num, int tar)
{
    vector<int>dp(tar+1,-1);
    return solveMem(num, tar,dp);
}

//Approach3: By Dynamic Programming with Tabulation
//Time Complexity: O(n*tar), Space Complexity: O(tar)
int solveTab(vector<int>&nums,int tar){
    vector<int>dp(tar+1,0);
    dp[0]= 1;
    
    // for all sub-targets upto target
    for(int i=1;i<=tar;i++){
        //for all numbers in nums
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0){
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[tar];
    
}
int findWays3(vector<int> &num, int tar)
{
    return solveTab(num, tar);
}

//Approach4: By Dynamic Programming with Space Optimization
//its not possible to optimize space in this question as we need to store the results of all sub-targets upto target, 
//so we cannot reduce the space complexity further than O(tar).





//Question 10: Get Minimum Squares
//Approach 1: By Recursion
//Time Complexity: O(2^n), Space Complexity: O(n)
int solve(int n){
        if(n==0) return 0;
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        return ans;
    }
int minSquares(int n) {
    return solve(n);
        
        
}

//Approach 2: By Dynamic Programming
//Time Complexity: O(n*sqrt(n)), Space Complexity: O(n)
int solveMem(int n,vector<int>&dp){
        if(n==0) return 0;
        int ans=n;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solveMem(n-i*i,dp));
            
        }
        dp[n]=ans;
        return dp[n];
    }
int minSquares2(int n) {
    vector<int>dp(n+1,-1);
    return solveMem(n,dp);
        
        
}

//Approach 3: By Dynamic Programming with Tabulation
//Time Complexity: O(n*sqrt(n)), Space Complexity: O(n)
int solveTab(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                int temp=j*j;
                if(i-temp>=0){
                    dp[i]=min(dp[i],1+dp[i-temp]);
                }
            }
            
        }
        
        return dp[n];
}
int minSquares3(int n) {
    return solveTab(n);
        
        
}

//Approach 4: By Dynamic Programming with Space Optimization
//its not possible to optimize space in this question as we need to store the results of all sub-problems upto n, 
//so we cannot reduce the space complexity further than O(n).



int main(){

    
//Question 9: Combination Sum IV
//Approach1: By Recursion
    vector<int> num={1,2,3};
    int tar=4;
    cout<<findWays(num,tar)<<endl;

//Approach2: By Dynamic Programming
    cout<<findWays2(num,tar)<<endl;

//Approach3: By Dynamic Programming with Tabulation
    cout<<findWays3(num,tar)<<endl;


//Question 10: Get Minimum Squares
//Approach1: By Recursion
    int n=12;
    cout<<minSquares(n)<<endl;

//Approach2: By Dynamic Programming
    cout<<minSquares2(n)<<endl;

//Approach3: By Dynamic Programming with Tabulation
    cout<<minSquares3(n)<<endl;




    return 0;
}