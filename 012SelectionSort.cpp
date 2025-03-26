#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{   
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
                
            }
        
        }
        swap(arr[minIndex],arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}

int main(){

    int arr[]={23,5325,24,1,4,6,2,34};
    int n=sizeof(arr) / sizeof(arr[0]);
    cout<<"\nBefore Selection sorting\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nAfter Selection sorting\n";
    
    selectionSort(arr,n);
    
    return 0;
}