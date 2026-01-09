#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int node,int parent,vector<int>& vis,vector<vector<int>>& adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,adj)){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V,vector<vector<int>>& adj){
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) format:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isCycle(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}