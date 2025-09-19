#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//Question1: Maximum frequency Number
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;

    int maxFreq=0;
    int maxAns=0;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;

}


int main(){

    /*
    unordered_map<string, int> n;
    //TC of all operations is O(1) on average
    //but in worst case, it can be O(n)

    // Insertion
    pair<string, int> p = make_pair("Mango", 100);
    n.insert(p);

    pair<string,int>p2("Apple", 120);
    n.insert(p2);

    n["Banana"] = 20;
    n["Banana"] += 20; // Banana key already exists, so it will update the value
    //No duplicate keys allowed


    
    // Search
    cout<<"Price of Mango is "<<n["Mango"]<<endl; 
    cout<<n.at("Mango")<<endl;
    //cout<<n.at("Guava")<<endl; // throws an error, key not found
    cout<<n["Guava"]<<endl; // inserts Guava with 0 value, key not found
    cout<<n.at("Guava")<<endl; // now it works


    // Size
    cout<<"Size of map is "<<n.size()<<endl;


    //count
    cout<<n.count("Mango")<<endl; // 1
    cout<<n.count("Pineapple")<<endl; // 0

    // Erase
    n.erase("Guava");
    cout<<"Size of map is "<<n.size()<<endl;


    // Iterate over all the key-value pairs in map 
    for(auto i:n){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //another way to iterate
    for(auto it=n.begin();it!=n.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<endl;

    // another way to iterate
    unordered_map<string,int> :: iterator it2=n.begin();
    while(it2!=n.end()){
        cout<<it2->first<<" "<<it2->second<<endl;
        it2++;
    }

    //in unordered_map, the order of the keys is not guaranteed
    //it may vary from execution to execution

    
    
    //Ordered map or map
    //but in map, the keys are always in sorted order
    //but TC of all operations is O(log n) in map


    map<string,int> m;
    m["Mango"]=100;
    m["Apple"]=120;
    m["Banana"]=20;

    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    */

    //Question1: Maximum frequency Number
    vector<int> arr={2,3,3,5,3,4,1,4,5,5,5};
    int n=arr.size();
    cout<<maximumFrequency(arr,n)<<endl;




    return 0;
}