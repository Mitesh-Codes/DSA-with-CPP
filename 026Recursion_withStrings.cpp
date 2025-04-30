#include<iostream>
#include<string>
using namespace std;

void reverseString(int i,int j,string &name){
    if(i>j){
        return;
    }
    swap(name[i],name[j]);
    i++;
    j--;
    reverseString(i,j,name);
}

bool checkPalindrome(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
    
        return checkPalindrome(str,i+1,j-1);
    }
}

int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);
    if(b&1){
        return a*ans*ans;
    }
    else{
        return ans*ans;
    }
}


//Bubble Sort by recursion
void BubbleSort(int *arr,int n){
    if(n==0||n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    BubbleSort(arr,n-1);
}

//Insertion sort by Recursion
void InsertionSort(int *arr,int n){
        if (n <= 0)
            return;
    
        // Sort first n-1 elements recursively
        InsertionSort(arr, n - 1);
    
        // Insert arr[n] into the sorted part
        int key = arr[n];
        int j;
    
        for (j = n - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
    
        arr[j + 1] = key;
    
}

//Selection Sort using recursion
void selectionSort(int *arr,int n){
    if(n==0||n==1){
        return;
    }
    int minIndex=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }

    }
    swap(arr[minIndex],arr[0]);
    selectionSort(arr+1,n-1);
    
}




int main(){

    // string name="naman";
    // int namesize=name.length()-1;
    // //reverseString(0,namesize,name);
    // //cout<<name<<endl;

    // bool ans=checkPalindrome(name,0,namesize);
    // cout<<ans<<endl;

    // int a=2;
    // int b=3;
    // int ans=power(a,b);
    // cout<<ans<<endl;

    int arr[5]={324,32,443,5,4};
    int n=5;
    //BubbleSort(arr,n);

    //InsertionSort(arr, n - 1)  // n-1 because we use 0-based index
    
    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}