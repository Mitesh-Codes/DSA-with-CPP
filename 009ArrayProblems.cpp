#include<iostream>
using namespace std;

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void swaparray(int arr[],int size){
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
}

void sort012(int *arr,int n){
        int firstvalue=0;
        int thirdvalue=2;

        int firstIdx=0;
        for(int i=0;i<n;i++){
            if(arr[i]==firstvalue){
                swap(arr[i],arr[firstIdx]);
                firstIdx++;
            }
        }

        int thirdIdx=n-1;
        for(int i=n;i>=0;i--){
            if(arr[i]==thirdvalue){
                swap(arr[i],arr[thirdIdx]);
                thirdIdx--;
            }
        }
}

int main(){
    // int arr1[5]={3,4,3,34,423};
    // int arr2[4]={342,321,32,13};

    // swaparray(arr2,4);
    // printarray(arr2,4);

//Find unique number in an array    
    // int arr[5]={3,1,3,1,7};
    // int size=5;
    // int ans=0;
    // for(int i=0;i<size;i++){
    //     ans=ans^arr[i];
    // }
    // cout<<ans;


//Find duplicate in array
    // int arr[7]={1,2,3,5,2,6,4};
    // int ans=0;
    // for(int i=0;i<7;i++){
    //     int count=0;
    //     for(int j=0;j<7;j++){
    //         if(arr[i]==arr[j]){
    //             count+=1;
    //             if(count>1){
    //                 ans=arr[j];
    //             }
    //         }
    //     }
    // }
    // cout<<ans;


//sort 0 1 2
    int arr[7]={1,0,2,0,1,0,0};
    sort012(arr,7);
    printarray(arr,7);

    



    






    
}