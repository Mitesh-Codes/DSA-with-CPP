#include<iostream>
#include<stack>
using namespace std;

//impelementation of stack
class Stack{
    public:
        int *arr;
        int top;
        int size;
    Stack(int size){
        this->size=size;
        arr=new int [size];
        top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>-0){
            top--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    int peak(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

//Question1: Two stack in an array;
class TwoStack {

public:
    int *arr;
    int top1;
    int top2;
    int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
            return-1;
        }
    }

    int peak1(){
        if(top1>=0){
            return arr[top1];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    int peak2(){
        if(top2<size){
            return arr[top2];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
};


//Question2: Reverse a stack using stack

//Question3: Delete middle element from stack
void solve(stack <int>&inputStack,int count,int size){

    if(count==size/2){
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();

    solve(inputStack,count+1,size);
    inputStack.push(num);

}
//Question4: Valid Parenthesis (IMPORTANT)
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];

        if(ch=='('||ch=='{'||ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top=st.top();
                if((top=='('&& ch==')')||(top=='{'&& ch=='}')||(top=='['&& ch==']')){
                    st.pop();

                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
    


}

//Question5: Insert at bottom of stack
void solve(stack<int>& myStack, int x) {
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}


//Question6: Reverse a stack using recursion
void insertAtBottom(stack<int> &stack,int element){
    if(stack.empty()){
        stack.push(element);
        return;
    }
    int num=stack.top();
    stack.pop();
    insertAtBottom(stack,element);
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);

}

//Question7: Sort a Stack
void sortedInsert(stack<int>&stack, int num){
	if(stack.empty()||(stack.empty()||stack.top()<num)){
		stack.push(num);
		return;
	}
	int n=stack.top();
	stack.pop();
	sortedInsert(stack,num);
	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, num);
}

//Question8: Redundant Brackets
#include <bits/stdc++.h>
#include<stack> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> st;
    for(int i=0;i<s.length();i++){
         char ch=s[i];

        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
            
            while(st.top()!='('){
                char top=st.top();
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                    isRedundant=false;
                }
                st.pop();
            }
            if(isRedundant==true){
                return true;
            }
            st.pop();
            }
        }
    }
    return false;
}







int main(){

    // stack<int> s;
    // s.push(5);
    // s.push(3);
    // s.push(1);

    // s.pop();

    // cout<<s.top()<<endl;
    // cout<<s.empty()<<endl;
    // cout<<s.size()<<endl;

//Stack implementation using array
    // Stack st(5);

    // st.push(22);
    // st.push(21);
    // st.push(20);

    // cout<<st.peak()<<endl;
    // st.pop();
    // cout<<st.peak()<<endl;
    // st.pop();
    // cout<<st.peak()<<endl;
    // st.pop();

//Question1: Two stack in an array;
    // TwoStack ts(4);
    // ts.push1(2);
    // ts.push1(3);
    // ts.push2(4);
    // ts.push2(5);
    // ts.pop1();
    // ts.pop2();
    // cout<<ts.peak1()<<endl;
    // cout<<ts.peak2()<<endl;

//Question2: Reverse a stack using stack
    // string str="kite";
    // stack<char>s;
    // for(int i=0;i<str.length();i++){
    //     char ch=str[i];
    //     s.push(ch);
    // }
    // string ans="";
    // while(!s.empty()){
    //     ans.push_back(s.top());
    //     s.pop();
    // }
    // cout<<ans<<endl;


//Question3: Delete middle element from stack
    // stack <int> st;
    // st.push(22);
    // st.push(21);
    // st.push(20);
    // int count=0;
    // int size=st.size();
    // solve(st,count,size);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }


//Question4: Valid Parenthesis (IMPORTANT)
    // string s="[([{})]]";
    // if(isValidParenthesis(s)){
    //     cout<<"Valid Parenthesis"<<endl;
    // }
    // else{
    //     cout<<"Not a Valid Parenthesis"<<endl;
    // }

//Question5: Insert at bottom of stack
    // stack<int> myStack;
    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);
    // int x=4;
    // myStack=pushAtBottom(myStack,x);
    // while(!myStack.empty()){
    //     cout<<myStack.top()<<endl;
    //     myStack.pop();
    // }

//Question6: Reverse a stack using recursion
    // stack<int> stack;
    // stack.push(1);
    // stack.push(2);
    // stack.push(3);
    // reverseStack(stack);
    // while(!stack.empty()){
    //     cout<<stack.top()<<endl;
    //     stack.pop();
    // }

//Question7: Sort a Stack
    // stack<int> stack;
    // stack.push(34);
    // stack.push(53);
    // stack.push(3);
    // sortStack(stack);
    // while(!stack.empty()){
    //     cout<<stack.top()<<endl;
    //     stack.pop();
    // }

//Question8: Redundant Brackets
    string s="(a+b)";
    if(findRedundantBrackets(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}
