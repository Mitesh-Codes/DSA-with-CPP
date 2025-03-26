#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    cout<<"Printing the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Printing is done";
}

int getMax(int num[],int n){
    int maxi=INT16_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,num[i]);
        // if(num[i]>max){
        //     max=num[i];
        // }
    
    }
    return maxi;
}
int getMin(int num[],int n){
    int mini=INT16_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,num[i]);
        
        // if(num[i]<min){
        //     min=num[i];
        // }
    
    }
    return mini;
}



int main(){

    // int number[3]={5,4,6};
    // //cout<<number[1];
    // int arr[4]={0};
    // cout<<(arr[1]);

    // int third[5]={2,3,4,1};
    // //printArray(third,9);

    // int sizeofthird=sizeof(third)/sizeof(int);
    // //cout<<sizeofthird;

    // char ch[4]={'a','b','c','d'};
    // cout<<ch[3];

    int size;
    cout<<"Enter the size of array:";
    cin>>size;

    int num[10];

    for(int i=0;i<size;i++){
        cin>>num[i];
    }
    int a=getMax(num,size);
    cout<<"Max number is:"<<a<<endl;
    int b=getMin(num,size);
    cout<<"Min Number is:"<<b;


}