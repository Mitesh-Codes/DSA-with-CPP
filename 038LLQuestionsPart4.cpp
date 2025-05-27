#include<iostream>
#include<vector>
#include<algorithm>
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
};
print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Question8: Sort 0s, 1s, and 2s in an array
//Approach1: making count of 0s, 1s, and 2s and then filling the list
//Time Complexity: O(n), Space complexity: O(1)
Node* sortList(Node *head){
    int countzero=0;
    int countones=0;
    int counttwos=0;

    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            countzero++;
        }
        else if(temp->data==1){
            countones++;

        }
        else if(temp->data==2){
            counttwos++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(countzero!=0){
            temp->data=0;
            countzero--;
        }
        else if(countones!=0){
            temp->data=1;
            countones--;
        }
        else if(counttwos!=0){
            temp->data=2;
            counttwos--;
        }
        temp=temp->next;

    }
    return head;
}
//Approach2: Using three pointers to keep track of 0s, 1s, and 2s
//Time Complexity: O(n), Space complexity: O(1)
Node* sortList2(Node *head){
    int countzero=0;
    int countones=0;
    int counttwos=0;

    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            countzero++;
        }
        else if(temp->data==1){
            countones++;

        }
        else if(temp->data==2){
            counttwos++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(countzero!=0){
            temp->data=0;
            countzero--;
        }
        else if(countones!=0){
            temp->data=1;
            countones--;
        }
        else if(counttwos!=0){
            temp->data=2;
            counttwos--;
        }
        temp=temp->next;

    }
    return head;
}




//Question9: Merge Two Sorted Linked Lists
//Time complexity: O(n), Space complexity: O(1)
Node* solve(Node* first, Node* second){

    if(first->next==NULL){
        first->next=second;
        return first;
    }

    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=NULL;

    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;

        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;

}
Node* sortTwoLists(Node*&first, Node* &second)
{
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }

}

//Question 10: Palindrome LL
//Approach1: Using array to store the elements and then checking if the array is palindrome
//TC: O(n), SC: O(n)
bool checkPalindrome(vector<int>arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool isPalindrome(Node *head) {
    Node*temp=head;
    vector<int>arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkPalindrome(arr);
}

//Approach 2: get mid , reverse it and compare the the first half to other half
//TC: O(n), SC:O(1)
Node*getMid(Node* head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
Node*reverse(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool isPalindrome2(Node *head) {
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node*Middle=getMid(head);
    Node*temp=Middle->next;
    Middle->next=reverse(temp);
    Node*head1=head;
    Node*head2=Middle->next;
    
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    
    //reordering into original list
    temp=Middle->next;
    Middle->next=reverse(temp);
        
    return true;
}



int main(){

//Question8: Sort 0s, 1s, and 2s in an array
//Approach1: making count of 0s, 1s, and 2s and then filling the list
//Time Complexity: O(n), Space complexity: O(1)

    // Node* node1=new Node(2);
    // node1->next=new Node(0);
    // node1->next->next=new Node(1);
    // node1->next->next->next=new Node(2);
    // node1->next->next->next->next=new Node(0);

    //Node*head=node1;
    //head=sortList(head);
    //print(head);
//Approach2: using three pointers
//Time Complexity: O(n), Space complexity: O(1)
    // Node* node2=new Node(2);
    // node2->next=new Node(1);
    // node2->next->next=new Node(2);
    // node2->next->next->next=new Node(0);
    // node2->next->next->next->next=new Node(2);

    //Node*head2=node2;
    //head2=sortList2(head2);
    //print(head2);



//Question9: Merge Two Sorted Linked Lists
//Time complexity: O(n), Space complexity: O(1) 
    Node* node1=new Node(3);
    node1->next=new Node(3);
    node1->next->next=new Node(5);

    Node*first=node1;

    Node* node2=new Node(1);
    node2->next=new Node(4);
    node2->next->next=new Node(5);

    Node*second=node2;

    //Node*sortedTwo=sortTwoLists(first,second);
    //print(sortedTwo);



//Question 10: Palindrome LL
//Approach1: Using array to store the elements and then checking if the array is palindrome
//TC: O(n), SC: O(n)
    Node* node3=new Node(1);
    node3->next=new Node(2);
    node3->next->next=new Node(2);
    node3->next->next->next=new Node(1);
    Node*head3=node3;
    // if(isPalindrome(head3)){
    //     cout<<"The linked list is a palindrome."<<endl;
    // }
    // else{
    //     cout<<"The linked list is not a palindrome."<<endl;
    // }


//Approach2: get mid , reverse it and compare the the first half to other half
//TC: O(n), SC:O(1)
    if(isPalindrome2(head3)){
        cout<<"The linked list is a palindrome."<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome."<<endl;
    }


    
    
return 0;
}