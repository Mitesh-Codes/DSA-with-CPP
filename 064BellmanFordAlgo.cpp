#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


//TC: O(N*M) SC:O(N)
int bellmonFord(int n, int m, int src,int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //check for negative cycles
    bool flag=0;
    for(int j=0;j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];

        if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
            flag=1;
        }
    }

    if(flag==0){
        return dist[dest];
    }
    return -1;
}

int main(){

    int n = 5;
    int m = 8;
    int src = 1;
    int dest = 5;
    vector<vector<int>> edges = {
        {1, 2, 9},
        {1, 3, 6},
        {1, 4, 5},
        {1, 5, 3},
        {2, 3, -2},
        {3, 4, 4},
        {4, 2, -3},
        {5, 4, 2}
    };
    //For non negative weight cycles
    vector<vector<int>> edges2 = {
        {1, 2, 9},
        {1, 3, 6},
        {1, 4, 5},
        {1, 5, 3},
        {2, 3, 2},
        {3, 4, 4},
        {4, 2, 3},
        {5, 4, 2}
    };

    int shortestPath = bellmonFord(n, m, src, dest, edges2);
    if (shortestPath != -1) {
        cout << "Shortest path from " << src << " to " << dest << " is: " << shortestPath << endl;
    } else {
        cout << "Negative weight cycle detected." << endl;
    }


    return 0;
}