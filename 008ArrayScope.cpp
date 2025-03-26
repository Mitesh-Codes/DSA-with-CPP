#include<iostream>
using namespace std;

// void update(int arr[],int n){
//     cout<<"Inside the function"<<endl;
//     arr[0]=120;

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

void reverse(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main(){
    // int arr[]={1,2,3};
    // cout<<endl<<"Printing in main function"<<endl;
    // for(int i=0;i<3;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // update(arr,3);

    // cout<<endl<<"after return,Printing in main function"<<endl;
    // for(int i=0;i<3;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    int arr[6]={2,3,1,3,4,3};
    int brr[5]={34,765,854,3,4};

    reverse(arr,6);
    reverse(brr,5);
    printArray(arr,6);
    printArray(brr,5);


}