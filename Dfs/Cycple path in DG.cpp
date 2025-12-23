#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool dfs(int node,
         vector<vector<int>> &adj,
         vector<int> &vis,
         vector<int> &pathvis,
         vector<int> &parent,
         vector<int> &cycle) {

    vis[node] = 1;
    pathvis[node] = 1;

    for(int it : adj[node]) {
        if(!vis[it]) {
            parent[it] = node;
            if(dfs(it, adj, vis, pathvis, parent, cycle))
                return true;
        }
        else if (pathvis[it]) {
            int cur = node;
            cycle.push_back(it);
            while(cur != it) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(it);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0), pathvis(n, 0), parent(n, -1);
    vector<int> cycle;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, pathvis, parent, cycle)) {
                cout << cycle.size() << "\n";
                for(int x : cycle) cout << x + 1 << " ";
                cout << "\n";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    FastIO;
    solve();
    return 0;
}
