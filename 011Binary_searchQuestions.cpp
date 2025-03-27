#include<iostream>
using namespace std;



/*Question1
int firstocc(int arr[],int n,int k){
    int start=0,end=n-1;
    int mid=start+(end-start)/2;
    int answer=-1;

    while(start<=end){
        if(arr[mid]==k){
            answer=mid;
            end=mid-1;
        }
        else if(arr[mid]<k){
            start=mid+1;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return answer;
}

int lastocc(int arr[],int n,int k){
    int start=0,end=n-1;
    int mid=start+(end-start)/2;
    int answer=-1;

    while(start<=end){
        if(arr[mid]==k){
            answer=mid;
            start=mid+1;
        }
        else if(arr[mid]<k){
            start=mid+1;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return answer;
}

*/


/*Question2
int peakIndex(int arr[],int size){
    int s=0;
    int e=size-1;
    while(s<e){
         int mid=s+(e-s)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
        
    }
    return -1;
}

*/


/*question3*/
int pivotElement(int arr[],int size){
    int s=0;
    int e=size-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=e+(s-e)/2;
    }
    return s;
}

/*question 4*/
long long int binarySearch(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
    if(square==n){
            return mid;
        }
        else if(square>n){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

long double morePrecise(int n,int precision,int tempSol){
    long double factor=1;
    long double ans=tempSol;
    for(double i=0;i<precision;i++){
        factor=factor/10;
        for(long double j=ans;j*j<n;j=j+factor){
            ans=j;

        }
    }
    return ans;

}

/*question 5*/
//BOOK ALLOCATION PROBLEM
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount=1;
    int pageSum=0;
  

    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m||arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}



int findPages(int arr[], int n, int m) {
    int s=0;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    if(n<m){
        ans=-1;
    }
    return ans;

}






int main(){
    /*question1
    int arr[11]={0,1,1,1,3,4,5,6,6,7,8};
    cout<<"First position is "<<firstocc(arr,11,1)<<endl;
    cout<<"last position is "<<lastocc(arr,11,1)<<endl;
    */
    
    /*question2
    int arr[8]={0,3,4,5,99,6,5,2};
    cout<<"Peak element index is "<<peakIndex(arr,8);
    */

   /*question3*/
   //int arr[7]={17,89,4,6,9,14,15};
   //cout<<"Peak element is:"<<pivotElement(arr,7);


   //question4
   int n;
   cout<<"enter a number:";
   cin>>n;
   int tempSol=binarySearch(n);
   cout<<"Answewr is "<<morePrecise(n,5,tempSol)<<endl;

    //question5
   int arr[]={25, 46, 28, 49, 24};
   int n=5;
   int m=4;
   int result = findPages(arr, n, m);
   cout << "Minimum number of pages: " << result << endl;
   

   return 0;


}



    




 
