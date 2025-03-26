#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key){

    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}




int main(){

    int even[6]={2,4,7,9,12,64};
    int odd[5]={2,5,8,12,65};

    int index=binarySearch(odd,6,5);
    cout<<"Index of 5 is "<<index;



}