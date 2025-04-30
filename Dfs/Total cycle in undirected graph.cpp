#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto child : adj[node]) {
        if(!vis[child]) {
            dfs(child, adj, vis);
        }
    }
}

void do_or_die() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++ ) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int components = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }
    }
    int total_cycles = m - n + components;
    cout << total_cycles << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_case = 1; //cin >> test_case;
    while(test_case-- ) {
        do_or_die();
    }
    return 0;
}
