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
bool isSorted(int *arr,int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1,size-1);
    }
}

int sumofarray(int *arr,int size){
    int sum=0;

    if(size==0){
        return 0;
    }
    
    sum=arr[0]+sumofarray(arr+1,size-1);
    return sum;
}

bool isFound(int *arr,int size,int key){
    if(size==0){
        return 0;
    }
    if(arr[0]==key){
        return true;
    }
    else{
    
    isFound(arr+1,size-1, key);

    }   
    
    
}

bool binarySearch(int *arr,int s,int e,int key){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    
    if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
    
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

//Stairs Problem
    // int n;
    // cin>>n;
    // cout<<endl;
    // int ans=climbStairs(n);
    // cout<<ans<<endl;

//Print digits
    // string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    // int n;
    // cin>>n;
    // cout<<endl;
    // printDigits(n,arr);
    // cout<<endl;


//IsSorted
    int arr[7]={4,5,5,5,6,7,8};
    int size=7;
    // bool ans=isSorted(arr,size);
    // if(ans){
    //     cout<<"Array is sorted"<<endl;
    // }
    // else{
    //     cout<<"Array is not sorted"<<endl;
    // }

//Sum by recusion
    // int ans=sumofarray(arr,size);
    // cout<<ans<<endl;


//element searching
    //cout<<isFound(arr,size,6)<<endl;



//Binary search
    int s=0;
    int e=size-1;
    int key=5;
    cout<<binarySearch(arr,s,e,key)<<endl;





    return 0;
}
