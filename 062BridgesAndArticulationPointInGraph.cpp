#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;



//Bridges in a graph
//A bridge is an edge which when removed, increases the number of connected components in a graph

void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>> &result,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for( auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);
            //check bridge
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>>adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent=-1;
    unordered_map<int,bool>vis;

    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;

}




//Articulation Point in a graph
//An articulation point is a vertex which when removed, increases the number of connected components in a graph
void findAP(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,vector<int>&ap){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    int child=0;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            child++;
            findAP(nbr,node,timer,disc,low,vis,adj,ap);
            low[node]=min(low[node],low[nbr]);
            //check articulation point
            if(low[nbr]>=disc[node] && parent!=-1){
                ap[node]=1;
            }
        }
        else{
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
    if(parent==-1 && child>1){
        ap[node]=1;
    }
    
}




int main(){



    // Example usage of findBridges function
    /*
    int v = 5;
    int e = 5;
    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 0});
    edges.push_back({1, 3});
    edges.push_back({3, 4});

    vector<vector<int>> bridges = findBridges(edges, v, e);
    for (auto bridge : bridges) {
        cout << "Bridge found: " << bridge[0] << " - " << bridge[1] << endl;
    }
    */


    // Example usage of articulation point function
    unordered_map<int,list<int>>adj;
    int v=5;
    int e=5;

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    int timer=0;
    vector<int>disc(v);
    vector<int>low(v);
    unordered_map<int,bool>vis;
    vector<int>ap(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            findAP(i,-1,timer,disc,low,vis,adj,ap);
        }
    }
    for(int i=0;i<v;i++){
        if(ap[i]){
            cout<<"Articulation Point found: "<<i<<endl;
        }
    }

    return 0;
}