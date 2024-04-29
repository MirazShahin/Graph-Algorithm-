#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto child : adj[node]) {
        if(!vis[child]) {
            if(dfs(child, node, adj, vis)) {
                return true;
            }
        }
        else{
            if(child != par) {
                return true;
            }
        }
    }
    return false;
}
void solve() {
    int n, m;
	cin >> n >> m;
	vector<vector<int>> adj;
	adj.resize(n + 1);
	for(int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n, 0);
	bool bug_found = 0;
	for(int i = 0; i < n; i++ ) {
        if(!vis[i]) {
            if(dfs(i, -1, adj, vis) == 1) {
                bug_found = 1;
                break;
            }
        }
	}
	if(bug_found) {
        cout << "Suspicious bugs found!" << endl;
	}
	else {
        cout << "No suspicious bugs found!" << endl;
	}
}
int main() {
    int testcase;
    cin >> testcase;
    int Case = 1;
    while(testcase-- ) {
        cout << "Scenario #" << Case << ":\n";
        solve();
        Case++;
    }

}
