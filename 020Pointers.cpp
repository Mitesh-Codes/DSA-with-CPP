#include<iostream>
using namespace std;



int main(){

    //double num=542432;
    //cout<<num<<endl;
    //Address operator ---> &
    //cout<<"Address of num is: "<<&num<<endl;

    //double *ptr=&num;
    //cout<<"Address of num using pointer is: "<<ptr<<endl;
    //cout<<"Value of num using pointer is: "<<*ptr<<endl;

    //char d='c';
    //char *ptr2=&d;
    // cout<<static_cast<void*>(&d)<<endl; //this static_cast is casting the address of char to void pointer
    // cout<<*ptr2<<endl;
    // cout<<static_cast<void*>(ptr)<<endl;

    // cout<<"The size of double is: "<<sizeof(num)<<endl;
    // cout<<"The size of double pointer is: "<<sizeof(ptr)<<endl;
    // cout<<"The size of char is: "<<sizeof(d)<<endl;
    // cout<<"The size of char pointer is: "<<sizeof(ptr2)<<endl;


    //BAD PRACTICE
    // int *p1;
    // cout<<*p1<<endl; //this will give garbage value because p1 is not initialized


    //int *p2=0;
    //cout<<*p2<<endl; //this will give segmentation fault because p2 is pointing to null

    // int i=9;
    // int *p3=0;
    // p3=&i;
    // cout<<p3<<endl;
    // cout<<*p3<<endl;


    int num=6;
    int a=num;
    a++;
    //cout<<a<<endl;
    //cout<<num<<endl; //this will print 6 because a is a copy of num and incrementing a does not change num    
    //BUT
    int *p4=&num;
    //cout<<"num Before:"<<num<<endl;
    (*p4)++;
    //cout<<"num after incrementing its pointer:"<<num<<endl; //this will print 7 because p4 is pointing to num and incrementing *p4 will change num


    //Copying a pointer
    int *q=p4;
    //cout<<p4<<" - "<<q<<endl;
    //cout<<*p4<<" - "<<*q<<endl;


    //Important concept
    int i=3;
    int *t=&i;
    cout<<++(*t)<<endl; //use brackets to increment the value of i using pointer t
    *t=*t+1;
    cout<<*t<<endl;
    
    //Pointer arithmetic
    cout<<"Before t"<<t<<endl;
    t=t+1;
    cout<<"After t"<<t<<endl; //this will increment the address of t by 4 bytes because int is 4 bytes



    return 0;
}