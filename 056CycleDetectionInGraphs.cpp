#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


//Cycle Detection in an Undirected Graph using BFS
bool iscycleBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent [src]=-1;
    visited[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return false;    
}

//Cycle Detection in an Undirected Graph using DFS
bool iscycleDFS(int node, int parent, unordered_map<int,bool>&visited, unordered_map<int,list<int>>&adj){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected= iscycleDFS(neighbour,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetectioninUnordered (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int ,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
        //for bfs function call iscycleBFS
            //bool ans=iscycleBFS(i, visited,adj);
        //for dfs function call iscycleDFS
            bool ans=iscycleDFS(i,-1, visited,adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}




//Cycle Detection in a Directed Graph using DFS
bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){
  visited[node]=true;
  dfsVisited[node]=true;
  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected=checkCycleDFS(neighbour,visited,dfsVisited,adj);
      if(cycleDetected){
        return true;
      }
    }
    else if(dfsVisited[neighbour]){
      return true;
    }

  }
  dfsVisited[node]=false;
  return false;
}
bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsVisited;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound=checkCycleDFS(i,visited,dfsVisited,adj);
      if(cycleFound){
        return true;
      }
    }
  }
  return false;
}





int main(){

    //Cycle Detection in an Undirected Graph using BFS and DFS
    vector<vector<int>> edges={{0,1},{0,2},{1,3},{2,4}};
    int n=5;
    int m=4;
    cout<<cycleDetectioninUnordered(edges,n,m)<<endl;


    //Cycle Detection in a Directed Graph using DFS
    vector<pair<int,int>> edges2={{1,2},{2,3},{3,4},{4,2}};
    int n2=4;
    cout<<detectCycleInDirectedGraph(n2,edges2)<<endl;



    




    return 0;
}