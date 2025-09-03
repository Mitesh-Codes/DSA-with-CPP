#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

//Question2: Height of Binary Tree
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node==NULL){
            return -1;
        }
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
};
*/

//Question3: Diameter of Binary Tree
// O(n^2) solution
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
int height(Node* node) {
        // code here
        if(node==NULL){
            return -1;
        }
        int left=height(node->left);
        int right=height(node->right);
        
        return max(left,right)+1;
}
int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        int opt1=diameter(root->left);
        int opt2=diameter(root->right);
        int opt3=height(root->left)+height(root->right)+2;
        
        return max(opt1, max(opt2, opt3));
}


//Q3 : O(n) solution
pair<int,int> diameterFast(Node *root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterFast(root->left);
    pair<int, int>right=diameterFast(root->right);
    int opt1=left.first;
    int opt2=right.first;
    int opt3=left.second + right.second;
        
    pair<int,int> ans;
    ans.first=max(opt1,max(opt2,opt3));
    ans.second=max(left.second,right.second)+1;
    return ans;
            
}
int diameter2(Node* root) {
    return diameterFast(root).first;
        
}
*/

//Question4: Check if Binary Tree is Height Balanced or Not
// O(n^2) solution
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
    private:
        int height(Node* node) {
        // code here
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        
        return max(left,right)+1;
        }
  public:
    bool isBalanced(Node* root) {
        // Code here
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff= abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};
// Q4: O(n) solution
pair<bool,int> isBalancedFast(Node*root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
        pair<int,int> left=isBalancedFast(root->left);
        pair<int,int> right=isBalancedFast(root->right);
        
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff= abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
bool isBalanced(Node* root) {
        // Code here
    return isBalancedFast(root).first;
        
}
*/

//Question5: Determine if two trees are identical or not
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
bool isIdentical(Node* root1, Node* root2) {
        // code here
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL && root2!=NULL){
            return false;
        }
        if(root1!=NULL && root2==NULL){
            return false;
        }
        
        bool left=isIdentical(root1->left, root2->left);
        bool right=isIdentical(root1->right,root2->right);
        
        bool value=root1->data == root2->data;
        if(left && right && value){
            return true;
        }
        else{
            return false;
        
        }
}
*/

//Question6: Sum Tree
/*
struct Node
{
    int data;
    Node* left, * right;
};
pair<bool, int> sumTree(Node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<int,int> left=sumTree(root->left);
        pair<int,int>  right=sumTree(root->right);
        
        bool leftans=left.first;
        bool rightans=right.first;
        bool sum= (root->data==left.second+right.second);
        pair<bool,int> ans;
        if(leftans&&rightans && sum){
            ans.first=true;
            ans.second=root->data+left.second+right.second;
            //ans.second=2*root->data;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
bool isSumTree(Node* root) {
    return sumTree(root).first;
}
*/

//Question7: ZigZag Tree Traversal
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight=true;
        
        while(!q.empty()){
            int  size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++){
               Node* frontNode=q.front();
               q.pop();
               int index=leftToRight?i:size-i-1;
               ans[index]=frontNode->data;
               
               if(frontNode->left){
                   q.push(frontNode->left);
               }
               if(frontNode->right){
                   q.push(frontNode->right);
               }
            }
            
            leftToRight=!leftToRight;
            
            for(auto i:ans){
                result.push_back(i);
            }
        }
        return result;
}
*/


//Question8: Boundary Traversal of Binary Tree
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void traversalLeft(Node *root, vector<int>&ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traversalLeft(root->left,ans);
        }
        else{
            traversalLeft(root->right,ans);
        }
        
}
void traversalLeaf(Node*root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if((root->left==NULL) && (root->right==NULL)){
            ans.push_back(root->data);
            return;
        }
        
        traversalLeaf(root->left,ans);
        traversalLeaf(root->right,ans);
}
void traversalRight(Node*root, vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            traversalRight(root->right,ans);
        }
        else{
            traversalRight(root->left,ans);
        }
        
        ans.push_back(root->data);
}
    
vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        traversalLeft(root->left, ans);
        
        traversalLeaf(root->left,ans);
        traversalLeaf(root->right,ans);
        
        traversalRight(root->right,ans);
        return ans;
}
*/

//Question9: Vertical Order Traversal of Binary Tree
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // map<hd, vector of nodes>
        map<int, vector<int>> nodes;
        
        // queue: node + horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            nodes[hd].push_back(frontNode->data);
            
            if(frontNode->left)
                q.push({frontNode->left, hd-1});
            if(frontNode->right)
                q.push({frontNode->right, hd+1});
        }
        
        // Collect results column by column
        for(auto &col : nodes) {
            ans.push_back(col.second);
        }
        return ans;
}
*/

//Question10: Top View of Binary Tree
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topNode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node*frontNode=temp.first;
            int hd=temp.second;
            
            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
            
        }
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        return ans;
}



int main(){

//Question2: Height of Binary Tree  
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // Solution obj;
    // cout << "Height of the binary tree: " << obj.height(root) << endl;


//Question3: Diameter of Binary Tree
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // cout << "Diameter of the binary tree: " << diameter(root) << endl;


//Q3 : O(n) solution
    // Node* root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // cout << "Diameter of the binary tree: " << diameter2(root) << endl;

//Question4: Check if Binary Tree is Height Balanced or Not
// O(n^2) solution
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->left->left = new Node(8);
    // Solution obj;
    // if (obj.isBalanced(root))
    //     cout << "The binary tree is height-balanced." << endl;
    // else
    //     cout << "The binary tree is not height-balanced." << endl;  

// Q4: O(n) solution
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->left->left = new Node(8);


    // if (isBalanced(root))
    //     cout << "The binary tree is height-balanced." << endl;
    // else
    //     cout << "The binary tree is not height-balanced." << endl;

//Question5: Determine if two trees are identical or not
    // Node* root1 = new Node(1);
    // root1->left = new Node(2);
    // root1->right = new Node(3);
    // root1->left->left = new Node(4);
    // root1->left->right = new Node(5);
    // root1->right->left = new Node(6);
    // root1->right->right = new Node(7);
    // Node* root2 = new Node(1);
    // root2->left = new Node(2);
    // root2->right = new Node(3);
    // root2->left->left = new Node(5);
    // root2->left->right = new Node(5);
    // root2->right->left = new Node(6);
    // root2->right->right = new Node(7);
    // if (isIdentical(root1, root2))
    //     cout << "The two binary trees are identical." << endl;
    // else
    //     cout << "The two binary trees are not identical." << endl;


//Question6: Sum Tree
    // Node* root = new Node{26};
    // root->left = new Node{10};
    // root->right = new Node{3};
    // root->left->left = new Node{4};
    // root->left->right = new Node{6};
    // root->right->right = new Node{3};
    // if (isSumTree(root))
    //     cout << "The binary tree is a sum tree." << endl;
    // else
    //     cout << "The binary tree is not a sum tree." << endl;



//Question7: ZigZag Tree Traversal
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // vector<int> result = zigZagTraversal(root);
    // cout << "ZigZag Traversal of the binary tree: ";
    // for (int val : result) {
    //     cout << val << " ";
    // }
    // cout << endl;

//Question8: Boundary Traversal of Binary Tree
    // Node* root = new Node(20);
    // root->left = new Node(8);
    // root->right = new Node(22);
    // root->left->left = new Node(4);
    // root->left->right = new Node(12);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(14);
    // root->right->right = new Node(25);
    // vector<int> result = boundaryTraversal(root);
    // cout << "Boundary Traversal of the binary tree: ";
    // for (int val : result) {
    //     cout << val << " ";
    // }
    // cout << endl;

//Question9: Vertical Order Traversal of Binary Tree
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // vector<vector<int>> result = verticalOrder(root);
    // cout << "Vertical Order Traversal of the binary tree: " << endl;
    // for (const auto& vec : result) {
    //     for (int val : vec) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }


//Question10: Top View of Binary Tree 
    Node* root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->right = new Node{4};
    root->left->right->right = new Node{5};
    root->left->right->right->right = new Node{6};
    vector<int> result = topView(root);
    cout << "Top View of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;







    



    return 0;
}
