#include<iostream>
#include<queue>
using namespace std;

//Queue implementation
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (qfront == rear);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            cout<<"Queue overflow";
            return;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};


//Circular queue
class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front==0&&rear==size-1)|| (rear==(front-1)%(size-1))){
            return false;
        }
        else if(front==-1){
            front=rear=0;
            
        }
        else if(rear==size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};

//Doubly Ended Queue implementation
#include <bits/stdc++.h> 
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size=n;
        front=rear=-1;
        arr=new int[n];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if((front==0&&rear==size-1)|| (front!=0 && rear==(front-1)%(size-1))){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if((front==0&&rear==size-1)|| (front!=0 && rear==(front-1)%(size-1))){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true;

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front==0&&rear==size-1)|| (front!=0 && rear==(front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};





int main(){

    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);

    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.empty()<<endl;

//Queue implementation
    // Queue q;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // cout<<q.front()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.front()<<endl;
    // cout<<q.isEmpty()<<endl;


//Circular queue
    // CircularQueue q(5);
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);

    // q.dequeue();



//Doubly Ended Queue
    // deque<int> d;
    // d.push_front(1);
    // d.push_back(5);

    // cout<<d.front()<<endl;
    // cout<<d.back()<<endl;

    // d.pop_front();
    // cout<<d.front()<<endl;
    // cout<<d.back()<<endl;
    // d.pop_back();
    // cout<<d.empty()<<endl; // queue is empty.

//Doubly Ended Queue implementation
    Deque dq(5);
    dq.pushFront(1);
    dq.pushRear(2);
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    dq.popFront();
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    dq.popRear();
    cout<<dq.isEmpty()<<endl; // queue is empty.


    return 0;
}