#include<iostream>
#include<unordered_map>
using namespace std;
/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Question11: Add Two Numbers Represented by Linked Lists
//Approach: Reverse both lists, add them, and then reverse the result
//Time Complexity: O(n), Space complexity: O(max(n, m))
class ADD_twoLists {
  private:
    Node* reverse(Node* head){
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            Node*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(Node*&head,Node*&tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return ;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node*add(Node* num1,Node* num2){
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        int carry=0;
        while(num1!=NULL || num2!=NULL || carry!=0){
            int val1=0;
            if(num1!=NULL){
                val1=num1->data;
            }
            int val2=0;
            if(num2!=NULL){
                val2=num2->data;
            }
            int sum=carry+val1+val2;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            if(num1!=NULL)
                num1=num1->next;
            if(num2!=NULL)    
                num2=num2->next;
        }
        return ansHead;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1=reverse(num1);
        num2=reverse(num2);
        Node* ans=add(num1,num2);
        ans=reverse(ans);
        while (ans != NULL && ans->data == 0) {
            Node* temp = ans;
            ans = ans->next;
            delete temp;
        }
        if (ans == NULL) {
            return new Node(0);
        }

        return ans;
    }
};

*/

//Question12: Clone a linked list with next and random pointer
//Approach: Using Mapping
//Time complexity:O(n)  , Space complexity:O(n)

class Node{
    public:
    int data;
    Node* next;
    Node*random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};

void insertAtTail(Node*&head,Node*&tail,int d){
    Node*newNode=new Node(d);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
/*
Node* copyRandomList(Node* head){
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    unordered_map<Node*,Node*> oldToNewNode;
    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    while(originalNode!=NULL){
        oldToNewNode[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    originalNode=head;
    cloneNode=cloneHead;

    while(originalNode!=NULL){
        cloneNode->random=oldToNewNode[originalNode->random];
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    return cloneHead;
}
*/

//Approach2: intermixing the original and clone list
//Time complexity:O(n), Space complexity: O(1)

Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node*cloneHead=NULL;
        Node*cloneTail=NULL;
        Node*temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
            
        }
        
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random ? temp->random->next : temp->random;
            }
            temp=temp->next->next;
        }
        
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        
        return cloneHead;
        
        
        
    }
        
    



void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){

//Question11: Add Two Numbers Represented by Linked Lists
//Time complexity: O(n), Space complexity: O(max(n,m))

    // Node* node1=new Node(3);
    // node1->next=new Node(4);
    
    // Node* node2=new Node(2);
    // node2->next=new Node(3);
    // node2->next->next=new Node(0);

    // Node* head=node1;
    // Node* head2=node2;

    //ADD_twoLists obj;
    //Node* result = obj.addTwoLists(head, head2);
    //print(result);





//Question12: Clone a linked list with next and random pointer
//Approach1: using mapping
//Time complexity:O(n), Space complexity:O(n)
    Node* node1=new Node(1);
    node1->next=new Node(2);
    node1->next->next=new Node(3);
    node1->next->next->next=new Node(4);

    Node* head=node1;
    //Node*clonedList=NULL;
    //clonedList=copyRandomList(head);
    //print(clonedList);
    

///Approach2: 
//Time complexity:O(n), Space complexity: O(1)
    Node*clonedList2=NULL;
    clonedList2=cloneLinkedList(head);
    print(clonedList2);


    return 0;
}
