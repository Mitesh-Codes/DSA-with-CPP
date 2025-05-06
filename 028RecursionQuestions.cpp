#include<iostream>
#include<vector>
#include<string>


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

//Question 3:Letter combinations of a phone number
//time complexity: O(4^n) where n is the length of the digits string because each digit can map to 3 or 4 letters, and we have n digits. 
//The space complexity is O(n) for the recursion stack.
//The output space complexity is O(3^n) because the maximum number of combinations is 3^n, where n is the length of the digits string.
void solve(string digit,string output,int index,vector<string>&ans,string mapping[]){
    if(index>=digit.length()){
        ans.push_back(output);
        return;
    }
    int number=digit[index]-'0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digit,output,index+1,ans,mapping);
        output.pop_back();
    }
}


int main(){

//Question1: give powersets of a set
    // vector<int> nums={1,2,3};
    // vector<vector<int>> ans;
    // vector<int> output;
    // int index=0;
    // solve(nums,output,index,ans);
    // for(auto i:ans){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

//Question2: subsequences of a string
    // string str="abc";
    // vector<string> ans2;
    // string output2="";
    // int index2=0;
    // solve(str,output2,index2,ans2);
    // for(auto i:ans2){
    //     cout<<i<<endl;
    // }
    // cout<<endl;


//Question 3:Letter combinations of a phone number
    vector<string> ans3;
    string digits="45";
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output="";
    int index3=0;
    solve(digits,output,index3,ans3,mapping);
    for(auto i:ans3){
        cout<<i<<endl;
    }
    cout<<endl;






    return 0;
}
