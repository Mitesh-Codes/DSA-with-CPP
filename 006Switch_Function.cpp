#include<iostream>
using namespace std;

int update(int a){
    a-=5;
    return a;
}

int power(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    return ans;
}

int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*i;
    }
    return ans;
}
int nCr(int n, int r){
    int num,den;
    num=factorial(n);
    den=factorial(r)*factorial(n-r);
    return num/den;
}

void isPrime(int n){
    int ans=0;
    for(int i=2;i<n;i++){
        if((n%i)==0){
            ans++;
            break;
        }
    }
    if(ans>=1){
        cout<<"Not a prime";
    }
    else if(n==0){
        cout<<"ZERO";
    }
    else{
        cout<<"Prime";
    }
    
}   

int main(){
    // char ch='1';
    // cout<<endl;
    // switch(ch){
    //     case '2': cout<<"First"<<endl;
    //             break;
    //     case '1': cout<<"Second"<<endl; // We can use switch inside switch.
    //             break;
    //     default: cout<<"It is default case"<<endl;
    // }
    // int a,b;
    // cin>>a>>b;

    // int ans=power(a,b);
    // cout<<ans;
    // return 0;

   //int i= nCr(8,2);
   //cout<<i;

   //isPrime(9);

   int a=15;
   update(a);
   cout<<a<<endl;
   




}