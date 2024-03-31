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

const int N = 1e5 + 7;

vector<vector<int>> tree;
int depth[N];
int height[N];

void dfs(int node, int par) {
   for(auto child : tree[node]) {
       if(child == par) continue;
       depth[child] = depth[node] + 1;  /// Depth pre-calculating
       dfs(child, node);
       height[node] = max(height[node], height[child] + 1);  /// Height pre-calculating
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
    dfs(1, 0);
    for(int i = 1; i <= n; i++ ) {
        cout << depth[i] << sp;
    }
    cout << nn;
    for(int i = 1; i <= n; i++ ) {
        cout << height[i] << sp;
    }
    cout << nn;
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
