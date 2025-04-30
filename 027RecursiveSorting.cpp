#include<iostream>
using namespace std;

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