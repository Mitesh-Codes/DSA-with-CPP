#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<set>
#include<climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> st;
    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        st.erase(st.begin());

        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record!=st.end()){
                    st.erase(record);
                }

                dist[neighbour.first]=nodeDistance+neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}




int main(){

    //Shortest Path in a Weighted directed Graph(Dijkstra's Algorithm)
    vector<vector<int>> edges={{0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5}};
    int n=4;
    int m=5;
    int s=0;
    vector<int> ans=dijkstra(edges,n,m,s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}