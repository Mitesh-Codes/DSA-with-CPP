#include<iostream>
#include<queue>
#include<vector>
using namespace std;




//Question1: K smallest element
//TC : O(nlogk) SC: O(k)
int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int r=arr.size();
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }


//Question2: Is Binary Tree Heap?
//TC : O(n) SC: O(h)
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int countNodes(Node*tree ){
        if(tree==NULL){
            return 0;
        }
        int ans=1+countNodes(tree->left)+ countNodes(tree->right);
        return ans;
    }
    
bool isCBT(Node* tree,int index,int count){
        if(tree==NULL){
            return true;
        }
        if(index>=count){
            return false;
        }
        else{
            int left=isCBT(tree->left,2*index+1,count);
            int right=isCBT(tree->right,2*index+2,count);
            return (left && right);
        }
    }
bool isMaxOrder(Node *tree){
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        if(tree->right == NULL){
            return (tree->data > tree->left->data);
        }
        else{
            bool left=isMaxOrder(tree->left);
            bool right=isMaxOrder(tree->right);
            return (left && right && (tree->data >=tree->left->data && tree->data>= tree->right->data));
        }
    }
bool isHeap(Node* tree) {
        // code here
        int index=0;
        int totalCount=countNodes(tree);
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
}


//Question3: Merge Two Binary Max Heaps
void heapify(vector<int> &arr,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size=ans.size();
        for(int i=size/2-1;i>=0;i--){
            heapify(ans,size,i);
        }
        return ans;
        
}


//Question4: Minimum Cost of Ropes
int minCost(vector<int>& arr) {
        // code here
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        int cost=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int sum=a+b;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
}


//Question5: Convert BST to Min Heap
void inorder(Node* root, vector<int> &arr){
	if(root==NULL){
		return;
	}
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);

} 
void fillPreOrder(Node* root, vector<int> &arr,int &index){
	if(root==NULL){
		return;
	}
	root->data=arr[index++];
	fillPreOrder(root->left,arr,index);
	fillPreOrder(root->right,arr,index);
}
Node* convertBST(Node* root)
{
	// Write your code here.
	vector<int> arr;
	inorder(root,arr);
	int index=0;
	fillPreOrder(root,arr,index);
	return root;

}
void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}

//Question6: Kth Largest Sum Subarray
//TC : O(n^2 logk) SC: O(k)
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> mini;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}

//Question7: Merge K sorted Arrays




int main(){

//Question1: K smallest element
    vector<int> arr={7,10,4,3,20,15};
    int k=3;
    cout<<kthSmallest(arr,k)<<endl;

//Question2: Is Binary Tree Heap?
    Node* root=new Node(10);
    root->left=new Node(9);
    root->right=new Node(8);
    root->left->left=new Node(7);
    root->left->right=new Node(6);
    root->right->left=new Node(5);
    root->right->right=new Node(4);
    if(isHeap(root)){
        cout<<"The given binary tree is a Heap"<<endl;
    }
    else{
        cout<<"The given binary tree is not a Heap"<<endl;
    }

//Question3: Merge Two Binary Max Heaps
    vector<int> a={10,5,6,2};
    vector<int> b={12,7,9};
    vector<int> ans=mergeHeaps(a,b,a.size(),b.size());
    cout<<"The merged array is "<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

//Question4: Minimum Cost of Ropes
    vector<int> ropes={4,3,2,6};
    cout<<"The minimum cost to connect the ropes is "<<minCost(ropes)<<endl;

//Question5: Convert BST to Min Heap
    convertBST(root);
    cout<<"The preorder traversal of the converted Min Heap is "<<endl;
    preorderPrint(root);
    cout<<endl;


///Question6: Kth Largest Sum Subarray
    vector<int> arr2={10,-10,20,-40,30};
    int k2=3;
    cout<<getKthLargest(arr2,k2)<<endl; 

//Question7: Merge K sorted Arrays

    
    


    return 0;
}