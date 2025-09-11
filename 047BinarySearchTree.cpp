#include<iostream>
#include<climits>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

class BinaryTreeNode{
    public: 
        int data;
        BinaryTreeNode*left;
        BinaryTreeNode*right;

        BinaryTreeNode(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};



//Question1: Validate BST
bool isBST(BinaryTreeNode* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>min && root->data<max){
        bool left=isBST(root->left, min, root->data);
        bool right=isBST(root->right, root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode* root) 
{
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);

}


//Question2: Find K-th smallest element in BST
int solve(BinaryTreeNode*root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);

    

}
int kthSmallest(BinaryTreeNode* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root, i,k);
    return ans;
}

//Question3: Predecessor ans Successor in BST
pair<int, int> predecessorSuccessor(BinaryTreeNode *root, int key){
    // Write your code here.
    BinaryTreeNode*temp=root;
    int pred=-1;
    int succ=-1;

    while(temp != NULL && temp->data != key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
            
        }
        else{
            pred=temp->data;
            temp=temp->right;
            
        }
    }
    if (temp == NULL) {
        return {pred, succ};
    }

    BinaryTreeNode * leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    BinaryTreeNode * rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred, succ);
    return ans;
}

//Question4: LCA in BST
BinaryTreeNode *LCAinaBST(BinaryTreeNode *root, BinaryTreeNode *P, BinaryTreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return NULL;
    }
    if(root->data< P->data && root->data< Q->data){
        return LCAinaBST(root->right, P,Q);
    }
    if(root->data> P->data && root->data> Q->data){
        return LCAinaBST(root->left, P,Q);
    }
    return root;
}
BinaryTreeNode* searchBST(BinaryTreeNode* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

//Question5: Two Sum In BST
void inorder(BinaryTreeNode* root, vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	//Write your code here
    vector<int> inorderVal;
    inorder(root,inorderVal);
    int i=0, j=inorderVal.size()-1;
    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;

}

//Question6: Flatten BST In A Sorted List
BinaryTreeNode* flatten(BinaryTreeNode* root)
{
    // Write your code here
    vector<int> inorderVal;
    inorder(root,inorderVal);
    int n=inorderVal.size();

    BinaryTreeNode* newRoot=new BinaryTreeNode(inorderVal[0]);
    BinaryTreeNode* curr=newRoot;
    for(int i=1;i<n;i++){
        BinaryTreeNode *temp=new BinaryTreeNode(inorderVal[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;

    return newRoot;

}
void printFlattened(BinaryTreeNode* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

//Question7: Normal BST To Balanced BST
BinaryTreeNode* inorderToBST(int s, int e, vector<int>& inorderVal){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    BinaryTreeNode*root=new BinaryTreeNode(inorderVal[mid]);
    root->left=inorderToBST(s,mid-1, inorderVal);
    root->right=inorderToBST(mid+1,e,inorderVal);
    return root;
}
BinaryTreeNode* balancedBst(BinaryTreeNode* root) {
    // Write your code here.
    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1, inorderVal);

}
void printLevelOrder(BinaryTreeNode* root) {
    if (!root) return;
    queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            BinaryTreeNode* node = q.front(); q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

//Question8: Preorder of a BST( BST from Pre-Order)
BinaryTreeNode* solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    BinaryTreeNode* root=new BinaryTreeNode(preorder[i++]);
    root->left=solve(preorder,mini, root->data,i);
    root->right=solve(preorder,root->data, maxi,i);
    return root;
}
BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}
void printInorder(BinaryTreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}




int main(){


    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(10);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(6);
    root->left->right->left = new BinaryTreeNode(4);
    root->left->right->right = new BinaryTreeNode(7);
    root->right->right = new BinaryTreeNode(14);
    root->right->right->left = new BinaryTreeNode(13);


//Question1: Validate BST
    // if (validateBST(root)) {
    //     cout << "The tree is a valid BST." << endl;
    // } else {
    //     cout << "The tree is NOT a valid BST." << endl;
    // }

//Question2: Find K-th smallest element in BST
    //cout<<kthSmallest(root,4)<<endl;

//Question3: Predecessor ans Successor in BST
    //pair<int, int> ans = predecessorSuccessor(root, 4);
    //cout << "Predecessor: " << ans.first << ", Successor: " << ans.second << endl;

//Question4: LCA in BST
    // BinaryTreeNode* P = searchBST(root, 14);
    // BinaryTreeNode* Q = searchBST(root, 1);
    // BinaryTreeNode* lca = LCAinaBST(root, P, Q);
    // if (lca) {
    //     cout << "LCA of " << 14 << " and " << 1 << " is: " << lca->data << endl;
    // } else {
    //     cout << "LCA does not exist." << endl;
    // }

//Question5: Two Sum In BST 
    //cout<<twoSumInBST(root,24)<<endl;

//Question6: Flatten BST In A Sorted List
    // BinaryTreeNode* flatRoot = flatten(root);

    // cout << "Flattened tree: ";
    // printFlattened(flatRoot);

//Question7: Normal BST To Balanced BST
    // BinaryTreeNode* balancedRoot = balancedBst(root);

    // cout << "\nBalanced BST (Level Order):" << endl;
    // printLevelOrder(balancedRoot);

//Question8: Preorder of a BST( BST from Pre-Order)
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    cout << "Preorder input: ";
    for (int val : preorder) cout << val << " ";
    cout << "\n\n";

    BinaryTreeNode* root2 = preorderToBST(preorder);

    cout << "Inorder traversal (should be sorted): ";
    printInorder(root2);
    cout << "\n\n";
    


    


    return 0;
}
