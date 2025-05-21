#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constuctor
    Node(int data){
        this ->data=data;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }
};

void insertNode(Node*&tail,int element,int d){

    //Empty list
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    //All other cases
    else{
        Node*curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }
        //we at curr node;
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node* tail){
    Node*temp=tail;

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

void deleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"List is empty. rn"<<endl;
        return;
    }
    else{
        //NON Empty
        Node*prev=tail;
        Node*curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        //We are at the node to be deleted
        prev->next=curr->next;
        //For single element
        if(curr==prev){
            tail=NULL;
        }
        //For 2 elements
        else if(tail==curr){
            tail=prev;
        }


        //For first element
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;


    }
}

int main(){

    Node* tail=NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);
   /* insertNode(tail,5,7);
    //print(tail);
    insertNode(tail,7,9);
    //print(tail);

    insertNode(tail,7,8);
    print(tail);


    deleteNode(tail,5);
    print(tail);

    //deleteNode(tail,3);
    //print(tail);

    deleteNode(tail,9);
    print(tail);

    */
    deleteNode(tail,3);
    print(tail);

    return 0;
}