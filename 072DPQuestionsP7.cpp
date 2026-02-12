#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//Question11: Minimum cost of tickets
//Approach 1: By Recursion
//Time Complexity: O(2^n), Space Complexity: O(n)
int solve(int n, vector<int>&days, vector<int>&cost,int index){
    if(index>=n){
        return 0;
    }
    int option1=cost[0]+solve(n,days,cost,index+1);
    
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solve(n,days,cost,i);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days,cost,0);
}


//Approach 2: By Dynamic Programming
//Time Complexity: O(n), Space Complexity: O(n)

int solveMem(int n, vector<int>&days, vector<int>&cost,int index,vector<int>&dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    
    int option1=cost[0]+solveMem(n,days,cost,index+1,dp);
    
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solveMem(n,days,cost,i,dp);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solveMem(n,days,cost,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoins2(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solveMem(n,days,cost,0,dp);
}


//Approach 3: By Tabulation
//Time Complexity: O(n), Space Complexity: O(n)
int solveTab(int n, vector<int>&days, vector<int>&cost){
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;
    
    for(int k=n-1;k>=0;k--){
        int option1=cost[0]+dp[k+1];
    
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int option2=cost[1]+dp[i];

        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3=cost[2]+dp[i];

        dp[k]=min(option1,min(option2,option3));
        
    }
    return dp[0];
}

int minimumCoins3(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    
    return solveTab(n,days,cost);
}

//Approach 4: By Space Optimization 
//Time Complexity: O(n), Space Complexity: O(1)
int minimumCoins4(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    
    int ans=0;

    queue<pair<int,int>>month;
    queue<pair<int,int>>week;

    for(int day:days){
        while(!month.empty() && month.front().first+30<=day)
            month.pop();

        while(!week.empty() && week.front().first+7<=day)
            week.pop();

        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        ans=min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;

}


//Question 12: Largest Square area in a binary matrix
//Approach1: By Recursion 
//Time Complexity: O(3^(m*n)), Space Complexity: O(m+n)
int solve2(vector<vector<int>>& mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        int right=solve2(mat,i,j+1,maxi);
        int diagonal=solve2(mat,i+1,j+1,maxi);
        int down=solve2(mat,i+1,j,maxi);
        
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
        
    }
int maxSquare(vector<vector<int>>& mat) {
        // code here
        int maxi=0;
        solve2(mat,0,0,maxi);
        return maxi;
}

//Approach 2: By Dynamic Programming 
//TC: O(m*n), SC: O(m*n) 
int solveMem2(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>>&dp){
    if(i>=mat.size() || j>=mat[0].size()) return 0;
        
    if(dp[i][j]!=-1) return dp[i][j];
    int right=solveMem2(mat,i,j+1,maxi,dp);
    int diagonal=solveMem2(mat,i+1,j+1,maxi,dp);
    int down=solveMem2(mat,i+1,j,maxi,dp);
        
    if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(diagonal,down));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j];
    }
    else{
        return dp[i][j]=0;
    }
}
int maxSquare2(vector<vector<int>>& mat) {
        
    int n = mat.size();
    int m = mat[0].size();

    int maxi=0;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    solveMem2(mat,0,0,maxi,dp);
    return maxi;
}

//Approach 3: By Tabulation
//TC: O(m*n), SC: O(m*n) 
int solveTab2(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
               int right=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                int down=dp[i+1][j];
        
                if(mat[i][j]==1){
                    dp[i][j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                } 
            }
        }
        return dp[0][0];
    }
    
    
    
    int maxSquare3(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        
        int maxi=0;
        solveTab2(mat,maxi);
        return maxi;
    }

//Approach 4: By Space Optimization 
//TC: O(m*n), SC: O(n)
int solveSO2(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<int>curr(col+1,0);
        vector<int>next(col+1,0);
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
               int right=curr[j+1];
                int diagonal=next[j+1];
                int down=next[j];
        
                if(mat[i][j]==1){
                   curr[j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                } 
            }
            next=curr;
        }
        return next[0];
    }
    
    
    int maxSquare4(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        
        int maxi=0;
        solveSO2(mat,maxi);
        return maxi;
        
        
    }

//Approach 5: By  in place modification of the input matrix
//TC: O(m*n), SC: O(1)
int maxSquareInPlace(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxi = 0;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(mat[i][j] == 1 && i<n-1 && j<m-1)
            {
                mat[i][j] = 1 + min(mat[i][j+1], min(mat[i+1][j], mat[i+1][j+1]));
            }
            
            maxi = max(maxi, mat[i][j]);
        }
    }

    return maxi;
}





int main(){

    
//Question 11: Minimum cost of tickets
//Approach 1: By Recursion
    //int n=6;
    //vector<int> days={1,4,6,7,8,20};
    //vector<int> cost={2,7,15};
    //cout<<minimumCoins(n,days,cost)<<endl;

//Approach 2: By Dynamic Programming
    //cout<<minimumCoins2(n,days,cost)<<endl;

//Approach 3: By Tabulation
    //cout<<minimumCoins3(n,days,cost)<<endl;

//Approach 4: By Space Optimization
    //cout<<minimumCoins4(n,days,cost)<<endl;


//Question12: Largest Square area in a binary matrix 
//Approach1: By Recursion
    vector<vector<int>> mat={{0,1,1,0}, {1,1,1,0}, {1,1,1,0}}; 
    cout<<maxSquare(mat)<<endl;

//Approach 2: By Dynamic Programming 
    cout<<maxSquare2(mat)<<endl;

//Approach 3: By Tabulation
    cout<<maxSquare3(mat)<<endl;

//Approach 4: By Space Optimization
    cout<<maxSquare4(mat)<<endl;

//Approach 5: By more Space Optimization 
    cout<<maxSquareInPlace(mat)<<endl;



    

    



    return 0;
}