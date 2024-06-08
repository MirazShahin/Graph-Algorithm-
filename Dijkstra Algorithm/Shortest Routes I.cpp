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

vector<ll> dijkstra(ll n, vector<vector<pair<ll, ll>>> &adj, ll source) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distance(n, LLONG_MAX);
    distance[source] = 0LL;
    pq.push({0, source});
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();
        if (weight > distance[node]) continue;
        for (auto it : adj[node]) {
            ll new_node = it.first;
            ll new_weight = it.second;
            if (new_weight + weight < distance[new_node]) {
                distance[new_node] = new_weight + weight;
                pq.push({distance[new_node], new_node});
            }
        }
    }
    return distance;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
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
