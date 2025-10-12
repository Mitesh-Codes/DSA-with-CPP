#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>

using namespace std;

//TC : O(E log V) using priority queue      and     O(V^2) without priority queue
//SC : O(V) for parent, key, mst and adjacency list

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=1;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }

    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
    }

    // or use a priority queue to optimize the selection of the minimum key vertex
    /*
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});  // (key, node)

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(mst[u]) continue;  // skip if already in MST
        mst[u] = true;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(!mst[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});   
            }
    }
    */


    vector<pair<pair<int,int>,int>>result;
    for(int i=2;i<=n;i++){
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return result;
}


int main(){

    int n = 5; 
    int m = 7;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{2, 3}, 1},
        {{2, 4}, 4},
        {{3, 4}, 5},
        {{3, 5}, 6},
        {{4, 5}, 7}
    };
    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);


    for (auto &edge : mst) {
        cout << "Edge: (" << edge.first.first << ", " << edge.first.second << "), Weight: " << edge.second << endl;
    }


    return 0;
}