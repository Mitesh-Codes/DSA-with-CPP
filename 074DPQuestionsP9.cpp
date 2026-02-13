#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Question 15: Rducing Dishes
//Approach 1: By Recursion
//Time Complexity: O(2^N), Space Complexity: O(N) for recursion stack
int solve(vector<int>& satisfaction,int index,int time){
        if(index==satisfaction.size()){
            return 0;
        }
        int include=satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1);
        int exclude=0+solve(satisfaction,index+1,time);
        return max(include,exclude);
    }
//Approach 2: By Memoization
//Time Complexity: O(N^2), Space Complexity: O(N^2) + O(N) for recursion stack
    int solveMem(vector<int>& satisfaction,int index,int time,vector<vector<int>>&dp){
        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1) return dp[index][time];
        int include=satisfaction[index]*(time+1)+solveMem(satisfaction,index+1,time+1,dp);
        int exclude=0+solveMem(satisfaction,index+1,time,dp);
        dp[index][time]=max(include,exclude);
        return dp[index][time];
    }
//Approach 3: By Tabulation
//Time Complexity: O(N^2), Space Complexity: O(N^2)
    int solveTab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+dp[index+1][time+1];
                int exclude=0+dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
//Approach 4: By Space Optimization
//Time Complexity: O(N^2), Space Complexity: O(N)
    int solveSO(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+next[time+1];
                int exclude=0+next[time];
                curr[time]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];
    }



    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        //return solve(satisfaction,0,0);

        // int n=satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);
        
        //return solveTab(satisfaction);

        return solveSO(satisfaction);
    }


//Approach 5: By Greedy
//Time Complexity: O(NlogN), Space Complexity: O(1)
int maxSatisfaction2(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int suffixSum = 0;   
    int ans = 0;         
    for(int i = satisfaction.size()-1; i >= 0; i--){
        suffixSum += satisfaction[i];
        if(suffixSum <= 0) break;
        ans += suffixSum;
    }
    return ans;
}


int main(){

//Question15: Reducing Dishes
    vector<int> satisfaction={-1,-8,0,5,-9};
    cout<<maxSatisfaction(satisfaction)<<endl;

    //Approach 5: By Greedy
    cout<<maxSatisfaction2(satisfaction2)<<endl;



    return 0;
}