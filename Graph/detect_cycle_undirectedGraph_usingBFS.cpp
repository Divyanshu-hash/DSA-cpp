#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycle(int V,vector<vector<int>>& adj){
    vector<int> visited(V,0);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i]=1;
            
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                
                for(auto it: adj[node]){
                    if(!visited[it]){
                        visited[it]=1;
                        q.push({it,node});
                    }
                    else if(parent!=it){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(isCycle(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }
    
    return 0;
}