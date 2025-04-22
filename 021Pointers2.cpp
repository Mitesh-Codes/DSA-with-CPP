#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl; //this will print the value of the first element of the array
    cout<<p<<endl; //this will print the address of the first element of the array
    cout<<&p<<endl; //this will print the address of the pointer
}

void update (int *p){
    //p=p+1;
    //cout<<"Inside "<<p<<endl;

    //But value can be changed 
    *p=*p+1;
}

int getSum(int arr[]){//Or int *arr //Both are same)
    //cout<<endl<<"Size : "<<sizeof(arr)<<endl; //this will print 8 or 4(based on system- 64 bit or 32 bit) because arr is a pointer to the array and it is 8 bytes in size
    
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=i[arr];
    }
    return sum;

}

//We can send also a part of array bcz pointer is passing to function
int getSum2(int *arr,int n){//Or int *arr //Both are same)
    //cout<<endl<<"Size : "<<sizeof(arr)<<endl; //this will print 8 or 4(based on system- 64 bit or 32 bit) because arr is a pointer to the array and it is 8 bytes in size
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=i[arr];
    }
    return sum;

}

int main(){

    /*
    int arr[10]={45,5,6,35};
    cout<<"address of first memory block is "<<arr<<endl;
    cout<<"address of first memory block is "<<&arr[0]<<endl;

    cout<<"1st value "<<*arr<<endl;
    cout<<"1st value "<<arr[0]<<endl;

    cout<<*arr+1<<endl;

    cout<<*(arr+1)<<endl;

    cout<<arr+1<<endl;
    cout<<arr+2<<endl;

    cout<<3[arr]<<endl;; //prints 4 element of the array
    cout<<*(3+arr)<<endl; //same as above
   
    int temp[10]={1,2,3,4,5};
    cout<<sizeof(temp)<<endl; //this will print 40 because int is 4 bytes and there are 10 elements in the array
    cout<<sizeof(*temp)<<endl; //this will print 4 because *temp is an int and it is 4 bytes in size
    cout<<sizeof(&temp)<<endl; //this will print 8 or 4(based on system- 64 bit or 32 bit) because &temp is a pointer to the array and it is 8 bytes in size
    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl; //this will print 4 because *ptr is an int and it is 4 bytes in size
    cout<<sizeof(&ptr)<<endl; //this will print 8 or 4(based on system- 64 bit or 32 bit) because &ptr is a pointer to the int and it is 8 bytes in size
    

    int a[20]={0,76,9,84,65};
    cout<<&a<<endl; //this will print the address of the first element of the array
    cout<<a<<endl; //this will print the address of the first element of the array
    cout<<&a[0]<<endl; //this will print the address of the first element of the array

    int *p=&a[0];
    cout<<p<<endl; //this will print the address of the first element of the array
    cout<<*p<<endl; //this will print the value of the first element of the array
    cout<<&p<<endl; //this will print the address of the pointer
    //a=a+1; //this will give ERROR because a is an array and we cannot change the address of an array
    //but
    p=p+1; //this will work because p is a pointer and we can change the address of a pointer
    //Now its pointing to the second element of the array
    cout<<p<<endl;
    cout<<*p<<endl;

    */


    //Character Array

    /*
    char name[6]="abcde";
    int arr[5]={1,2,3,4,5}; 
    cout<<name<<endl; //this will print abcde
    cout<<arr<<endl; //this will print the address of the first element of the array

    char *c=&name[0]; //this will point to the first element of the array
    cout<<c<<endl; //this will print abcde

    char temp='z';
    char *p=&temp; //this will point to the first element of the array
    cout<<p<<endl; //this will print z + smiley face???? because it is a character and it will print till it finds a null character

    */

    //Passing pointer to function
    int value=5;
    int *p=&value;
    //print(p);

    //cout<<"Before update "<<p<<endl;
    update(p);
    //cout<<"After update "<<p<<endl; //Same. WHY?? -> because we are passing the pointer by value and not by reference. So, the address of p is not changed in the main function.

    //cout<<"Before update "<<*p<<endl;
    update(p);
    //cout<<"After update "<<*p<<endl; //But value can be changed.



    //When we are passing the array to the function, we are passing the address of array
    int arr[5]={1,2,3,4,5};
    cout<<getSum(arr)<<endl;

    int arr2[6]={1,2,3,4,5,8};
    cout<<getSum2(arr2+3,3)<<endl; //this will pass the address of the second element of the array to the function getSum2
    
    
    return 0;
}