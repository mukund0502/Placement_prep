#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void print1d(vector<int>&temp){
        for(int i:temp){
            cout << i << " ";
        }
        cout << endl;
    }
    void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&desc, vector<int>&low, int timer, vector<int>&visited, vector<vector<int>>&ret){
        visited[node] = 1;
        desc[node] = low[node] = timer++;
        for(auto neighbour: adj[node]){
            if(neighbour==parent) continue;
            if(visited[neighbour]==0){
                dfs(neighbour, node, adj, desc, low, timer, visited, ret);
                low[node] = min(low[neighbour], low[node]); // while returning dfs, check if low can be reduced or not 
                if(low[neighbour]>desc[node]){ // condition for critical edge 
                    ret.push_back({neighbour, node});
                }
            }else{
                //back-edge case // that can cause loop also
                low[node] = min(low[node], desc[neighbour]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>desc(n, -1); // discovery of all node
        vector<int>low(n, -1); // lowest discovery of all node
        int parent = -1; // parent will change in function
        int timer = 0; // timer increase as the function calls or increase 
        vector<int>visited(n, 0); // keep track of all the visited nodes 
        vector<vector<int>>ret; // return datatype to store answer into the function 
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                dfs(i, parent, adj, desc, low, timer, visited, ret);
            }
        }
        cout << "desc time: " << endl;
        for(int i=0; i<desc.size(); i++){
            cout << desc[i] <<" ";
        }
        cout << endl;
        cout << "low time: " << endl;
        for(int i=0; i<low.size(); i++){
            cout << low[i] <<" ";
        }
        cout << endl;
        
        return ret;
    }
};