#include<bits/stdc++.h>
using namespace std;


int findparent(vector<int>&parent, int node){
  if(parent[node]==node) return node;
  return parent[node] = findparent(parent,  parent[node]);
}

void unionfunc(vector<int>&parent, vector<int>&rank, int u, int v){
  int parv = findparent(parent, v);
  int paru = findparent(parent, u);
  if(rank[parv]<rank[paru]){
    parent[v] = u;
  }else if(rank[parv]>rank[paru]){
    parent[u] = v;
  }else{
    parent[u] = v;
    rank[v]++;
  }
}

bool comp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{

  vector<int>parent(n);
  for(int i=0; i<n; i++){
    parent[i] = i;
  }
  vector<int>rank(n, 0);
  sort(edges.begin(), edges.end(), comp);

  int components = n;
  int cost = 0;
  for(int i=0; i<edges.size(); i++){
    int u = findparent(parent, edges[i][0]);
    int v = findparent(parent, edges[i][1]);

    if(u!=v){
      unionfunc(parent, rank, u, v);
      components--;
      cost+=edges[i][2];
      if(components==1){
        return cost;
      }
    }
  }
  return 0;
}