#include<iostream>
#include<string>

using namespace std;

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

    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
        
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }

    bool removeUtil(TrieNode* root, string word){
        if(word.length()==0){
            if(root->isTerminal){
                root->isTerminal=false;
            }
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    return false;
                }
            }
            return true;
            
        }

        int index=word[0]-'a';
        TrieNode* child=root->children[index];
        if(child==NULL){
            return false;
        }

        bool shouldDeleteChild=removeUtil(child,word.substr(1));
        if(shouldDeleteChild){
            delete child;
            root->children[index]=NULL;

            if(root->isTerminal==false){
                for(int i=0;i<26;i++){
                    if(root->children[i]!=NULL){
                        return false;
                    }
                }
                return true;
            }
        }
        return false; //why? because if we are not deleting the child then we should not delete the parent

    }
    void removeWord(string word){
        removeUtil(root,word);
    }
    

};


int main(){

    Trie* T=new Trie();
    T->insertWord("abcd");
    T->insertWord("ab");

    cout<<T->searchWord("abcd")<<endl;
    cout<<T->searchWord("ab")<<endl;

    T->removeWord("abcd");
    cout<<T->searchWord("abcd")<<endl;
    cout<<T->searchWord("ab")<<endl;


    return 0;
}