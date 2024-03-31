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

const int N = 2e5 + 7;
vector<vector<int>> tree;
int depth[N];
void dfs(int node, int par = -1) {
    for(auto child : tree[node]) {
        if(child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}
///---------------------------------------->>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n;
    cin >> n;
    tree.resize(n + 1);
    for(int i = 0; i < n - 1; i++ ) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    int max_node_depth = -1;
    int max_node_pos;
    for(int i = 1; i <= n; i++ ) {
        if(max_node_depth < depth[i]) {
            max_node_depth = depth[i];
            max_node_pos = i;
        }
        depth[i] = 0;
    }
    dfs(max_node_pos);
    for(int i = 1; i <= n; i++ ) {
        if(max_node_depth < depth[i]) {
            max_node_depth = depth[i];
        }
    }
    cout << max_node_depth << nn;
}
int32_t main()
{
    FastIO;
    int test_case = 1;
//    cin >> test_case;
    int Case = 1;
    while(test_case--) {
//    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
