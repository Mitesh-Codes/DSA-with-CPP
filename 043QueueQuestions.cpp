#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;


//Question1: Queue reversal using stack
queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int>s;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
        }
        return q;
        
}

//Question2: First negative integer in every window of size k
 vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int N=arr.size();
        deque <long long int> dq;
        vector<int > ans;
        
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k;i<N;i++){
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            if(arr[i]<0){
            dq.push_back(i);
            }
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
        
}


//Question3: Reverse first k element of queue
queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if (q.empty() || k > (int)q.size() || k <= 0) {
        return q;
        }
        stack<int>s;
        for(int i=0;i<k;i++){
            int element=q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
        }
        int n=q.size()-k;
        while(n--){
            int element=q.front();
            q.pop();
            q.push(element);
        }
        return q;
}

//Question4: First non repeating character in a stream
string FirstNonRepeating(string &s) {
        // Code here
        unordered_map<char,int>count;
        queue<int> q;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            count[ch]++;
            q.push(ch);
            while(!q.empty()){
                if(count[q.front()]>1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
            
        }
        return ans;
        
}

//Question5: Circular tour (important)
struct pertrolPump{
    int petrol;
    int distance;
};

int tour(pertrolPump p[],int n){
    int deficit=0;
    int balance=0;
    int start=0;

    for(int i=0;i<n;i++){
        balance+=p[i].petrol-p[i].distance;
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficit+balance>=0){
        return start;
    }
    else{
        return -1;
    }
}


//Question6: Interleaving the first half of the queue with second half
queue<int> rearrangeQueue(queue<int> q) {
        // code here
        queue<int> newQ;
        int size=q.size();
        int n=size/2;
        for(int i=0;i<n;i++){
            int value =q.front();
            q.pop();
            newQ.push(value);
            
        }
        while(!newQ.empty()){
            int value=newQ.front();
            newQ.pop();
            q.push(value);
            value=q.front();
            q.pop();
            q.push(value);
        }
        return q;
}


//Question7: 'K' queue in an array
class KQueue {
    int *arr;
    int n;
    int k;
    int *front;
    int *rear;
    int *next;
    int freeSpot;
  public:
    KQueue(int n,int k){
        this->n=n;
        this->k=k;
        arr= new int[n];
        front=new int[k];
        rear=new int[k];
        next=new int[n];
        freeSpot=0;
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        
    }
    void enqueue(int data,int qn){
        if(freeSpot==-1){
            cout<<"No empty space is present"<<endl;
            return;
        }
        int index=freeSpot;
        freeSpot=next[index];
        if(front[qn-1]==-1){
            front[qn-1]=index;
        }
        else{
            next[rear[qn-1]]=index;
        }
        next[index]=-1;
        rear[qn-1]=index;
        arr[index]=data;
    }

    int dequeue(int qn){
        if(front[qn-1]==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }

};

//Question8: Sum of minimum and maximum elements of all subarrays of size k
int solve(int arr[],int n,int k){
    deque<int> maxi(k);
    deque<int> mini(k);
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

    }
    int ans=0;
    for(int i=k;i<n;i++){
        ans+=arr[maxi.front()]+arr[mini.front()];

        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans+=arr[maxi.front()]+arr[mini.front()];
    return ans;
    
}



int main(){

//Question1: Queue reversal using stack
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q=reverseQueue(q);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

//Question2: First negative integer in every window of size k
    // vector<int> arr={12,-1,-7,8,-15,30,16,28};
    // int k=3;
    // vector<int> ans=firstNegInt(arr,k);
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }


//Question3: Reverse first k element of queue
    // queue<int>q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // int k=3;
    // q=reverseFirstK(q,k);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

//Question4: First non repeating character in a stream
    // string s="aabc";
    // string ans=FirstNonRepeating(s);
    // cout<<ans<<endl;

//Question5: Circular tour (important)
    // pertrolPump p[]={ {4,6}, {6,5}, {7,3}, {4,5} };
    // int n=sizeof(p)/sizeof(p[0]);
    // int start=tour(p,n);
    // cout<<start<<endl;


//Question6: Interleaving the first half of the queue with second half
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.push(6);

    // q=rearrangeQueue(q);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

//Question7: 'K' queue in an array
    // KQueue k(10,3);
    // k.enqueue(10,1);
    // k.enqueue(15,1);
    // k.enqueue(20,2);
    // k.enqueue(25,1);
    // cout<<k.dequeue(1)<<endl;
    // cout<<k.dequeue(2)<<endl;
    // cout<<k.dequeue(1)<<endl;
    // cout<<k.dequeue(1)<<endl;
    // cout<<k.dequeue(1)<<endl;

//Question8: Sum of minimum and maximum elements of all subarrays of size k
    int arr[]={2,5,-1,7,-3,-1,-2};
    cout<<solve(arr,7,4)<<endl;


    return 0;
}