#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){                 //for(int i=1,i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-(i+1);j++){            //for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}

            // TIME COMPLEXITY: O(n^2)
            //if array is already sorted, it will take O(n) time.
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