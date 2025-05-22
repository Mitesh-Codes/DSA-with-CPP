#include<iostream>
using namespace std;

class Node
    {
        public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    



//question1:
//Aproach 1 : iterative approach
//Time complexity: O(n)
//Space complexity: O(1)
Node* reverseLinkedList(Node *head) 
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL){
        
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    return prev;
}
//Aproach2: Recursive approach
//Time complexity: O(n)
//Space complexity: O(n)

void reverse(Node* &head,Node*curr,Node*prev){
    //Base case
    if(curr==NULL){
        head=prev;
        return;
    }

    Node*forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
Node* reverseLinkedListApprorach2(Node*head){
    Node* curr=head;
    Node* prev=NULL;
    reverse(head,curr,prev);
    return head;
}

//Approach3: Recursive approach
//Time complexity: O(n)
//Space complexity: O(n)
Node* reverse2(Node* head){
    //Base case
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *chotahead=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotahead;
}
Node* reverseLinkedListApprorach3(Node* head){
    return reverse2(head);
}
    


void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


//Question2 : reverse a doubly linked list
class DNode{
    public:
    int data;
    DNode* prev;
    DNode* next;

    //Constructor
    DNode(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //Destructor
    ~DNode(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }
};

void printDoubly(DNode* head){
    DNode* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Reversing the doubly linked list
DNode* reverseDLinkedList(DNode *head) 
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    DNode* curr = head;
    DNode* temp = NULL;

    while(curr!=NULL){
        
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node in original list (which is prev in the reversed one)
        curr = curr->prev;
    }
    // If the list is not empty, then prev will be the new head
    if(temp != NULL) {
        head = temp->prev;
    }
    return head;
}



//Question 3 : middle of linked list
//Approach 1: using length
//Time complexity: O(n)
//Space complexity: O(1)
int getlength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
        
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len=getlength(head);
    int ans=len/2;
    Node* temp=head;
    int count=0;
    while(count<ans){
        temp=temp->next;
        count++;
    }
    return temp;
}
//Approach 2: using slow and fast pointer
Node* getmiddle(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }

    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        
    }
    return slow;
}

Node *findMiddle2(Node *head) {
    return getmiddle(head);
    
}







int main(){

    /*
    //Question1 : Reverse a linked list
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    print(head);
    //head=reverseLinkedList(head);
    print(head);

    //head=reverseLinkedListApprorach2(head);
    print(head);

    head=reverseLinkedListApprorach3(head);
    print(head);
    

    //Question2 : Reverse a doubly linked list
    DNode* head1=new DNode(1);
    head1->next=new DNode(2);
    head1->next->prev=head1;
    head1->next->next=new DNode(3);
    head1->next->next->prev=head1->next;
    head1->next->next->next=new DNode(4);
    head1->next->next->next->prev=head1->next->next;

    printDoubly(head1);
    head1=reverseDLinkedList(head1);
    printDoubly(head1);



    */

    //Question3 : Middle of Linked List
    //Approach 1: using length
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    //findMiddle(head);
    Node* middle=findMiddle(head);
    //print(middle);

    //Approach 2: using slow and fast pointer
    Node* head2=new Node(1);
    head2->next=new Node(2);
    head2->next->next=new Node(3);
    head2->next->next->next=new Node(4);
    head2->next->next->next->next=new Node(5);
    head2->next->next->next->next->next=new Node(6);

    Node* middle2=findMiddle2(head2);
    print(middle2);

    

    return 0;
}