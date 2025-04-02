#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>

#include<algorithm>
using namespace std;




int main(){

//STL CONTAINERS

 //ARRAY STL
    // array<int,4> a={3,7,8,2};
    // int size=a.size();
    // for(int i=0;i<size;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // cout<<a.at(2)<<endl;
    // cout<<a.empty()<<endl;
    // cout<<a.front()<<endl;
    // cout<<a.back()<<endl;
    
//VECTOR STL
    // vector<int> v;
    // cout<<v.capacity()<<endl;

    // vector<int> a(5,2);
    // for(int i:a){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // vector<int> b(a);
    // for(int i:b){
    //     cout<<i<<" ";
    // }
    // cout<<endl;


    // v.push_back(1);
    // cout<<v.capacity()<<endl;

    // v.push_back(2);
    // cout<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<v.capacity()<<endl;

    // cout<<"size of array "<<v.size()<<endl;

    // cout<<v.at(2)<<endl;

    // cout<<v.front()<<endl;
    // cout<<v.back()<<endl;

    // v.pop_back();
    // for(int i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // v.clear();
    // cout<<v.size()<<endl;
    // cout<<v.capacity()<<endl;



//DEQUE STL
    // deque<int> d;
    // d.push_front(1);
    // d.push_back(2);

    // //d.pop_back;

    // cout<<d.front()<<endl;
    // cout<<d.back()<<endl;

    // cout<<"Empty or not "<<d.empty()<<endl;
    
    // cout<<"before erase "<<d.size()<<endl;
    // d.erase(d.begin(),d.begin()+1);
    // cout<<"after erase "<<d.size()<<endl;




//LIST STL
    // list<int>l;
    // l.push_front(1);
    // l.push_back(2);
    // for(int i:l){
    //     cout<<i<<" ";

    // }
    // cout<<endl;
    // l.erase(l.begin());
    // cout<<l.size();



//STACK STL
    // stack<string> s;
    // s.push("Mitesh");
    // s.push("Kumar");
    // s.push("cpp");
    // cout<<s.top()<<endl;
    // cout<<s.size()<<endl;
    // s.pop();
    // cout<<s.size()<<endl;
    // cout<<s.empty()<<endl;


//Queue
    // queue<string> q;
    // q.push("Mitesh");
    // q.push("Kumar");
    // q.push("cpp");

    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;


//PRIORITY QUEUE STL
    // //max heap;
    // priority_queue<int> maxi;
    // //min heap;
    // priority_queue<int,vector<int>,greater<int>> mini;

    // maxi.push(2);
    // maxi.push(1);
    // maxi.push(4);
    // maxi.push(3);
    // int n=maxi.size();
    // for(int i=0;i<n;i++){
    //     cout<<maxi.top()<<" ";
    //     maxi.pop();
    // }
    // cout<<endl;

    // mini.push(2);
    // mini.push(1);
    // mini.push(3);
    // mini.push(4);
    // int m=mini.size();
    // for(int i=0;i<m;i++){
    //     cout<<mini.top()<<" ";
    //     mini.pop();
    // }
    // cout<<endl;



//SET STL
    // set<int> s;
    // s.insert(3);
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(2);
    // s.insert(2);
    // s.insert(-1);

    // for(int i:s){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // s.erase(s.begin());
    
    // for(int i:s){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // cout<<s.count(-1)<<endl<<endl;

    // set<int>::iterator itr = s.find(2);
    // cout<<*itr<<endl;

    // set<int>::iterator its = s.find(-1);
    // cout<<*its<<endl;



//MAP STL
    // map<int,string> m;
    // m[1]="Mitesh";
    // m[3]="Mitesh";
    // m[2]="Kumar";
    // m.insert({5,"bheem"});

    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // m.erase(5);








//STL ALGORITHM

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    cout<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"Lower bound "<<lower_bound(v.begin(),v.end(),7)-v.begin()<<endl;
    cout<<"Upper bound "<<upper_bound(v.begin(),v.end(),1)-v.begin()<<endl;

    int a=4;
    int b=5;
    cout<<max(a,b)<<endl;
    cout<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;

    string s="mitesh";
    reverse(s.begin(),s.end());
    cout<<s<<endl;

    rotate(v.begin(),v.begin()+3,v.end());
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    int arr[4]={2,5,3,6};
    sort(arr,arr+4);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}