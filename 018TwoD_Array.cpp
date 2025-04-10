#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPresent(int arr[][4],int key,int row, int col){
    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
}

void rowSum(int arr[][4],int row, int col){
   for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
            
        }
        cout<<sum<<" ";
    }
    
}

void columnSum(int arr[][4],int row, int col){
    for(int j=0;j<col;j++){
         int sum=0;
         for(int i=0;i<row;i++){
             sum+=arr[i][j];
             
         }
         cout<<sum<<" ";
     }
     
 }

 void largestRowSum(int arr[][4],int row, int col){
    int max=INT16_MIN;
    int rowIndex=-1;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(sum>max){
            max=sum;
            rowIndex=i;
        }
    }
    cout<<"Largest row sum is: "<<max<<endl;
    cout<<"Row index is: "<<rowIndex<<endl;

 }

 vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int j=0;j<mCols;j++){
        if(j & 1){
            for(int i=nRows-1;i>=0;i--){
                ans.push_back(arr[i][j]);
            }

        }
        else{
             for(int i=0;i<nRows;i++){
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
//time complexity is O(n*m) and space complexity is O(1)
}

int main(){

    // int arr[3][4];
    // for(int i=0;i<3;i++){
    //     for (int j=0;j<4;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //2nd way to initialize 2D array
    // int arr2[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<arr2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //3rd way to initialize 2D array
    // int arr3[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<arr3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Enter the element to be searched: ";
    // int key;
    // cin>>key;
    // if(isPresent(arr3,key,3,4)){
    //     cout<<"Element is present in the array"<<endl;
    // }
    // else{
    //     cout<<"Element is not present in the array"<<endl;
    // }


    // int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // cout<<"Row sum is: "<<endl;
    // rowSum(arr,3,4);
    // cout<<endl;
    // cout<<"Column sum is: "<<endl;
    // columnSum(arr,3,4);
    // cout<<endl;
    
    // int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // largestRowSum(arr,3,4);
    // cout<<endl;


    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    int nRows = arr.size();
    int mCols = arr[0].size();
    vector<int> result = wavePrint(arr, nRows, mCols);
    cout << "Wave Print: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    
    return 0;
}