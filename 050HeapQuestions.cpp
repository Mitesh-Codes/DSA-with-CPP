#include<iostream>
#include<queue>
#include<vector>
#include<climits>


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
class node2{
    public:
        int data;
        int i;
        int j;

        node2(int data, int row,int col){
            this->data=data;
            i=row;
            j=col;
        }
};

class compare{
    public:
        bool operator()(node2* a,node2* b){
            return (a->data > b->data);
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<node2* , vector<node2*>, compare> minHeap;

    for(int i=0;i<k;i++){
        node2* tmp=new node2(kArrays[i][0],i,0);
        minHeap.push(tmp);
    }

    vector<int>ans;

    while(minHeap.size()>0){
        node2* tmp=minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i=tmp->i;
        int j=tmp->j;

        if(j+1< kArrays[i].size()){
            node2* next=new node2(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;


}

//Question8: Merge K Sorted Linked Lists
class Node3
{
public:
    int data;
    Node3 *next;
    Node3()
    {
        this->data = 0;
        next = NULL;
    }
    Node3(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node3(int data, Node3* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare2{
    public:
        bool operator()(Node3* a,Node3* b){
            return (a->data > b->data);
        }
};
Node3* mergeKLists(vector<Node3*> &listArray){
    // Write your code here.
    priority_queue<Node3* , vector<Node3*>, compare2> minHeap;
    int k=listArray.size();
    if(k==0){
        return NULL;
    }

    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }    
    }
    Node3*head=NULL;
    Node3*tail=NULL;
    while(minHeap.size()>0){
        Node3*top=minHeap.top();
        minHeap.pop();

        if(top->next!=NULL){
            minHeap.push(top->next);
        }

        if(head==NULL){
            head=top;
            tail=top;
            
        }
        else{
            tail->next=top;
            tail=top;
            
        }
    }
    return head;
}

//Question9: smallest range in K lists
class node4{
    public:
        int data;
        int row;
        int col;
        node4(int d,int r,int c){
            this->data=d;
            row=r;
            col=c;
        }
};
class compare4{
    public:
        bool operator()(node4* a , node4* b){
            return (a->data > b->data);
        }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini=INT_MAX, maxi=INT_MIN;
    priority_queue<node4*,vector<node4*>,compare4> minHeap;

    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minHeap.push(new node4(element,i,0));
    }

    int start=mini, end=maxi;
    while(!minHeap.empty()){
        node4*temp=minHeap.top();
        minHeap.pop();
        mini=temp->data;
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new node4(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }

    }
    return (end-start+1);


}

//Question10: Median in a Stream
int signum(int a, int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
	else{
		return -1;
	}
}
void callMedian(int element,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &median){
	switch (signum(maxi.size(),mini.size())){
		case 0: if(element>median){
					mini.push(element);
					median=mini.top();
				}
				else{
					maxi.push(element);
					median=maxi.top();
				}
				break;
		case 1: if(element>median){
					mini.push(element);
					median=(mini.top()+maxi.top())/2;
				}
				else{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(element);
					median=(mini.top()+maxi.top())/2;
				}
				break;
		case -1: if(element>median){
					maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median=(mini.top()+maxi.top())/2;
				}
				else{
					maxi.push(element);
					median=(mini.top()+maxi.top())/2;
				}
				break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> ans;
	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int median=0;

	for(int i=0;i<n;i++){
		callMedian(arr[i],maxHeap,minHeap,median);
		ans.push_back(median);
	}
	return ans;
}



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
    vector<vector<int>> kArrays = { { 2, 6, 12 },
                                   { 1, 9 },
                                   { 23, 34, 90, 2000 } };
    int k3 = kArrays.size();
    vector<int> mergedArray = mergeKSortedArrays(kArrays, k3);  
    cout << "Merged array is " << endl;
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

//Question8: Merge K Sorted Linked Lists
    vector<Node3*> listArray;
    Node3* list1 = new Node3(1);
    list1->next = new Node3(4);
    list1->next->next = new Node3(5);
    listArray.push_back(list1);
    Node3* list2 = new Node3(1);
    list2->next = new Node3(3);
    list2->next->next = new Node3(4);
    listArray.push_back(list2);
    Node3* list3 = new Node3(2);
    list3->next = new Node3(6);
    listArray.push_back(list3);
    Node3* mergedList = mergeKLists(listArray);
    cout << "Merged Linked List is: ";
    while (mergedList != nullptr) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

//Question9: smallest range in K lists
    vector<vector<int>> a2 = { { 1, 5, 8 },
                             { 4, 12 },
                             { 7, 8, 10 } };
    int k4 = a2.size();
    int n2 = a2[0].size();
    cout << "The smallest range is: " << kSorted(a2, k4, n2) << endl;


//Question10: Median in a Stream
    vector<int> arr3 = {5, 15, 1, 3};
    int n3 = arr3.size();
    vector<int> medians = findMedian(arr3, n3);
    cout << "Medians after each insertion: ";
    for (int i = 0; i < medians.size(); i++) {
        cout << medians[i] << " ";
    }
    cout << endl;
    


    
    


    return 0;
}
