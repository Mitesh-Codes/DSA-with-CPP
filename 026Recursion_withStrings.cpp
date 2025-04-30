#include<iostream>
#include<string>
using namespace std;

void reverseString(int i,int j,string &name){
    if(i>j){
        return;
    }
    swap(name[i],name[j]);
    i++;
    j--;
    reverseString(i,j,name);
}

bool checkPalindrome(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
    
        return checkPalindrome(str,i+1,j-1);
    }
}

int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);
    if(b&1){
        return a*ans*ans;
    }
    else{
        return ans*ans;
    }
}







int main(){

    // string name="naman";
    // int namesize=name.length()-1;
    // //reverseString(0,namesize,name);
    // //cout<<name<<endl;

    // bool ans=checkPalindrome(name,0,namesize);
    // cout<<ans<<endl;

    // int a=2;
    // int b=3;
    // int ans=power(a,b);
    // cout<<ans<<endl;

    



    return 0;
}
