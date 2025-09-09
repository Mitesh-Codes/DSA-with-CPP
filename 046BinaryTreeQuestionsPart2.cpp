#include<iostream>
#include<climits>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//Question14: Sum of Longest Bloodline of a Tree
void solve(Node*root, int sum, int &maxSum,int len,int &maxLen){
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            } 
            else if(len==maxLen){
                maxSum=max(sum,maxSum);
            }
            return;
        }
        sum=sum+root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
    }
int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len=0;
        int maxLen=0;
        int sum=0;
        int maxSum=INT_MIN;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
        
}

//Qquestion15: Lowest Common Ancestor in a Binary Tree
Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root==NULL){
            return NULL;
        }
        if(root->data==n1|| root->data==n2){
            return root;
        }
        
        Node*leftAns=lca(root->left,n1,n2);
        Node*rightAns=lca(root->right,n1,n2);
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
        
}

//Question16: K Sum Paths
void solve(Node* root,int k, int &count,vector<int>&path){
      if(root==NULL){
          return;
      }
      path.push_back(root->data);
      
      int sum = 0;
      for(int i = path.size()-1; i >= 0; i--) {
          sum += path[i];
          if(sum == k) count++;
      }
      solve(root->left,k,count,path);
      solve(root->right,k,count,path);
      
      path.pop_back();
    }
    int sumK(Node *root, int k) {
        // code here
        vector<int> path;
        int count=0;
        solve(root,k,count,path);
        return count;
        
    }

//Question17: kth Ancestor of a Node in a Binary Tree
Node* solve(Node*root,int &k,int node){
      if(root==NULL){
          return NULL;
      }
      if(root->data==node){
          return root;
      }
      Node*leftAns=solve(root->left,k,node);
      Node*rightAns=solve(root->right,k,node);
      
      if(leftAns!=NULL && rightAns==NULL){
          k--;
          if(k<=0){
              k=INT_MAX; //locked the answer
              return root;
          }
          return leftAns;
      }
      if(leftAns==NULL && rightAns!=NULL){
          k--;
          if(k<=0){
              k=INT_MAX; //locked the answer
              return root;
          }
          return rightAns;
      }
      return NULL;
}
int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node*ans=solve(root,k,node);
        if(ans==NULL|| ans->data==node){
            return -1;
        }
        return ans->data;
}

//Question18: Maximum sum of Non-adjacent nodes
pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int> res;
        res.first=root->data+left.second+right.second;
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
}
int getMaxSum(Node *root) {
        // code here
        pair<int,int>ans=solve(root);
        return max(ans.first,ans.second);
}



//


//Question19: Construct a Tree from Inorder and Preorder
void createMapping(vector<int> &inorder,map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
        
    }
Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,int inOrderStart,int inOrderEnd,int n,map<int,int> &nodeToIndex){
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        int element=preorder[index++];
        Node* root=new Node(element);
        int position=nodeToIndex[element];
        root->left=solve(inorder,preorder,index,inOrderStart,position-1,n,nodeToIndex);
        root->right=solve(inorder,preorder,index,position+1,inOrderEnd,n,nodeToIndex);
        return root;
        
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n=preorder.size();
        int preOrderIndex=0;
        map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        Node*ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
}

void printPostorder(Node* root) {
    if(root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}


//Question20: Create a Binary Tree from Inorder and Postorder
void createMapping2(vector<int> &inorder,map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
        
    }
Node* solve2(vector<int> &inorder, vector<int> &postorder,int &index,int inOrderStart,int inOrderEnd,int n,map<int,int> &nodeToIndex){
        if(index<0 || inOrderStart>inOrderEnd){
            return NULL;
        }
        int element=postorder[index--];
        Node* root=new Node(element);
        int position=nodeToIndex[element];
        
        root->right=solve2(inorder,postorder,index,position+1,inOrderEnd,n,nodeToIndex);
        root->left=solve2(inorder,postorder,index,inOrderStart,position-1,n,nodeToIndex);
        return root;
        
}
Node *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n=postorder.size();
        int postOrderIndex=n-1;
        map<int,int>nodeToIndex;
        createMapping2(inorder,nodeToIndex,n);
        Node*ans=solve2(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
}
void printLevelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}


//Question21: Brurning Tree
Node* createParentMapping(Node* root,int target,map<Node*,Node*>&nodeToParent){
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            Node*front=q.front();
            q.pop();
            if(front->data==target){
                res=front;
            }
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
}
int burnTree(Node* root,int target,map<Node*,Node*>&nodeToParent){
        map<Node*,bool> visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        int ans=0;
        
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*front=q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
}
int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>nodeToParent;
        Node* targetNode=createParentMapping(root,target,nodeToParent);
        int ans=burnTree(targetNode,target,nodeToParent);
        return ans;
}


//Morris Traversal (TC: O(n), SC: O(1))
void morrisTraversal(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right; // move to next
        } 
        else {
            // find inorder predecessor
            Node* pre = curr->left;
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            // make thread
            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }
            // thread already exists
            else {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}


//Question22: Flatten Binary Tree To Linked List
void flatten(Node *root) {
        // code here
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
        
}




int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->right = new Node(6);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(8);

//Question14: Sum of Longest Bloodline of a Tree
    
    //cout << sumOfLongRootToLeafPath(root) << endl;

//Question15: Lowest Common Ancestor in a Binary Tree
    //cout << lca(root, 7, 8)->data << endl;

//Question16: K Sum Paths
    //cout << sumK(root, 11) << endl;

//Question17: kth Ancestor of a Node in a Binary Tree
    //cout << kthAncestor(root, 2, 3) << endl;

//Question18: Maximum sum of Non-adjacent nodes
    //cout << getMaxSum(root) << endl;


//

//Question19: Construct a Tree from Inorder and Preorder
    // vector<int> inorder  =  {1, 6, 8, 7};
    // vector<int> preorder = {1, 6, 7, 8};

    // // Build the tree
    // Node* root = buildTree(inorder, preorder);

    // cout << "Postorder of constructed tree: ";
    // printPostorder(root);
    // cout << endl;


//Question20: Create a Binary Tree from Inorder and Postorder
    // vector<int> inorder  = {4, 2, 5, 1, 3};
    // vector<int> postorder = {4, 5, 2, 3, 1};

    // Node* root = buildTree2(inorder, postorder);

    // cout << "Level Order Traversal of constructed tree: ";
    // printLevelOrder(root);
    // cout << endl;


//Question 21: Burning Tree
    //cout<<minTime(root,7)<<endl;




//Morris Traversal
    //cout << "Morris Inorder Traversal: ";
    //morrisTraversal(root);


//Question22: Flatten Binary Tree To Linked List
    flatten(root);   
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right; 
    }
    cout << endl;


    
    
    







    

    return 0;
}
