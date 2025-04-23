#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){

    // int n;
    // cin>>n;

    // //variable size array
    // int *arr=new int[n]; //this will create an array of size n in heap memory

    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // int ans=getSum(arr,n);
    // cout<<ans<<endl;

    // delete [] arr; // or delete i(if variable) //this will delete the array from heap memory. its important to delete the array after using it to avoid memory leak


//2D array by dyanmic memeory allocation

    // int n;
    // cin>>n;
    // int **arr2=new int*[n]; //this will create an array of size n in heap memory
    // for(int i=0;i<n;i++){
    //     arr2[i]=new int[n];
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>arr2[i][j];
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // Release the memory
    // for(int i=0;i<n;i++){
    //     delete [] arr2[i];
    // }
    // delete [] arr2;
    


    //2D array of m*n size;
    // int row;
    // int col;
    // cin>>row;
    // cin>>col;
    // int **arr3=new int *[row];
    // for(int i=0;i<row;i++){
    //     arr3[i]=new int[col];
    // }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cin>>arr3[i][j];
    //     }
    // }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<arr3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // //Release the memory
    // for(int i=0;i<row;i++){
    //     delete [] arr3[i];
    // }
    // delete [] arr3;
   
   
    
    //Jagged array
    int row1=3;
    int *jagged[row1];
    int colsize[row1];

    for(int i=0;i<row1;i++){
        cout << "Enter number of columns for row " << i << ": ";
        cin>>colsize[i];
        jagged[i]=new int[colsize[i]];
    }
    //free memory
    for(int i=0;i<row1;i++){
        delete [] jagged[i];
    }


    
    
    
    
    return 0;
}