#include<iostream>
using namespace std;

int main(){

    // int n;
    // cin>>n;
    // cout<<"hey!"<<endl;

    // if(n>0){
    //     cout<<"Positive";

    // }
    // else{
    //     cout<<"Negative";
    // }

    // int a;
    // a=cin.get();
    // cout<<"The value of is a is "<< a;

    //postive negative or zero program
    // int a;
    // cout<<"Enter a number: ";
    // cin>>a;
    // if(a>0){
    //     cout<<"The number is postive";
    // }
    // else if(a<0){
    //     cout<<"The number is negative";
    // }
    // else{
    //    cout<< "the number is zero";
    // }

    // int a=2;
    // int b=a+1;
    // if((a=3)==b){
    //     cout<<a<<endl;
    // }
    // else{
    //     cout<<a+9;
    // }
    // cout<<a;

    // int i=1;
    // //cout<<i;
    // cout<<"Enter the last number:";
    // int n;
    // cin>>n;
    // int sum=0;
    // while(i<=n){
    //     sum+=i;
    //     i++;
    // }
    // cout<<sum;


    // int i;
    // cin>>i;
    // int n=0;
    // int sum=0;
    // while(n<=i){
    //     if(n%2==0){
    //         sum+=n;
    //     }
    //     n++;
        
    // }
    // cout<<sum;


    int n;
    cin>>n;
    int i=1;

    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<"*";
            j=j+1;
        }
        cout<<"\n";
        i+=1;
    }




    
    return 0;

}