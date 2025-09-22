#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Question1: Longest Common Prefix
//Approach 1: Horizontal Scanning  // TC O(N*M)  SC O(1)
/*
string commonPrefix(vector<string> &arr, int n)
{
	if(n == 0) return "-1"; 
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];

        bool match=true;

        for(int j=1;j<n;j++){
            if(arr[j].length()<=i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
        
    }
    if(ans.empty()) return "-1";  // important fix for no common prefix
    return ans;
}
//Approach 2: Using Trie //but here TC is O(N*M) SC is O(N*M)
class TrieNode{
    public:
        char data;
        TrieNode* children[52];
        int childCount;
        bool isTerminal;

        TrieNode(char ch){
             data=ch;
            for(int i=0;i<52;i++){
                children[i]=NULL;
            }
            childCount=0;
            isTerminal=false;
     }
};
class Trie{
    public:
        TrieNode*root;
        Trie(char ch){
            root=new TrieNode(ch);
        }
        int getIndex(char ch){
        if(ch >= 'a' && ch <= 'z') return ch - 'a';
        else return ch - 'A' + 26;
        }
        void insertUtil(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int index = getIndex(word[0]);
            TrieNode* child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                child=new TrieNode(word[0]);
                root->childCount++;
                root->children[index]=child;
            }
            insertUtil(child,word.substr(1));
        }
        void insertWord(string word){
            insertUtil(root,word);
        }

        void lcp(string str, string &ans){
            TrieNode* curr = root;  // <-- added local pointer
            for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(curr->childCount==1){
                ans.push_back(ch);
                int index = getIndex(ch);  // <-- changed here
                curr = curr->children[index];  // <-- use local pointer
            }
            else{
                break;
            }
            if(curr->isTerminal){
                break;
            }
    }
}

};
string commonPrefix2(vector<string> &arr, int n)
{
	if(n == 0) return "-1";
    Trie*t=new Trie('\0');
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    if(ans.empty()) return "-1";
    return ans;
}
*/

//Question2: Implement a Phone Directory
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data =ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }


void printSuggestions(TrieNode* curr,vector<string> &temp, string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
        
        
    }
    for(char ch='a';ch<='z';ch++){
        TrieNode* next=curr->children[ch-'a'];
        if(next!=NULL){
            prefix.push_back(ch);
            printSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(string str){
    TrieNode*prev=root;
    vector<vector<string>> output;
    string prefix="";
    for(int i=0;i<str.length();i++){
        char lastch=str[i];
        prefix.push_back(lastch);

        TrieNode* curr=prev->children[lastch-'a'];
        if(curr==NULL){
            break;
        }
        vector<string> temp;
        printSuggestions(curr,temp,prefix);
        output.push_back(temp);
        temp.clear();
        prev=curr;
    }
    return output;
}
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t=new Trie();

    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestions(queryStr);
}


int main(){

//Question1: Longest Common Prefix
    // vector<string> arr = {"flower","flow","flight"};
    // int n = arr.size();
    // cout<<commonPrefix(arr,n)<<endl;
    // //Approach 2: Using Trie
    // cout<<commonPrefix2(arr,n)<<endl;


//Question2: Implement a Phone Directory
    vector<string> contactList={"geeikistest","geeksforgeeks","geeksfortest"};
    string queryStr="geeips";
    vector<vector<string>> ans=phoneDirectory(contactList,queryStr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }





    return 0;
}