#include<iostream>
using namespace std;

int InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>key){
                //swap
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=key;
    }

}

int main(){

    int arr[5] = {3,7,8,2,9};
    int n = 5;
    InsertionSort(arr,n);
    for(int i=0;i<n;i++){
        if (i > 0) {
            cout << ",";
        }
        cout << arr[i];
    }


    return 0;
}