#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
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
void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Question7: remove duplicates Linked List
//1:from sorted list
Node * uniqueSortedList(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            Node*next_next=curr->next->next;
            Node*nodeToDelete=curr->next;
            curr->next=next_next;
            delete nodeToDelete;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

//2:from unsorted list

//Approach 1: using two loop and checking for duplicates
//Time Complexity: O(n^2) and Space Complexity: O(1)
Node*uniqueUnsortedList(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*curr=head;
    while (curr != NULL) {
        Node* prev = curr;
        Node* temp = curr->next;

        while (temp != NULL) {
            if (temp->data == curr->data) {
                // Duplicate found
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

//Approach 2: first sort the list and then remove duplicates
//Time Complexity: O(nlogn) and Space Complexity: O(1)

//code not mine
Node* uniqueUnsortedList2(Node* head) {
    if (!head) return nullptr;

    // Step 1: Extract data
    vector<int> values;
    Node* temp = head;
    while (temp) {
        values.push_back(temp->data);
        temp = temp->next;
    }

    // Step 2: Sort and remove duplicates
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    // Step 3: Build new list
    Node* newHead = new Node(values[0]);
    Node* current = newHead;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return newHead;
}

//Approach 3: using hash map
//Time Complexity: O(n) and Space Complexity: O(n)
Node*uniqueUnsortedList3(Node*head){
    if(head==NULL){
        return NULL;
    }
    map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (visited[curr->data] == true) {
            // Duplicate found – remove current node
            prev->next = curr->next;
            Node* nodeToDelete = curr;
            curr = curr->next;
            delete nodeToDelete;
        } else {
            // Not visited before
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;

    
}

//Approach 4: using set
//Time Complexity: O(nlogn) and Space Complexity: O(n)
Node* uniqueUnsortedListbest(Node* head) {
    if (head == NULL) return NULL;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (seen.count(curr->data)) {
            // Duplicate found – remove node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}






int main(){

//Question7: remove duplicates from sorted list
    Node* head=new Node(1);
    head->next=new Node(3);
    head->next->next=new Node(2);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(3);
    head->next->next->next->next->next=new Node(4);
    print(head);
    //head=uniqueSortedList(head);

    head=uniqueUnsortedListbest(head);
    print(head);


    return 0;
}