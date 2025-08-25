#include<iostream>
//#include<stack>
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
        arr=new int(s);
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
            return -1;
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

//Question1
    TwoStack ts(4);
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);
    ts.push2(5);
    ts.pop1();
    ts.pop2();
    cout<<ts.peak1()<<endl;
    cout<<ts.peak2()<<endl;


    


    return 0;
}