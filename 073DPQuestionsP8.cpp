#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Question13: Minimum Score Triangulation
//Approach 1: By Recursion
//Time Complexity: O(2^n) + O(4^n) for the loop, Space Complexity: O(n)
/*
 int solve(vector<int>&v,int i,int j){
        if(i+1==j){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
        }
        return ans;
}

//Approach 2: By Memoization
//TC: O(n^3), SC: O(n^2)+O(n)
int solveMem(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    if(i+1==j){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[j]*v[k]+solveMem(v,i,k,dp)+solveMem(v,k,j,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}

//Approach 3: By Tabulation
//TC: O(n^3), SC: O(n^2)
int solveTab(vector<int>&v){
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
                
            }
        }
        return dp[0][n-1];
    }


int minScoreTriangulation(vector<int>& values) {
    int n=values.size();
    // return solve(values,0,n-1);
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // return solveMem(values,0,n-1,dp);
    return solveTab(values);

}

*/

//Question14: Minimum Sideway Jumps
//Approach 1: By Recursion
//TC: O(2^n), SC: O(n)
int solve(vector<int>& obstacles,int currlane,int currpos){
        int n=obstacles.size();
        if(currpos==n) return 0;
        if(obstacles[currpos+1]!=currlane){
            return solve(obstacles,currlane,currpos+1);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans,1+solve(obstacles,i,currpos));
                }
            }
            return ans;
        }
    }
//Approach 2: By Memoization
//TC: O(n), SC: O(n) 
    int solveMem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>&dp){
        int n=obstacles.size()-1;
        if(currpos==n) return 0;

        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];

        if(obstacles[currpos+1]!=currlane){
            return solveMem(obstacles,currlane,currpos+1,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans,1+solveMem(obstacles,i,currpos,dp));
                }
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];
        }
    }
//Approach 3: By Tabulation
//TC: O(n), SC: O(n)
    int solveTab(vector<int>&obstacles){
        int n=obstacles.size()-1;
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),1e9));
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(obstacles[currpos+1]!=currlane){
                    dp[currlane][currpos]= dp[currlane][currpos+1];
                }
                else{
                int ans=1e9;
                for(int i=1;i<=3;i++){
                    if(currlane!=i && obstacles[currpos]!=i){
                        ans=min(ans,1+dp[i][currpos+1]);
                    }
                }
                dp[currlane][currpos]= ans;
                }
            }
        }
        return min(dp[2][0],1+min(dp[1][0],1+dp[3][0]));
    }
//Approach 4: By Space Optimization
//TC: O(n), SC: O(3) or O(1)
    int solveSO(vector<int>&obstacles){
        int n=obstacles.size()-1;
        vector<int>curr(4,INT_MAX);
        vector<int>next(4,INT_MAX);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(obstacles[currpos+1]!=currlane){
                    curr[currlane]= next[currlane];
                }
                else{
                int ans=1e9;
                for(int i=1;i<=3;i++){
                    if(currlane!=i && obstacles[currpos]!=i){
                        ans=min(ans,1+next[i]);
                    }
                }
                curr[currlane]= ans;
                }
            }
            next=curr;
        }
        return min(next[2],1+min(next[1],1+next[3]));
    }

int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        // return solveMem(obstacles,2,0,dp);
        //return solveTab(obstacles);
        return solveSO(obstacles);
}



int main(){

//Question13: Minimum Score Triangulation
    // vector<int>values={1,3,1,4,1,5};
    // cout<<minScoreTriangulation(values)<<endl; 
    
//Question14: Minimum Sideway Jumps
    vector<int>obstacles={0,1,2,3,0};
    cout<<minSideJumps(obstacles)<<endl;
    

    return 0;
}