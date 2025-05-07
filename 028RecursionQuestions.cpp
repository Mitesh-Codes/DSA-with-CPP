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

//Question 4: Permutations (leetcode 46)
void solve(vector<int>nums,vector<vector<int>> &ans,int index){
    if(index>=nums.size()){
        ans.push_back(nums);
        return ; 
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        //Backtracking
        swap(nums[index],nums[j]);
    }

}

//question 5: Rat in a maze
bool isSafe(int x,int y,int n,vector<vector<int>>& visited, vector<vector<int>> &m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>>& m,int n,vector<string> &ans,int x,int y,vector<vector<int>> visited,string path){

    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    
    //Down
    int newx=x+1;
    int newy=y;
    if(isSafe(newx,newy,n,visited,m)){
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Left
    newx=x;
    newy=y-1;
    if(isSafe(newx,newy,n,visited,m)){
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Right
    newx=x;
    newy=y+1;
    if(isSafe(newx,newy,n,visited,m)){
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //UP
    newx=x-1;
    newy=y;
    if(isSafe(newx,newy,n,visited,m)){
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    
    visited[x][y]=0;
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
    // vector<string> ans3;
    // string digits="45";
    // string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // string output="";
    // int index3=0;
    // solve(digits,output,index3,ans3,mapping);
    // for(auto i:ans3){
    //     cout<<i<<endl;
    // }
    // cout<<endl;


//question 4: Permutations (leetcode 46)
    // vector<int> nums={1,2,3};
    // vector<vector<int>> ans4;
    // int index4=0;
    // solve(nums,ans4,index4);
    // for(auto i:ans4){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

//question 5: RAT IN A MAZE
//Time complexity : O(4^(n^2)) because in the worst case we can go in all 4 directions from each cell, and there are n^2 cells in the maze. 
//Space complexity : O(n^2) for the visited array and O(n) for the recursion stack.
    vector<vector<int>> m;
    vector<string> ans5;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        m.push_back(temp);
    }
    if(m[0][0]==0 || m[n-1][n-1]==0){
        cout<<"No path exists"<<endl;
        return 0;
    }
    vector<vector<int>> visited(n,vector<int>(n,0));
    string path="";
    int x=0,y=0;
    solve(m,n,ans5,x,y,visited,path);
    cout<<"All paths are: "<<endl;
    for(auto i:ans5){
        cout<<i<<endl;
    }
    cout<<endl;
	
    return 0;
}
