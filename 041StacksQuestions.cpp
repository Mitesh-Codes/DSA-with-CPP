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

//Question12: Celebrity problem
bool knows(vector<vector<int>>& mat,int a,int b,int n){
  if(mat[a][b]==1){
    return true;
  }
  else{
    return false;
  }
}
int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(knows(mat,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        int ans=s.top();
        //Verify
        for(int i=0;i<n;i++){
            if(i != ans && mat[ans][i] == 1) return -1;
        }
        
        // Column check (everyone knows candidate)
        for(int i=0;i<n;i++){
            if(i != ans && mat[i][ans] == 0) return -1;
        }
        
        return ans;
        
}

//Question13: Max Rectangle
int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m=mat[0].size();
        
        int area=largestRectangle(mat[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                }
                else{
                    mat[i][j]=0;
                }
            }
            area=max(area,largestRectangle(mat[i]));
        }
        return area;
        
        
        
}

//Question14: N stacks in an array
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot==-1){
            return false;
        }

        int index=freespot;
        freespot=next[index];
        arr[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};



//Question15: Design a stack that supports getMin() in O(1) time and O(1) extra space
class SpecialStack {
    stack<int>s;
    int mini;
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini=data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()){
            return -1;

        }
        int curr=s.top();
        s.pop();
        if(curr>mini){
            return curr;
        }
        else{
            int prevMin=mini;
            int val=2*mini-curr;
            mini=val;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty(){
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};






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
    // vector<int> heights={2,1,5,6,2,3};
    // cout<<largestRectangle(heights)<<endl;


  //Question12: Celebrity problem
    // vector<vector<int>> mat={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
    // cout<<celebrity(mat)<<endl;

  //Question13: Max rectangle
    // vector<vector<int>> mat={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    // cout<<maxArea(mat)<<endl;

  //Question14: N stacks in an array
    // NStack s(3,6);
    // s.push(15,1);
    // s.push(45,1);
    // s.push(17,2);
    // s.push(49,3);
    // s.push(39,2);
    // s.push(11,1);
    // s.push(9,3);
    // s.push(7,2);
    // cout<<s.pop(2)<<endl;
    // cout<<s.pop(1)<<endl;
    // cout<<s.pop(3)<<endl;


  //Question15: Design a stack that supports getMin() in O(1) time and O(1) extra space
    SpecialStack s;
    s.push(10);
    s.push(20);
    cout<<s.getMin()<<endl;
    s.push(5);
    cout<<s.getMin()<<endl;
    s.push(3);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    



    



    

  


    return 0;
}
