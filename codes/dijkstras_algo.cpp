#include <bits/stdc++.h> 
using namespace std;


vector<int>djk(vector<vector<pair<int,int>>>adj, int src, int n){
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<int>dist(n, INT_MAX);
    minheap.push({0, src});
    dist[src] = 0;
    while(!minheap.empty()){
        int topnode = minheap.top().second;
        int topdist = minheap.top().first;
        minheap.pop();
        for(auto neigh:adj[topnode]){
            if(dist[neigh.first]> topdist+neigh.second){
                dist[neigh.first] = topdist+neigh.second;
                minheap.push({dist[neigh.first], neigh.first});
            }
        }
    }
    return dist;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int,int>>>adj(vertices);
    for(int i=0; i<vec.size(); i++){
        int u = vec[i][0];
        int v = vec[i][1];
        adj[u].push_back({v, vec[i][2]});
        adj[v].push_back({u, vec[i][2]});
    }
    return djk(adj, source, vertices);

}
