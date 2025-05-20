#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }
};

void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node*head){
    int length=0;
    Node*temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertAtHead(Node*&head,Node*&tail,int d){
    //Create a new node

    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node*temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node*temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }

   
}

void insertAtPosition(Node*&head,Node*&tail,int position,int d){
    //Insert at first position
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //Insert at last position
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }
    Node*nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;

}

void deletion(int position,Node*&head,Node*&tail){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        //Deleting any middle or last node
        Node*curr=head;
        Node*prev=NULL;

        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;

        if(curr->next == NULL){
            tail = prev;
        }
        curr->next=NULL;
        delete curr;
        return;

    }
}
    

int main(){

    //Node* node1=new Node(10);
    Node* head=NULL;
    Node* tail=NULL;
    //print(head);
    //cout<<getLength(head)<<endl;

    insertAtHead(head,tail,20);
    //print(head);

    insertAtHead(head,tail,30);
    //print(head);

    insertAtHead(head,tail,40);
    //print(head);

    insertAtTail(head,tail,0);
    //print(head);

    insertAtTail(head,tail,-10);
    //print(head);

    insertAtPosition(head,tail,4,15);
    //print(head);

    insertAtPosition(head,tail,1,50);
    insertAtPosition(head,tail,8,-20);
    print(head);

    deletion(8,head,tail);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;

    return 0;
}