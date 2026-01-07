#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjLs[node]) {
        if (!vis[it]) {
            dfs(it, adjLs, vis);
        }
    }
}

// Function to count number of provinces
int numProvinces(vector<vector<int>> adj, int V) {
    vector<vector<int>> adjLs(V);

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);
    int cnt = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjLs, vis);
        }
    }

    return cnt;
}


int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    int provinces = numProvinces(adj, V);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
