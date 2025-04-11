#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    vector<int> ans;
    int count=0;
    int total=row*col;

    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    while(count<total){
        for(int index=startingCol;count<total && index<=endingCol;index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        for(int index=startingRow;count<total && index<=endingRow;index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        for(int index=endingCol;count<total && index>=startingCol;index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        for(int index=endingRow;count<total && index>=startingRow;index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;

    }
    return ans;
//time complexity is O(n*m) and space complexity is O(1)
}


void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    int col=matrix[0].size();
    int start=0;
    int end=row*col-1;

    int mid=start+(end-start)/2;

    while(start<=end){
        int element=matrix[mid/col][mid%col];
        if(element==target){
            return true;
        }
        if(element<target){
            start=mid+1;
        }
        if(element>target){
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return 0;
//time complexity is O(log(n*m)) and space complexity is O(1)
}

bool searchMatrixII(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    int col=matrix[0].size();
    int rowIndex=0;
    int colIndex=col-1;
    while(rowIndex<row && colIndex>=0){
        int element=matrix[rowIndex][colIndex];
        if(element==target)
            return true;
        if(target>element)
            rowIndex++;
        else
            colIndex--;
        }
    return 0;
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


    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    // int nRows = arr.size();
    // int mCols = arr[0].size();
    // vector<int> result = wavePrint(arr, nRows, mCols);
    // cout << "Wave Print: ";
    // for (int i : result) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    // vector<int> result = spiralOrder(arr);
    // cout << "Spiral Order: ";
    // for (int i : result) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    // rotate(arr);
    // cout << "Rotated Matrix: " << endl;
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = 0; j < arr[i].size(); j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    // int target=5;
    // if(searchMatrix(arr,target)){
    //     cout<<"Element is present in the matrix"<<endl;
    // }
    // else{
    //     cout<<"Element is not present in the matrix"<<endl;
    // }
    // cout<<endl;

    vector<vector<int>> arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    if(searchMatrixII(arr,target)){
        cout<<"Element is present in the matrix"<<endl;
    }
    else{
        cout<<"Element is not present in the matrix"<<endl;
    }
    cout<<endl;





    
    return 0;
}
