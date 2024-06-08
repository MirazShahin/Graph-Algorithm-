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

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &adj, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    pq.push({0, source});
    vector<int> parent(n);
    for(int i = 0; i < n; i++ ) parent[i] = i;
    while(!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto it : adj[node]) {
            int adjnode = it.first;
            int adjdis = it.second;
            if(adjdis + dis < distance[adjnode]) {
                distance[adjnode] = adjdis + dis;
                pq.push({adjdis + dis, adjnode});
                parent[adjnode] = node;
            }
        }
    }
    int node = n - 1;
    vector<int> path;
    while(parent[node] != node) {
        path.push_back(node + 1);
        node = parent[node];
    }
    path.push_back(1);
    reverse(all(path));
    return path;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }
    auto ans = dijkstra(n, adj, 0);
    for (auto u : ans) cout << u << sp;
    cout << nn;
}
int32_t main() {
    FastIO;

    int test_case = 1;
    //cin >> test_case;
    int Case = 1;
    while (test_case--) {
        // cout << "Case " << Case << ": \n";
        solve();
        Case++;
    }

    return 0;
}
