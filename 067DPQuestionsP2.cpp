#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Question2: minimmum no. of coins to make a given amount
//Approach1:By recursion
//Time complexity: O(m^n)  Space complexity: O(n)

// this method give TLE error for large input because of repeated calculations

int solveRec(vector<int>&num,int x){
    if(x==0) return 0;
    if(x<0) return 1e9;

    int mini=1e9;
    for(int i=0;i<num.size();i++){
        int ans=solveRec(num,x-num[i]);
        if(ans!=1e9){
            mini=min(mini,1+ans); 
        }
    }
    return mini;
}
int minimumElements(vector<int>&num,int x){
    int ans=solveRec(num,x);
    if(ans==1e9) return -1;
    return ans;
}


//Approach2:By Dynamic Programming
//Time complexity: O(m*n)  Space complexity: O(n)
int solveMem(vector<int>&num,int x,vector<int>&dp){
    if(x==0) return 0;
    if(x<0) return 1e9;

    if(dp[x]!=-1){
        return dp[x];
    }

    int mini=1e9;
    for(int i=0;i<num.size();i++){
        int ans=solveMem(num,x-num[i],dp);
        if(ans!=1e9){
            mini=min(mini,1+ans);
        }
    }
    dp[x]=mini;
    return mini;
}
int minimumElements2(vector<int>&num,int x){
    vector<int>dp(x+1,-1);
    int ans=solveMem(num,x,dp);
    if(ans==1e9) return -1;
    return ans;
}

//Approach3:By Dynamic Programming with Tabulation
//Time complexity: O(m*n)  Space complexity: O(n)
int solveTab(vector<int>&num,int x){
    vector<int> dp(x+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)
        return -1;
    
    return dp[x];

}
int minimumElements3(vector<int>&num,int x){

    return solveTab(num,x);

}

//Approach4:By Dynamic Programming with Tabulation and Space Optimization

// here we can't optimize space because we need to store the minimum number of coins for all amounts from 0 to x
 




int main(){

//Question2: minimmum no. of coins to make a given amount
//Approach1:By recursion
    vector<int>num={1,2,3}; 
    int x=7;
    int ans=minimumElements(num,x);
    //cout<<ans<<endl;

//Approach2:By Dynamic Programming
    int ans2=minimumElements2(num,x);
    cout<<ans2<<endl;

//Approach3:By Dynamic Programming with Tabulation
    int ans3=minimumElements3(num,x);
    cout<<ans3<<endl;







    return 0;

}
