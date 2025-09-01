#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
  public:  
    int data;
    node*left;
    node* right;
  
  node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for insertong in left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp=q.front();
        
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

void reverseLevelOrderTraversal(node*root){
    if(!root){
        return;
    }
    stack<node*>s;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if (temp == NULL) {
            s.push(NULL); // marker for newline
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            s.push(temp);
            if(temp->right){
            q.push(temp->right);
            }
            if(temp->left){
            q.push(temp->left);
            }
        }
    }
    while (!s.empty()) {
        node* temp = s.top();
        s.pop();
        if (temp == NULL) {
            cout << endl;
        } else {
            cout << temp->data << " ";
        }
    }
}


void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder( node* &root){
    queue<node*>q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);

        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData; 
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }  
    }
}


//Question1: Count leaf nodes in a binary tree
void inorder(node*root, int &count){
    if(root==NULL){
        return;
    }
    inorder(root->left, count);

    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}

int noOfLeafNodes(node *root){
    // Write your code here.
    int count=0;
    inorder(root,count);
    return count;

}

int main(){

    node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //root=buildTree(root);
    // cout<<"Level Order Traversal is: "<<endl;
    // levelOrderTraversal(root);

    // cout << "Reverse Level Order Traversal: ";
    // reverseLevelOrderTraversal(root);

    // cout<<"Inorder Traversal is: "<<endl;
    // inorder(root);

    // cout<<endl<<"Preorder Traversal is: "<<endl;
    // preorder(root);

    // cout<<endl<<"Postorder Traversal is: "<<endl;
    // postorder(root);

    // buildFromLevelOrder(root);
    // // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // cout<<"Level Order Traversal is: "<<endl;
    // levelOrderTraversal(root);

//Question1: Count leaf nodes in a binary tree
    buildFromLevelOrder(root);
    cout << "Level Order Traversal is: " << endl;
    levelOrderTraversal(root);
    cout << "No of leaf nodes are: " << noOfLeafNodes(root) << endl;




    return 0;
}