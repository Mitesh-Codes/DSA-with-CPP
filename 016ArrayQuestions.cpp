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

void rotate(vector<int>& nums, int k) {
    vector<int>temp(nums.size());
    for(int i=0;i<nums.size();i++){
        temp[(i+k)%nums.size()]=nums[i];
    }
    nums=temp;
}
bool sortedAndRotated(vector<int>& nums) {
    int count=0;
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
    }
    if(nums[n-1]>nums[0]){
        count++;
    }
    return count<=1;
}



vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i=n-1;
	int j=m-1;
	vector<int>ans;
	int carry=0;
	while(i>=0 && j>=0){
		int val1=a[i];
		int val2=b[j];
		int sum=val1+val2+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while(i>=0){
		int sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}
	while(j>=0){
		int sum=b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
	}
	while(carry!=0){
		int sum=carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}
	return reverse(ans); 
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
    // int arr[5]={2,4,0,0,1};
    // MovesZeroes(arr,5);
    // print_Array(arr,5);

//question 4
    // vector <int> v;
    // v.push_back(11);
    // v.push_back(7);
    // v.push_back(3);
    // v.push_back(12);
    // v.push_back(4);
    // int k=3;
    // rotate(v,k);
    // print_vector(v);


//Question 5
    // vector <int> v;
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(12);
    // v.push_back(-1);
    // if(sortedAndRotated(v)){
    //     cout<<"Vector is sorted and rotated";
    // }
    // else{
    //     cout<<"Not";
    // }


//Question 6
    vector <int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(12);
    v.push_back(-1);

    vector <int> v2;
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    vector<int> ans=findArraySum(v,v.size(),v2,v2.size());
    print_vector(ans);


    return 0;
}
