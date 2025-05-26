#include<iostream>
#include<map>
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
void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Detect Loop in Linked List (using Map)
//Time Complexity: O(n) and Space Complexity: O(n)
bool detectLoop(Node*head){
    if(head==NULL) return false;
    map <Node*, bool> visited;

    Node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Loop detected at node with data: "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
    
    
}

//Detect Loop in Linked List (using Floyd's Cycle Detection Algorithm)
//Time Complexity: O(n) and Space Complexity: O(1)
Node* FloydDetectLoop(Node*head){
    if(head==NULL){
        return NULL;
    }

    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        if(fast==slow){
            //cout<<"node at which fast==slow "<<slow->data<<endl;
            return slow;
        }
    }
    
    return NULL;
    
}


Node* detectstart(Node* head){
    if(head==NULL){
        return NULL;

    }
    Node* intersection=FloydDetectLoop(head);
    if(intersection==NULL){
        return NULL;
    }
    Node*slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
   
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* startNode=detectstart(head);
    if(startNode==NULL){
        return;
    }
    Node*temp=startNode;

    while(temp->next!=startNode){
        temp=temp->next;
    }
    temp->next=NULL;
}


int main(){

    Node* node1=new Node(2);
    node1->next=new Node(3);
    node1->next->next=new Node(4);
    node1->next->next->next=new Node(7);
    node1->next->next->next->next=new Node(9);

    Node*head=node1;
    //print(head);

    //Creating a loop for testing
    node1->next->next->next->next->next=node1->next; // 9 -> 3 (loop)

    // if(detectLoop(head)){
    //     cout<<"Loop exists in the linked list."<<endl;
    // } else {
    //     cout<<"No loop detected in the linked list."<<endl;
    // }

    if(FloydDetectLoop(head)){
        cout<<"Loop exists in the linked list."<<endl;
    } else {
        cout<<"No loop detected in the linked list."<<endl;
    }
    Node*loop=detectstart(head);
    cout<<"The starting node of the loop is :"<<loop->data<<endl;
    removeLoop(head);
    //print(head);
    if(FloydDetectLoop(head)){
        cout<<"Loop exists in the linked list."<<endl;
    } else {
        cout<<"No loop detected in the linked list."<<endl;
    }




    return 0;
}