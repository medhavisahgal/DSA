#include<bits/stdc++.h>
using namespace std;
int main(){
    // v = vertices, e = edges
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    //or you can make vectors of vectors
    // vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//for undirected graph
    }
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
    }
    //for weighted graph
    vector<pair<int,int>> adj1[v];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj1[u].push_back(make_pair(v,w));
        adj1[v].push_back(make_pair(u, w));//for undirected graph
    }
    return 0;
}