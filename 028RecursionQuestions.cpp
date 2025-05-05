#include<iostream>
#include<vector>

using namespace std;

//Question 1 : give powersets of a set 
void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums,output,index+1,ans);

    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}

//Question 2: subsequences of a string
void solve(string str,string output,int index,vector<string>& ans){
	if(index>=str.length()){
		if(!output.empty()) ans.push_back(output);
		return;
	}
	
	solve(str,output,index+1,ans);
	
	char element=str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);
}


int main(){

//Question1: give powersets of a set
    vector<int> nums={1,2,3};
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

//Question2: subsequences of a string
    string str="abc";
    vector<string> ans2;
    string output2="";
    int index2=0;
    solve(str,output2,index2,ans2);
    for(auto i:ans2){
        cout<<i<<endl;
    }
    cout<<endl;




    return 0;
}