#include<bits/stdc++.h>
using namespace std;


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1, 1e8);
    dist[src] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if(dist[u]!=INT_MAX && dist[v] > (dist[u]+weight)){
                dist[v] = dist[u]+weight;
            }
        }
    }
    return dist;
}