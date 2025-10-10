#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;



//Shortest Path in an Undirected Graph
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int ,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=front;
				q.push(i);
			}
		}
	}
	vector<int>ans;
	int currentNode=t;
	ans.push_back(t);
	while(currentNode!=s){
		currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}


//Shortest Path in a Weighted directed Graph
void dfs(int node, vector<int> &visited, stack<int> &topo, vector<vector<pair<int,int>>> &adj) {
    visited[node] = 1;
    for (auto &edge : adj[node]) {
        int neighbour = edge.first;
        if (!visited[neighbour]) {
            dfs(neighbour, visited, topo, adj);
        }
    }
    topo.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    // Step 1: Create adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        adj[u].push_back({v, wt});
    }

    // Step 2: Topological Sort using DFS
    vector<int> visited(n, 0);
    stack<int> topo;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, topo, adj);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0; 

    // Step 3: Relax nodes in topo order
    while (!topo.empty()) {
        int node = topo.top();
        topo.pop();

        if (dist[node] != INT_MAX) { 
            for (auto &edge : adj[node]) {
                int neighbour = edge.first;
                int wt = edge.second;

                if (dist[node] + wt < dist[neighbour]) {
                    dist[neighbour] = dist[node] + wt;
                }
            }
        }
    }

    // Step 4: Replace unreachable nodes with -1
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) dist[i] = -1;
    }

    return dist;
}







int main(){

    //Shortest Path in an Undirected Graph
    vector<pair<int,int>> edges={{0,1},{0,3},{1,2},{3,4},{4,5},{2,5}};
    int n=6;
    int m=5;
    int s=0;
    int t=5;
    vector<int> ans=shortestPath(edges,n,m,s,t);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;


    //Shortest Path in a Weighted directed Graph
    int N = 6, M = 7;
    vector<vector<int>> Edges = {{0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 5, 4}, {2, 3, 6}, {5, 3, 1}};
    vector<int> result = shortestPathInDAG(N, M, Edges);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}