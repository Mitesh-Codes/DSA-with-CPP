#include<iostream>
#include<string>
//#include<hero.h> // include header file for class hero
using namespace std;

class hero{
    public:
    string name;
    private:
    int health;
    //private:
    char level;
    //Getter and setter
    public:
    int gethealth(){
        return health;
    }
    void sethealth(int h){
        health=h;
    }


    void printf(){
        cout<<level<<endl;
    //private class can be accessed only inside class
    }
};
// class empty{

// };

int main(){
    /*
    hero h1; // object creation
    //cout<<sizeof(h1)<<endl; // size of object : 8 bytes because of padding
    // 1 byte for char + 4 bytes for int + 3 bytes padding = 8 bytes
    // The compiler adds padding to ensure that the data members are aligned in memory.

    //empty e1;
    //cout<<sizeof(e1)<<endl; // size of object : 1 bytes because of empty class
    // empty class will take 1 byte of memory because of the compiler's rule that every object must have a unique address.

    //We acn also include a class from oter file by using #include "filename.h"
    //But we have to make sure that the header file is in the same directory as the source file or provide the correct path to the header file.

    hero paul;
    // cout<<paul.health<<endl;
    // cout<<paul.level<<endl; // private member cannot be accessed outside the class

    // paul.health=70;
    // paul.level='A';
    // cout<<paul.health<<endl;
    // cout<<paul.level<<endl;

    //To access private members, we can use getter and setter methods.
    // cout<<paul.gethealth()<<endl; // getter method to access private member
    // paul.sethealth(70);
    // cout<<paul.gethealth()<<endl; // getter method to access private member

    //Static allocation
    hero h2;
    

    //Dyanamic memory allocation
    hero *jin=new hero;
    (*jin).sethealth(90);
    cout<<(*jin).gethealth()<<endl;
    (*jin).name="jin";
    cout<<(*jin).name<<endl;
    jin->sethealth(90); // using arrow operator to access private member
    cout<<jin->gethealth()<<endl;
    
    */

    

    return 0;
}