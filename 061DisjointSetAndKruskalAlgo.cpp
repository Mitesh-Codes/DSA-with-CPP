#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//TC : O(E log E) + O(E * α(V)) where α is the Inverse Ackermann function (or just O(E log E because α(V) is very slow growing and for all practical purposes can be considered a small constant)
//SC : O(V) for parent and rank arrays


bool cmp(vector<int>&a,vector<int>&b){
  return a[2]<b[2];
}

void makeSet(vector<int>&parent,vector<int>&rank,int n){
    for(int i=0;i<n;i++){
      rank[i]=0;
      parent[i]=i;
    }
}

int findParent(vector<int>&parent,int node){
  if(parent[node]==node){
      return node;
  }
  return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u,int v, vector<int>&parent,vector<int>&rank){
  u=findParent(parent,u);
  v=findParent(parent,v);

  if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else if(rank[v]<rank[u]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  sort(edges.begin(),edges.end(),cmp);
  vector<int>parent(n);
  vector<int>rank(n);
  makeSet(parent,rank,n);

  int minWeight=0;

  for(int i=0;i<edges.size();i++){
    int u=findParent(parent,edges[i][0]);
    int v=findParent(parent,edges[i][1]);
    int wt=edges[i][2];

    if(u!=v){
      minWeight+=wt;
      unionSet(u,v,parent,rank);
    }
  }
  return minWeight;

}


int main(){
    int n = 5; 
    int m = 7;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 2, 25},
        {2, 4, 30}
    };

    cout << "Minimum Spanning Tree weight: " << minimumSpanningTree(edges, n) << endl;

    return 0;
}