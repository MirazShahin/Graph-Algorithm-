#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
const int N = 1e6 + 5;
int vis[N];
stack<int> s;

void topological_sort_dfs(int node) {
    vis[node] = 1;
    for(auto child : adj[node]) {
        if(vis[child] == 1) continue;
        topological_sort_dfs(child);
    }
    s.push(node);
}
int main() {
    int node, edge;
    cin >> node >> edge;
    adj.resize(node + 1);
    for(int i = 0; i < edge; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 0; i < node; i++ ) {
        if(!vis[i]) {
            topological_sort_dfs(i);
        }
    }
    vector<int> ans;
    while(!s.empty()) {
      int x = s.top();
      ans.push_back(x);
      s.pop();
    }
    for(auto it : ans ) cout << it << " ";
    cout << endl;
    
    return 0;
}
