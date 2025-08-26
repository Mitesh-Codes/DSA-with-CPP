#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

//Question 9: Minimum cost to make string valid 
int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2==1){
    return -1;
  }
  stack <char>s;
  for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(ch=='{'){
      s.push(ch);
    }
    else{
      if(!s.empty() && s.top()=='{'){
        s.pop();
      }
      else{
        s.push(ch);
      }
    }
  }
  int a=0,b=0;
  while(!s.empty()){
    if(s.top()=='{'){
      b++;
    }
    else{
      a++;
    }
    s.pop();
  }
  int ans=(a+1)/2+(b+1)/2;
  return ans;
}


//Question10: Next smaller element
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

//Question11: Largest rectangle in histogram
vector<int> nextSmallerElement1(vector<int>arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
 }
vector<int> prevSmallerElement(vector<int>arr,int n){
  stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int n=heights.size();
    vector<int>next(n);
    next=nextSmallerElement1(heights,n);
    vector<int> prev(n);
    prev=prevSmallerElement(heights,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
      int l=heights[i];
      
      if(next[i]==-1){
        next[i]=n;
      }
      int b=next[i]-prev[i]-1;
      int newArea=l*b;
      area=max(area,newArea);
      
    }
    return area;
}


int main(){

    
//Question9: Minimum cost to make string valid
    // string str="{{{{}}";
    // cout<<findMinimumCost(str)<<endl;


//Question10: Next smaller element
    // vector<int> arr={4,5,2,10,8};
    // int n=arr.size();
    // vector<int> ans=nextSmallerElement(arr,n);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

//Question11: Largest rectangle in histogram
    vector<int> heights={2,1,5,6,2,3};
    cout<<largestRectangle(heights)<<endl;



    return 0;
}