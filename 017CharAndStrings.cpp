#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
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


void replaceSpaces(string &str) {
    int spaceCount = 0;
    int n = str.length();

    for (char ch : str) {
        if (ch == ' ') spaceCount++;
    }

    int newLength = n + spaceCount * 2;
    str.resize(newLength); 

 
    int i = n - 1;         
    int j = newLength - 1;   


    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}
//2nd method with O(n) time complexity and O(n) space complexity
string replaceSpaces_2nd_method(string &str){
	string temp="";
	for(int i=0;i<str.length();i++){
		
		if(str[i]==' '){
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}
		else{
			temp.push_back(str[i]);
		}
		
	}
	return temp;
}


string removeOccurrences(string s, string part) {
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}


bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    // Step 1: Count letters in s1
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for (char ch : s1) {
        count1[ch - 'a']++;
    }

    // Step 2: First window in s2
    for (int i = 0; i < s1.length(); i++) {
        count2[s2[i] - 'a']++;
    }

    // Step 3: Slide the window through s2
    for (int i = 0; i <= s2.length() - s1.length(); i++) {
        if (count1 == count2) return true;

        // Slide window: remove first char, add next char
        if (i + s1.length() < s2.length()) {
            count2[s2[i] - 'a']--;                        // remove leftmost
            count2[s2[i + s1.length()] - 'a']++;          // add new rightmost
        }
    }

    return false;
}


int compress(vector<char>& chars) {
    int i=0;
    int ansIndex=0;
    int n=chars.size();

    while(i<n){
        int j=i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }
        chars[ansIndex++]=chars[i];
        int count=j-i;

        if(count>1){
            string cnt=to_string(count);
            for(char ch:cnt){
                chars[ansIndex++]=ch;
            }
        }
        i=j;
    }
    return ansIndex;
//time complexity is O(n) and space complexity is O(1)
}

string removeDuplicates(string s) {
    string result="";
    for(char ch:s){
        if(!result.empty() && result.back()==ch ){
            result.pop_back();
        }
        else{
            result.push_back(ch);
        }
    }
    return result;

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

    // string s;
    // cout<<"Enter a string: ";
    // cin>>s;
    // cout<<"Max occurring character is: "<<getmaxOccuringChar(s)<<endl;

    // string str = "Mr John Smith";
    // int trueLength = 13;
    // replaceSpaces(str);
    // cout << "String after replacing spaces: " << str << endl;


    // string s="daabcbaabcbc";
    // string part="abc";
    // cout<<removeOccurrences(s,part)<<endl;


    // string s1 = "ab";
    // string s2 = "eidbaooo";
    // if (checkInclusion(s1, s2)) {
    //     cout << "s1's permutation is a substring of s2" << endl;
    // } else {
    //     cout << "s1's permutation is NOT a substring of s2" << endl;
    // }

   
    // vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // int newLength = compress(chars);
    // chars.resize(newLength); // Resize the vector to the new length
    // cout << "Compressed string: ";
    // for (char ch : chars) {
    //     cout << ch;
    // }
    // cout << endl;

    
    string s = "abbaca";
    string result = removeDuplicates(s);
    cout << "String after removing duplicates: " << result << endl;


    return 0;
}
