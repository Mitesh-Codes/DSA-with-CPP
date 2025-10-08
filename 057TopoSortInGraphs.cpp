#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<queue>
#include<vector>
using namespace std;



//Topological Sort using DFS
void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}



//Topological Sort using Kahn's Algorithm (BFS)
vector<int> topologicalSortBFS(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}





int main(){

    //Topological Sort using DFS
    vector<vector<int>>edges={{0,1},{0,2},{1,3},{2,3},{2,4},{3,5},{4,5}};
    int v=6;
    int e=7;
    vector<int>ans=topologicalSort(edges,v,e);
    for(auto node:ans){
        cout<<node<<" ";
    }
    cout<<endl;


    //Topological Sort using Kahn's Algorithm (BFS)
    vector<int>ans2=topologicalSortBFS(edges,v,e);
    for(auto node:ans2){
        cout<<node<<" ";
    }
    cout<<endl;

    return 0;
}