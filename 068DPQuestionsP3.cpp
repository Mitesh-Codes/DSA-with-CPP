#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Q3: Maximum sum of non-adjacent elements in an array
//Approach1:By recursion
//Time complexity: O(2^n)  Space complexity: O(n)
// this method give TLE error for large input because of repeated calculations
int solve(vector<int>&nums,int n){
    if(n<0) return 0;
    if(n==0) return nums[0];

    int include=solve(nums,n-2)+nums[n];
    int exclude=solve(nums,n-1)+0;

    return max(include,exclude);
}
int maximumNonAdjacentSum(vector<int>& nums) {
    int n=nums.size();
    return solve(nums,n-1);
}

//Approach2:By Dynamic Programming
//Time complexity: O(n)  Space complexity: O(n)
int solve2(vector<int>&nums,int n,vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return nums[0];

    if(dp[n]!=-1) return dp[n];

    int include=solve2(nums,n-2,dp)+nums[n];
    int exclude=solve2(nums,n-1,dp)+0;

    dp[n]= max(include,exclude);
    return dp[n];
}
int maximumNonAdjacentSum2(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,-1);
    return solve2(nums,n-1,dp);
}

//Approach3:By Dynamic Programming with Tabulation
//Time complexity: O(n)  Space complexity: O(n)
int solve3(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int include=dp[i-2]+nums[i];
        int exclude=dp[i-1];
        dp[i]=max(include,exclude);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum3(vector<int>& nums) {
    return solve3(nums);
}

//Approach4:By Dynamic Programming with Tabulation and Space Optimization
//Time complexity: O(n)  Space complexity: O(1)
int solve4(vector<int>&nums){
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++){
        int include=prev2+nums[i];
        int exclude=prev1+0;
        int ans=max(include,exclude);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum4(vector<int>& nums) {
    return solve4(nums);
}


//Question4: House Robber
//TC: O(n)  SC: O(n)
long long int solve5(vector<int>&nums){
    int n = nums.size();
    if(n == 0) return 0;       
    if(n == 1) return nums[0];
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1;i<n;i++){
        long long int include=prev2+nums[i];
        long long int exclude=prev1+0;
        long long int ans=max(include,exclude);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();

    if(n==1) return valueInHouse[0];
    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }
    return max(solve4(first),solve4(second));

}




//Question5: Cut rod in segments
//Approach1:By recursion
//Time complexity: O(3^n)  Space complexity: O(n)
// this method give TLE error for large input because of repeated calculations
int solve(int n, int x, int y, int z){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	int a=solve(n-x,x,y,z)+1;
	int b=solve(n-y,x,y,z)+1;
	int c=solve(n-z,x,y,z)+1;
	return max(a,max(b,c));
}
int cutSegments(int n, int x, int y, int z) {
    int ans=solve(n,x,y,z);
    if(ans<0){
        return 0;
    }
    return ans;
}

//Approach2:By Dynamic Programming
//Time complexity: O(n)  Space complexity: O(n)
int solvemem(int n, int x, int y, int z,vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1) return dp[n];
	int a=solvemem(n-x,x,y,z,dp)+1;
	int b=solvemem(n-y,x,y,z,dp)+1;
	int c=solvemem(n-z,x,y,z,dp)+1;
	dp[n]= max(a,max(b,c));
	return dp[n];
}

int cutSegments2(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);
	int ans=solvemem(n,x,y,z,dp);
	return max(0,ans);


}

//Approach3:By Dynamic Programming with Tabulation
//Time complexity: O(n)  Space complexity: O(n)
int solveTab(int n,int x,int y,int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0){
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0){
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}
	if(dp[n]<0){
		return 0;
	}
	else{
		return dp[n];
	}
}
int cutSegments3(int n, int x, int y, int z) {
    return solveTab(n,x,y,z);
}


//Approach4:By Dynamic Programming with Tabulation and Space Optimization is NOT possible in this question because 
//we dont have fixed number of previous states to calculate the current state. 
//we have to check for all previous states from i-x to i-z to calculate the current state. 
//so we need to store all previous states in dp array to calculate the current state.



int main(){

//Q3: Maximum sum of non-adjacent elements in an array
//Approach1:By recursion
    vector<int>nums={3,4,4,6,7};
    cout<<maximumNonAdjacentSum(nums)<<endl;

//Approach2:By Dynamic Programming
    cout<<maximumNonAdjacentSum2(nums)<<endl;

//Approach3:By Dynamic Programming with Tabulation
    cout<<maximumNonAdjacentSum3(nums)<<endl;

//Approach4:By Dynamic Programming with Tabulation and Space Optimization
    cout<<maximumNonAdjacentSum4(nums)<<endl;


//Question4: House Robber
    vector<int>valueInHouse={2,3,2};
    cout<<houseRobber(valueInHouse)<<endl;



//Question5: Cut rod in segments
//Approach1:By recursion
    int n=5,x=1,y=2,z=3;
    cout<<cutSegments(n,x,y,z)<<endl;

//Approach2:By Dynamic Programming
    cout<<cutSegments2(n,x,y,z)<<endl;

//Approach3:By Dynamic Programming with Tabulation
    cout<<cutSegments3(n,x,y,z)<<endl;





    return 0;
}