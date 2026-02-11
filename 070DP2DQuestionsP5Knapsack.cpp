#include<iostream>
#include<vector>
using namespace std;

//Question8: Knapsack Problem

//Approach1: By Recursion
//Time Complexity: O(2^n), Space Complexity: O(n)
int solve(vector<int>&weight, vector<int>&value, int index, int maxWeight){
	if(index==0){
		if(weight[0]<=maxWeight){
			return value[0];
		}
		else{
			return 0;
		}
	}

	int include=0;
	if(weight[index]<=maxWeight){
		include=value[index]+solve(weight,value,index-1,maxWeight-weight[index]);
	}
	int exclude=0+ solve(weight,value,index-1,maxWeight);
	int ans=max(exclude,include);
	return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight,value,n-1,maxWeight);

}

//Approach2: By Dynamic Programming
//Time Complexity: O(n*maxWeight), Space Complexity: O(n*maxWeight)
int solveMem(vector<int>&weight, vector<int>&value, int index, int maxWeight,vector<vector<int>>&dp){
	if(index==0){
		if(weight[0]<=maxWeight){
			return value[0];
		}
		else{
			return 0;
		}
	}
	if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];

	int include=0;
	if(weight[index]<=maxWeight){
		include=value[index]+solveMem(weight,value,index-1,maxWeight-weight[index],dp);
	}
	int exclude=0+ solveMem(weight,value,index-1,maxWeight,dp);
	dp[index][maxWeight]=max(exclude,include);
	return dp[index][maxWeight];
}

int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	//return solve(weight,value,n-1,maxWeight);

	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return solveMem(weight,value,n-1,maxWeight,dp);


}

//Approach3: By Dynamic Programming with Tabulation
//Time Complexity: O(n*maxWeight), Space Complexity: O(n*maxWeight)
int solveTab(vector<int>&weight, vector<int>&value, int n, int maxWeight){
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int w=weight[0];w<=maxWeight;w++){
		if(weight[0]<=maxWeight){
			dp[0][w]= value[0];
		}
		else{
			dp[0][w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=0;w<=maxWeight;w++){
			
			int include=0;
			if(weight[index]<=w){
			include=value[index]+dp[index-1][w-weight[index]];
			}
			int exclude=0+ dp[index-1][w];
			dp[index][w]=max(exclude,include);
		}
	}
	return dp[n-1][maxWeight];
}
int knapsack3(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	return solveTab(weight,value,n,maxWeight);
}

//Approach4: By Dynamic Programming with Space Optimization
//Time Complexity: O(n*maxWeight), Space Complexity: O(2*maxWeight)
int solveSO(vector<int>&weight, vector<int>&value, int n, int maxWeight){
	vector<int> prev(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);
	for(int w=weight[0];w<=maxWeight;w++){
		if(weight[0]<=maxWeight){
			prev[w]= value[0];
		}
		else{
			prev[w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=0;w<=maxWeight;w++){
			
			int include=0;
			if(weight[index]<=w){
			include=value[index]+prev[w-weight[index]];
			}
			int exclude=0+ prev[w];
			curr[w]=max(exclude,include);
		}
		prev=curr;
	}
	return prev[maxWeight];
}

int knapsack4(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	return solveSO(weight,value,n,maxWeight);

}

//Approach5: By Dynamic Programming with Space Optimization and 1D Array
//Time Complexity: O(n*maxWeight), Space Complexity: O(maxWeight)
int solveSO1D(vector<int>&weight, vector<int>&value, int n, int maxWeight){
	vector<int> curr(maxWeight+1,0);
	for(int w=weight[0];w<=maxWeight;w++){
		if(weight[0]<=maxWeight){
			curr[w]= value[0];
		}
		else{
			curr[w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=maxWeight;w>=0;w--){
			
			int include=0;
			if(weight[index]<=w){
			include=value[index]+curr[w-weight[index]];
			}
			int exclude=0+ curr[w];
			curr[w]=max(exclude,include);
		}
	}
	return curr[maxWeight];
}
int knapsack5(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    
    return solveSO1D(weight,value,n,maxWeight);

}







int main(){

    
//Question 8: Knapsack Problem
//Approach1: By Recursion
    vector<int> weight={1,5,3};
    vector<int> value={10,15,40};
    int maxWeight=6;
    int n=weight.size();
    cout<<knapsack(weight,value,n,maxWeight)<<endl;

//Approach2: By Dynamic Programming
    cout<<knapsack2(weight,value,n,maxWeight)<<endl;

//Approach3: By Dynamic Programming with Tabulation
    cout<<knapsack3(weight,value,n,maxWeight)<<endl;

//Approach4: By Dynamic Programming with Space Optimization
    cout<<knapsack4(weight,value,n,maxWeight)<<endl;

//Approach5: By Dynamic Programming with Space Optimization and 1D Array
    cout<<knapsack5(weight,value,n,maxWeight)<<endl;




    return 0;
}