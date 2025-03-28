#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){                 //for(int i=1,i<n;i++){
        for(int j=0;j<n-(i+1);j++){            //for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

            // TIME COMPLEXITY: O(n^2)
            // Space Complexity: O(1)

int main(){

    int arr[5] = {5, 4, 3, 46,6};
    int n=5;
    BubbleSort(arr,n);
    for(int i=0;i<n;i++){
        if (i > 0) {
            cout << ",";
        }
        cout << arr[i];
    }
    
    


    return 0;
}