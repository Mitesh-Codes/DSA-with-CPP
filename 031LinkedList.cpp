#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //Constructor
    Node(int data){
        this-> data=data;
        this-> next=NULL;
    }

    //Destructor
    ~Node(){
        int value=this->data;
        //Memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }

};

void InsertAtHead(Node* &head,int d){
    //Create a new node
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;

}

void InsertAtTail(Node* &tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;

}

void InsertAtPosition(Node*&tail,Node* &head,int position,int d){
    //Insert at first position
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    
    Node *temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    
    //Insert at last position
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return;
    }

    Node* NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void deletion(int position,Node *&head, Node *&tail){
    //Deleting first node
    if(position==1){
        Node*temp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }

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
        prev->next=curr->next;
        curr->next=NULL;
        
        if(curr->next == NULL){
            tail = prev;
        }
        //Memory free
        delete curr;
        return;

    }
}

void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //Head pointed to node1
    Node* head=node1;
    Node* tail=node1;
   // print(head);
    //print(tail);

   // InsertAtHead(head,12);
    InsertAtTail(tail,12);
    //print(head);
    //print(tail);

    //InsertAtHead(head,15);
    InsertAtTail(tail,15);
    //print(head);
    //print(tail);

    InsertAtPosition(tail,head,4,22);
    //print(head);

    //cout<<"Head: "<<head->data<<endl;
    //cout<<"Tail: "<<tail->data<<endl;

    deletion(4,head,tail);
    print(head);
    cout<<"Tail: "<<tail->data<<endl;



    return 0;
}
