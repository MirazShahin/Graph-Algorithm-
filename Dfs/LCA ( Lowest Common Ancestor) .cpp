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
int parent[N];

void dfs(int node, int par = -1) {
    parent[node] = par;
    for(auto child : tree[node]) {
        if(child == par) continue;
        dfs(child, node);
    }
}
vector<int> path(int v) {
    vector<int> ans;
    while(v >= 0) {
        ans.push_back(v);
        v = parent[v];
    }
    reverse(all(ans));
    return ans;
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
    int x, y;
    cin >> x >> y;
    vector<int> path_of_x = path(x);
    vector<int> path_of_y = path(y);

    int LCA = -1;
    for(int i = 0; i < min(sz(path_of_x),sz(path_of_y)); i++ ) {
        if(path_of_x[i] == path_of_y[i] ) {
            LCA = path_of_x[i];
        }
        else {
            break;
        }
    }
    cout << LCA << nn;
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
