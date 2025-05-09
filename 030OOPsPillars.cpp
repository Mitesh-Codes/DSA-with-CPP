#include<iostream>
#include<string>
using namespace std;

//1.Encapsulation
//2.Inheritance 
//3.Polymorphism
//4.Absraction

//Encapsulation
class Student{
    private:
        string name;
        int age;
        int height;
    
    public:
        int getAge(){
            return this->age;
        }

};

//Inheritance

//Single inheritance
class Human{
    public:
    int height;
    int weight;
    int age;
    void speak(){
        cout<<"Human is speaking"<<endl;
    }
    public:
    int getAge(){
        return this->age;
    }
    int setWeight(int w){
        return this->weight=w;
    }


};

class Male:public/*protected*//*private*/ Human{
    public:
    string color;
    
    void sleep(){
        cout<<"Male is sleeping"<<endl;
    }
    int getHeight(){
        return this->height;
    }
};

//MultiLevel inheritance // Huamn -> Male -> indianMale
class indianMale:public Male{
    public:
    string language;
};

//Mutiple inheritance
class Animal{
    public:
    void eat(){
        cout<<"Animal is eating"<<endl;
    }
    int height;

};

class hybrid: public Animal,public Human{
    //Ambiguity



};

//Hierarchical inheritance // Human -> to both male and female
class Female:public Human{
    public:
    string talking;


};

//Hybrid Inheritance 
class Love: public Animal, public Human{

};




//Polymorphism
  //Compiler Time overloading
    //Function overloading
class A{
    public:
    void sayhello(){
        cout<<"Hello"<<endl;

    }
    void sayhello(string name){
        cout<<"Hello"<<name<<endl;
    }

    //Not compatible
    /*int sayhello(){
        cout<<"hello"<<endl;
    }*/

};

    //Operator overloading
class B{
    public :
    int a;
    int b;
    public:
    int add(){
        return a+b;

    }
    void operator+ (B &obj){
        int value1=this -> a;
        int value2=obj.a;
        cout<<"output: "<<value2-value1<<endl;
    }
    void operator-(B &obj){
        cout<<"Hello"<<endl;
    }
};


  //Run time overloading 
class Animal2{
    public:
    void speak(){
        cout<<"Speaking";
    }

};

class Dog:public Animal2{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};




//Abstraction
class Abstract{
    private:
    int a, b;
    public:
    void set(int x, int y){
        a=x;
        b=y;
    }
    void display(){
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
};










int main(){

   
//1.Encapsulation
    //Encapsulation is the bundling of data and methods that operate on that data within one unit, such as a class.
    //Student first; // In encapsultion , student all data members  are private and we can only read it.

//2.Inheritance
    //In inheritance, we can create a new class that inherits the properties of an existing class.
    //This allows us to create a new class that has all the properties of the existing class, but also has its own unique properties.
    //Male object1;
    //Human one;
    //cout<<object1.age<<endl;
    //cout<<object1.weight<<endl;
    //cout<<object1.color<<endl;
    //object1.sleep();

    //object1.setWeight(75);
    //cout<<object1.weight<<endl;
    //cout<<one.weight<<endl; // parent class value doesn't change if we change the value of child class
    //cout<<object1.getHeight()<<endl;
   
   
//MultiLevel inheritance
    //indianMale ramesh;
    //ramesh.speak(); //we can access human class through (grand)child class 

//Mutiple inheritance
    //hybrid h1;
    //h1.eat(); // we can access animal class through child class
    //h1.speak(); // we can access human class through child class

//Hierarchical inheritance
    //In hierarchical inheritance, multiple classes inherit from a single parent class.
    //Male m1;
    //Female f1;
    //m1.speak(); // we can access human class through child class
    //f1.speak(); // we can access human class through child class

//Hybrid Inheritance
    //Hybrid inheritance is a combination of more than one type of inhertance
    //Love l1;


//Inheritance Ambiguity
    //Both human and animal class have height data memeber so if we use class hybrid , which inherit both animal and human , we need to give it instructions on which height to use
    //hybrid h1;
    //h1.Human::height;







//Polymorphism
    // B obj1, obj2;
    // obj1.a=4;
    // obj2.a=7;

    // obj1+obj2;

    // B obj1,obj2;
    // obj1-obj2;



//Run time poly 
    //function overriding
    //Dog d1;
    //d1.speak(); //








//Abstraction
 //showing use essential info and hiding all the complexity.
    Abstract a1;
    a1.set(10,20);
    a1.display();




    return 0;
}