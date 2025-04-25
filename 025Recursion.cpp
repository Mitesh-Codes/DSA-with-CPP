#include<iostream>
#include<string>
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

void sourceToDestination( int source, int destination){
    cout<<"Source:"<<source<<" Destination:"<<destination<<endl;
    if(source==destination){
        cout<<"At the destination"<<endl;
        return;
    }
    source++;
    sourceToDestination(source,destination);
}

int fib(int n) {
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans=fib(n-1)+fib(n-2);   
    return ans;     
}
int fib_forLoop(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int prev2 = 0; // fib(0)
    int prev1 = 1; // fib(1)
    int curr;

    for(int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

//CLimb Stairs
int climbStairs(int n) {
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=climbStairs(n-1)+climbStairs(n-2);
    return ans;
}

void printDigits(int n, string arr[]){
    if(n==0){
        return ;
    }
    int digit=n%10;
    n=n/10;
    printDigits(n,arr);
    cout<<arr[digit]<<" ";
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

    //int n=5;
    //print(n);
    //cout<<endl;
    //print2(n);

    // int source=0;
    // int destination=5;
    // sourceToDestination(source,destination);

//Fibonacci Series
    // int n;
    // cin>>n;
    // cout<<endl;
    // int ans=fib(n);
    // cout<<ans<<endl;

    // int n;
    // cin>>n;
    // cout<<endl;
    // int ans=climbStairs(n);
    // cout<<ans<<endl;

//Print digits
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    cout<<endl;
    printDigits(n,arr);
    cout<<endl;






    return 0;
}
