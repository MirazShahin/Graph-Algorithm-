#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define vii        vector<int>
#define vll        vector<ll>
#define nn         '\n'

#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define sp         " "

#define sz(x)      (int)x.size()
#define all(x)     (x).begin(), (x).end()

using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long;

vector<int> bfs(int n, vector<vector<int>> &adj, int source) {
    vector<int> dis(n, -1);
    vector<int> par(n, -1);
    queue<int> q;
    dis[source] = 0;
    q.push(source);
    par[source] = source;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(dis[it] == -1) {
                dis[it] = dis[node] + 1;
                q.push(it);
                par[it] = node;
            }
        }
    }
    int node = n - 1;

    vector<int> path;
    if(par[node] == -1) {
        return path;
    }
    while(par[node] != node) {
        path.push_back(node);
        node = par[node];
    }
    path.push_back(0);
    reverse(all(path));
    return path;

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
    auto ans = bfs(n, adj, 0);
    if(ans.empty()) {
        cout << "IMPOSSIBLE" << nn;
    }
    else {
        cout << sz(ans) << nn; 
        for(auto u : ans ) cout << u + 1 << sp;
        cout << nn;
    }
    
  
}

int32_t main() {
    FastIO;

    int test_case = 1;
    //cin >> test_case;
    int Case = 1;
    while (test_case--) {
       // cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
