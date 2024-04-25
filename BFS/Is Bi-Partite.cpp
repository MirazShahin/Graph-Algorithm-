#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

#define vll        vector<ll>
#define vii        vector<int>
#define nn         '\n'

#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define sp         " "

#define sz(x)      (int)x.size()
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()


using namespace std;
using ll = long long int;

bool bfs(int node, int color[], vector<vector<int>> adj) {
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int vartex = q.front();
        q.pop();
        for(auto child : adj[vartex]) {
            if(color[child] == -1) {
                color[child] = !color[vartex];
                q.push(child);
            }
            else {
                if(color[child] == color[vartex]) {
                    return false;
                }
            }
        }
    }
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    adj.resize(n + 1);
    for(int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int color[n];
    for(int i = 0; i < n; i++ ) {
        color[i] = -1;
    }
    for(int i = 0; i < n; i++ ) {
        if(color[i] == -1) {
            if(bfs(i, color, adj) == false) {
                cout << "NOT Bi-partite" << nn;
                return;
            }
        }
    }
    cout << "Bi-partite" << nn;
}
int32_t main() {
    FastIO;

    int test_case = 1;
//    cin >> test_case;
    int Case = 1;
    while(test_case--) {
    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
