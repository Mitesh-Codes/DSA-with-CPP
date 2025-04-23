#include<iostream>
using namespace std;

void update(int **p2){
    //p2=p2+1;
    //nothing will change in main function

    //*p2=*p2+1;
    //this will change the address of p in main function because we are passing the address of p2 and not p2 itself.

    //But value can be changed 
    **p2=**p2+1;
    //this will change the value of i in main function because we passing the double pointer which coinatins the address of p which contains the address of i.
}

void update2(int n){
    n++;
}

void update3(int &n){
    n++;
}
    //this will change the value of i in main function because we passing the reference of n which is same as i.


int main(){

    /*
    int i=5;
    int *p=&i;
    int **p2=&p; //Pointer to pointer
    // cout<<"i value "<<i<<endl;
    // cout<<"i address "<<&i<<endl;
    // cout<<"adrress of i by p "<<p<<endl;
    // cout<<"p address "<<&p<<endl;
    // cout<<"p value (contain i value) "<<*p<<endl;
    // cout<<"address of p by p2 "<<p2<<endl; //it contains the address of p
    // cout<<"address of p2 "<<&p2<<endl;
    // cout<<"p2 value which contain p address which contain i address "<<*p2<<endl; //this will print the address of p
    // cout<<"i value through p2 "<<**p2<<endl; //this will print the value of i

    cout<<"Before update "<<i<<endl;

    update(p2); //this will change the value of i to 6
    cout<<"After update "<<i<<endl; //this will print the value of i which is 6

    */



    //Refernce variable
    // int i=5;

    // int &j=i; //this will create a reference variable j which will point to i

    // cout<<i<<endl;
    // i++;
    // cout<<i<<endl;
    // j++;
    // cout<<i<<endl;
    // cout<<j<<endl;


    //Update by passing the value of i; // value will not change in main function
    int k=0;
    update2(k);
    cout<<k<<endl; //this will print 0 because we are passing the value of j and not the address of j

    //Update by passing the address of i; passs by reference
    update3(k);
    cout<<k<<endl; //this will print 0 because we are passing the address of i and not the value of i

   


    return 0;
}