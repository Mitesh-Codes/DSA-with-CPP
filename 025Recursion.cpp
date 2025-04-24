#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0)return 1; //if we reomve the base case, it will go into infinite recursion and give stack overflow error

    return n*factorial(n-1);

}

int power(int n){
    if(n==0) return 1;
    return 2*power(n-1);
}

void print(int n){
    //TAIL Recrusion
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    print(n-1);
}

void print2(int n){
    //HEAD Recrusion
    if(n==0){
        return ;
    }
    
    print2(n-1);

    cout<<n<<endl;
}


int main(){

    // int n;
    // cin>>n;
    // int ans=factorial( n);
    // cout<<ans<<endl;

    // int n;
    // cin>>n;
    // int ans=power(n);
    // cout<<ans<<endl;

    int n=5;
    //print(n);
    cout<<endl;
    print2(n);


    return 0;
}