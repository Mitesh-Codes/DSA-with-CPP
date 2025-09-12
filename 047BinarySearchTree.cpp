#include<iostream>
#include<queue>
using namespace std;

class Node{
    public: 
        int data;
        Node*left;
        Node*right;

        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};

Node* minVal(Node*root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node*root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}


Node* insertIntoBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(Node * &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }

}

void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp-> left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


//Search In BST
 // TC: O(logn), worst case: O(n);
 // SC: O(Height)
bool search(Node* root, int x) {
    // Your code here
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data>x){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}
//iterative way
 // Time Complexity: O(h) → O(log n) average, O(n) worst
 // Space Complexity: O(1)

Node* searchBST(Node* root, int data) {
        Node *temp=root;
        while(temp!=NULL){
            if(temp->data==data){
                return temp;
            }
            if(temp->data>data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        return NULL;
}


//Deletion from a BST
Node* deleteFromBst(Node* root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBst(root->right,mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left=deleteFromBst(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBst(root->right,val);
        return root;
    }
}

int main(){

    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    //levelOrderTraversal(root);

    //Search In BST
     if (search(root, 5)) {
        cout << 5 << " found in BST" << endl;
    }
    else {
        cout << 5 << " not found in BST" << endl;
    }
    //iterative way
    if(searchBST(root,5)){
      cout << 5 << " found in BST" << endl;
    }
    else {
        cout << 5 << " not found in BST" << endl;
    }

    //Min and max value
    cout<<"Min value is : "<<minVal(root)->data<<endl;
    cout<<"Max value is: "<<maxVal(root)->data<<endl;

    //deletion
    root=deleteFromBst(root,9);
    cout<<"Max value is: "<<maxVal(root)->data<<endl;

    if(searchBST(root,9)){
      cout << 9 << " found in BST" << endl;
    }
    else {
        cout << 9 << " not found in BST" << endl;
    }



    return 0;
}
