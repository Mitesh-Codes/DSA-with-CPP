#include<iostream>
#include<string>
#include<algorithm>
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
string reverseWords(string s) {
    int start = 0;
    int n = s.length();

    for (int end = 0; end <= n; ++end) {
        // If we reach a space or the end of the string
        if (end == n || s[end] == ' '){
            // Reverse the word in place
            reverse(s.begin() + start, s.begin() + end);
            // Move start to the beginning of the next word
            start = end + 1;
        }
    }

    return s;
}

char getmaxOccuringChar(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;
        number=ch-'a';
        arr[number]++;
    }
    int maxi=-1, ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }
    return ans+'a';
//time complexity is O(n) and space complexity is O(1)
}
    

int main(){

    // char name[200];
    // cout<<"Enter your name: ";
    // cin.getline(name, 200);
    // //name[2]='\0';
    // cout<<"Your name is \"";
    // cout<<name<<"\""<<endl;
    // int length=getLengthOfString(name);
    // cout<<"Length of the string is "<<length<<endl;
    // //reverseString(name,length);
    // //cout<<name<<endl;

    
    // if(checkPalindrome(name,length)){
    //     cout<<"Your string is a palindrome"<<endl;
    // }
    // else{
    //     cout<<"Nah. Not a Palindrome"<<endl;
    // }
    
    //cout<<toLowerCase('b')<<endl;
    //cout<<toLowerCase('B')<<endl;

    // string input;
    // cout << "Enter a sentence: ";
    // getline(cin, input);

    // string result = reverseWords(input);
    // cout << "Reversed each word: " << result << endl;

    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Max occurring character is: "<<getmaxOccuringChar(s)<<endl;



    return 0;
}
