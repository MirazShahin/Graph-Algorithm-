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
#define yes        cout << "Yes\n"
#define no         cout << "No\n"
#define sp         " "

#define sz(x)      (int)x.size()
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()

using namespace std;
using ll = long long int;

void toposort(int n, vector<vector<int>> &adj, vector<int> &degree, vector<int> &is_cycle) {
    queue<int> q;
    for(int i = 0; i < n; i++ ) {
        if(degree[i] == 1) {
            q.push(i);
            is_cycle[i] = 0;
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            degree[it]--;
            if(degree[it] == 1) {
                q.push(it);
                is_cycle[it] = 0;
            }
        }
    }
}
void dfs_for_a(int a, vector<vector<int>> &adj, vector<int> &dis_a) {
    queue<int> q;
    q.push(a);
    dis_a[a] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(dis_a[it] == -1) {
                dis_a[it] = dis_a[node] + 1;
                q.push(it);
            }
        }
    }
}
void bfs_for_b(int b, vector<vector<int>> &adj, vector<int> &dis_b) {
    queue<int> q;
    q.push(b);
    dis_b[b] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(dis_b[it] == -1) {
                dis_b[it] = dis_b[node] + 1;
                q.push(it);
            }
        }
    }
}
void solve() {
     int n, a, b;
     cin >> n >> a >> b;
     a--;
     b--;
     vector<vector<int>> adj;
     adj.resize(n + 2);
     vector<int> degree(n, 0);
     for(int i = 0; i < n; i++ ) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
     }
     vector<int> is_cycle(n + 1, 1);
     toposort(n, adj, degree, is_cycle);
 
     vector<int> dis_a(n + 1, -1);
     vector<int> dis_b(n + 1, -1);
     bfs_for_a(a, adj, dis_a);
     bfs_for_b(b, adj, dis_b);
     bool check = 0;
     for(int i = 0; i < n; i++ ) {
        cout << dis_a[i] << sp;
     }
     cout << nn;
     for(int i = 0; i < n; i++ ) {
        cout << dis_b[i] << sp;
     }
     cout << nn;
     for(int i = 0; i < n; i++ ) {
        if(is_cycle[i] and dis_a[i] > dis_b[i]) {
            check = 1;
            break;
        }
     }
     if(check) cout << "YES" << nn;
     else cout << "NO" << nn;
}
int32_t main() {
    FastIO;

    int test_case = 1;
    cin >> test_case;
    int Case = 1;
    while(test_case--) {
        solve();
        Case++;
    }

    return 0;
}
