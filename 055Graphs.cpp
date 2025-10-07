#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;
template<typename T>

class graph{

    public:
    unordered_map<T,list<T>> adj;
    
    void addEdge(T u,T v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


//BFS Traversal
 // on some platform they need sorted order , so list doesn't work . use set.
void prepareAdjList(unordered_map<int,list<int>>& adjList, vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int>>& adjList, unordered_map<int,bool>& visited, vector<int>& ans, int node){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}    
vector<int> BFS(int vertex, vector<pair<int,int>>edges){
    unordered_map<int,list<int>> adjList;
    vector<int>ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}



//DFS Traversal
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>>&adj,vector<int>&component){
    component.push_back(node);
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}




int main(){

    // int n;
    // cout<<"Enter the Number of node"<<endl;
    // cin>>n;
    // int m;
    // cout<<"Enter the number of edges"<<endl;
    // cin>>m;

    // graph <int> g;
    // cout << "Enter edges (u v):" << endl;
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addEdge(u,v,0);
    // }

    // g.printAdjList();


//BFS Traversal
    vector<pair<int,int>> edges={{0,1},{0,3},{1,2},{2,3},{4,5}};
    int vertex=6;
    vector<int> ans=BFS(vertex,edges);
    cout<<"BFS Traversal is "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


//DFS Traversal
    int V=5;
    int E=4;
    vector<vector<int>> edges1={{0,1},{0,2},{1,3},{2,4}};
    vector<vector<int>> ans1=depthFirstSearch(V,E,edges1);
    cout<<endl<<"DFS Traversal is "<<endl;
    for(int i=0;i<ans1.size();i++){
        for(int j=0;j<ans1[i].size();j++){
            cout<<ans1[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}