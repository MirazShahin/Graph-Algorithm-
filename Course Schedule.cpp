#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;
using ll = long long;

bool is_cycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis) {
    vis[node] = 1;  
    pathvis[node] = 1;     

    for (auto &it : adj[node]) {
        if (!vis[it]) { 
            if (is_cycle(it, adj, vis, pathvis)) {
                return true;   
            }
        } else if (pathvis[it]) {  
            return true;   
        }
    }

    pathvis[node] = 0;   
    return false;      
}

void topo_sort(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &nodes) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            topo_sort(it, adj, vis, nodes);
        }
    }
    nodes.push(node); 
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n); 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;  
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0), pathvis(n, 0);
    bool check = false; 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (is_cycle(i, adj, vis, pathvis)) {
                check = true;
                break;   
            }
        }
    } 
    if (check) {
        cout << "IMPOSSIBLE\n"; 
        return;
    } 
    stack<int> nodes;
    fill(vis.begin(), vis.end(), 0); 

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topo_sort(i, adj, vis, nodes);
        }
    } 
    while (!nodes.empty()) {
        cout << nodes.top() + 1 << " ";  
        nodes.pop();
    }
    cout << '\n';
}
int32_t main() {
    FastIO;
    
    int test_case = 1;
    // cin >> test_case;
    int Case = 1;
    while(test_case--) {
//    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */