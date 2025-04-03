#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

void merge(int arr[],int n, int arr2[],int m, int arr3[]){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr[i]<arr2[j]){
            arr3[k++]=arr[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr3[k++]=arr[i++];
    }
    while(j<m){
        arr3[k++]=arr2[j++];
    }
}

void MovesZeroes(int arr[],int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}

void print_vector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print_Array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

//Question 1
    // vector <int> v;
    // v.push_back(11);
    // v.push_back(7);
    // v.push_back(3);
    // v.push_back(12);
    // v.push_back(4);

    // vector<int> ans=reverse(v);
    // print_vector(ans);


//Question 2
    // int arr[5]={5,8,9,12,13};
    // int arr2[3]={2,4,11};
    // int arr3[8]={0};

    // merge(arr,5,arr2,3,arr3);
    // print_Array(arr3,8);


//Question 3
    int arr[5]={2,4,0,0,1};
    MovesZeroes(arr,5);
    print_Array(arr,5);



    return 0;
}