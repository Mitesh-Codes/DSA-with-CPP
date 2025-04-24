#include<iostream>
using namespace std;

#define PI 3.14 //MACROs
#define square(x) ((x)*(x))  //MACROs
#define min(a,b) (((a)<(b))?(a):(b)) //MACROs


int score =0; //GLOBAL variable , not a good practice to use global variable in large programs

//Inline function

inline int add(int a ,int b){
    return a+b; // only one line of code in the function
    //Inline function is used to reduce the function call overhead and it is used when the function is small and called frequently
}

//default argument
void print(int arr[], int n, int start=0){ // we cannot assign deafult value to n before start but both can be assigned default value 
    for(int i=start;i<n;i++){
        cout<<arr[i]<<" ";
    }
//If we want to assign default value to the leftmost parameter, we have to use function overloading
//default argument is used to assign default value to the function parameter if the user doesn't pass the value of the parameter
}



int main(){

//MACROs
    int r=5;
    float a=5.67, b=5.66667;
    float area=PI*r*r;
    cout<<"Area of circle is: "<<area<<endl;
    cout<<"Area of square is: "<<square(r)<<endl; //MACROs
    cout<<"Minimum of a,b is: "<<min(a,b)<<endl;

    
    
//GLOBAL variable
    cout<<"Score is: "<<score<<endl; 
    score++;
    cout<<"Score is: "<<score<<endl; 
    //Disadvantage of global variable is that it can be changed in any function and it is not good for large programs
    //So, we should use global variable only when it is necessary


//Inline function
    int x=5, y=10;
    cout<<"Sum of x and y is: "<<add(x,y)<<endl; //Inline function
    //Inline function is used to reduce the function call overhead and it is used when the function is small and called frequently

    //Inline function is not always inline, it is just a suggestion to the compiler to inline the function


//default argument
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array is: ";
    print(arr,size); //default argument , here we didn't pass the start argument so it will take the default value of 0
    print(arr,size,5); //default argument , here we passed the start argument so it will take the value of 5
    cout<<endl;

    //in default argument, we can only assign default value to the RIGHTMOST parameter of the function
    //If we want to assign default value to the leftmost parameter, we have to use function overloading



//Constants variable
    const int x=10; //constant variable, we cannot change the value of x after this
    //x=20; //error: assignment of read-only variable 'x'



    return 0;
}