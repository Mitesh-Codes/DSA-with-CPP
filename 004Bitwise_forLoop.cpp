#include<iostream>
using namespace std;

int main(){

    // int a=4;
    // int b=6;
    // cout<< "a&b is " << (a&b) << endl;
    // cout<<"a|b is "<< (a|b) << endl;
    // cout<<"~a is "<< ~a << endl;
    // cout<<"a^b is "<< (a^b) << endl;

    // int a,b=1;
    // a=0;
    // if(a++){
    //     cout<<b;
    
    // }
    // else{
    //     cout<<++b;
    // }


//FOR LOOP

    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<endl;
    // }

    // int n=10;
    // int a=0;
    // int b=1;
    // cout<<a<<" "<<b<<" ";
    //  for(int i=1;i<=n;i++){
    //     int nextnumber=a+b;
    //     cout<<nextnumber<<" ";

    //     a=b;
    //     b=nextnumber;
    //  }


    for(int i=0;i<5;i++){
        for(int j=i;j<=5;j++){
            if(i+j==10){
                break;
            }
            
            cout<<i<<" "<<j<<endl;
        }
        
    }
    



}