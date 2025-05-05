#include<iostream>
using namespace std;

//Bubble Sort by recursion
void BubbleSort(int *arr,int n){
    if(n==0||n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    BubbleSort(arr,n-1);
    //Time complexity: O(n^2) and space complexity: O(n)
}

//Insertion sort by Recursion
void InsertionSort(int *arr,int n){
        if (n <= 0)
            return;
    
        // Sort first n-1 elements recursively
        InsertionSort(arr, n - 1);
    
        // Insert arr[n] into the sorted part
        int key = arr[n];
        int j;
    
        for (j = n - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
    
        arr[j + 1] = key;
  //Time complexity: O(n^2) and space complexity: O(n)  
}

//Selection Sort using recursion
void selectionSort(int *arr,int n){
    if(n==0||n==1){
        return;
    }
    int minIndex=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }

    }
    swap(arr[minIndex],arr[0]);
    selectionSort(arr+1,n-1);
    //Time complexity: O(n^2) and space complexity: O(n)
    
}

//MERGE SORT using recursion
//Time Complexity: O(n log n) in all cases.
//Space Complexity: O(n) due to the temporary arrays used in merging.
void merge(int*arr,int s, int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int [len1];
    int *second= new int[len2];

    //Copy values
    int mainArrayIndex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //Merge two sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr,int s, int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;

    //Left part sort
    mergeSort(arr,s,mid);
    //Right part sort
    mergeSort(arr,mid+1,e);

    //Merge the two parts
    merge(arr,s,e);
}

//INVERSION COUNT using Merge Sort
//Time Complexity: O(n log n) in all cases.
//Space Complexity: O(n) due to the temporary arrays used in merging.
int merge2(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // Copy elements into temporary arrays
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    // Merge and count inversions
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;
    int invCount = 0;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
            invCount += (len1 - index1); // Key inversion logic
        }
    }

    // Copy remaining elements
    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];
    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];

    delete[] first;
    delete[] second;

    return invCount;
}

int mergeAndCount(int *arr,int s,int e){
    if(s>=e){
        return 0;
    }
    int mid=s+(e-s)/2;

    int count=mergeAndCount(arr,s,mid)+mergeAndCount(arr,mid+1,e);

    //Merge the two parts
    count+=merge2(arr,s,e);
    return count;
}


//Quick Sort
//time complexity: O(n^2) in worst case and O(n log n) in average case.
//Space complexity: O(log n) or O(n) .
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){    
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(i<pivotIndex && arr[i] <= pivot){
            i++;
        }
        while(j>pivotIndex && arr[j]>=pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}

void quickSort(int arr[],int s,int e){
    //Base case
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){

    //int arr[]={324,32,443,5,4,345,34,64,365,75,75,65,46,45,34,454353,45,66,3243,3199,23,23};
    //int n=sizeof(arr)/sizeof(int);
    
    //BubbleSort(arr,n);

    //InsertionSort(arr, n - 1)  // n-1 because we use 0-based index
    
    //selectionSort(arr,n);

    //mergeSort(arr,0,n-1); //Time Complexity: O(n log n) in all cases. //Space Complexity: O(n) due to the temporary arrays used in merging.

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    //Inversion Count using Merge Sort
    // int arr2[]={5,3,4,1,2};
    // int n2=sizeof(arr2)/sizeof(int);
    // int inversionCount=mergeAndCount(arr2,0,n2-1);
    // cout<<"Inversion Count: "<<inversionCount<<endl;

    
    
//Quick sort using recursion
    //Time Complexity: O(n^2) in worst case and O(n log n) in average case.
    //Space Complexity: O(log n) or O(n) .
    int arr[]={-2,3,3,4,4,6};
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;



    return 0;
}

