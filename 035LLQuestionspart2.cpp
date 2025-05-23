#include<iostream>
using namespace std;


//Question 4 : Reverse List In K Groups
class Node {
    public:
        int data;
        Node *next;
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node *next) : data(x), next(next) {}
};
Node* kReverse(Node* head, int k) {
    //Base case
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // If less than k nodes, don't reverse
    if (count < k) return head;

    //Reverse first K node
    Node* next=NULL;
    Node* curr=head;
    Node* prev=NULL;
    count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;

    }
    //Recusrion
    if(next!=NULL){
        head->next=kReverse(next,k);
    }
    return prev;
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



//Question 5: check if Linked List is Circular or not
//Approach1: Traverse the list and check if we reach the head again    
    //Time complexity: O(n)
    //Space Complexity:O(1)
class Node2{
    public:
    int data;
    Node2* next;

    //Constuctor
    Node2(int data){
        this ->data=data;
        this->next=NULL;
    }

    //Destructor
    ~Node2(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }
};
void insertNode(Node2*&tail,int element,int d){

    //Empty list
    if(tail==NULL){
        Node2* newNode=new Node2(d);
        tail=newNode;
        newNode->next=newNode;
    }
    //All other cases
    else{
        Node2*curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }
        //we at curr node;
        Node2* temp=new Node2(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print2(Node2* tail){
    Node2*temp=tail;

    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(tail!=temp);
    cout<<endl;
}

bool isCircular(Node2*head){
    if(head==NULL){
        return true;
    }
    Node2* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;

    }
    return false;
}










int main(){

//Question 4 : Reverse List In K Groups
    //Approach: do first k by iteration and remaining by recusrsion
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    Node* head=new Node(5);
    head->next=new Node(4);
    head->next->next=new Node(3);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(9);
    head->next->next->next->next->next=new Node(2);

    //head=kReverse(head,4);
    //print(head);


    
//Question 5: Check if linked list is circular or not
    //Approach1: Traverse the list and check if we reach the head again
    //Time Complexity: O(n)
    //Space complexity: O(1)
    Node2* tail=NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,7,9);


    if(isCircular(tail)){
        cout<<"circular"<<endl;
    }
    else{
        cout<<"Not circular";
    }




    
    
    
    
    
    
    
    
    
    
    
    return 0;

}