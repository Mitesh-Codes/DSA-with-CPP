#include<iostream>
using namespace std;

int getLengthOfString(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

void reverseString(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
}
char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
    
}

bool checkPalindrome(char a[],int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        while(s<e && !isalnum(a[s])){
            s++;
        }
        while(s<e && !isalnum(a[e])){
            e--;
        }
        if(toLowerCase(a[s])!=toLowerCase(a[e])){
            return false;
        }
            
        s++;
        e--;
    }
    return true;
}


int main(){

    char name[200];
    cout<<"Enter your name: ";
    cin.getline(name, 200);
    //name[2]='\0';
    cout<<"Your name is \"";
    cout<<name<<"\""<<endl;
    int length=getLengthOfString(name);
    cout<<"Length of the string is "<<length<<endl;
    //reverseString(name,length);
    //cout<<name<<endl;

    
    if(checkPalindrome(name,length)){
        cout<<"Your string is a palindrome"<<endl;
    }
    else{
        cout<<"Nah. Not a Palindrome"<<endl;
    }
    
    //cout<<toLowerCase('b')<<endl;
    //cout<<toLowerCase('B')<<endl;


    return 0;
}