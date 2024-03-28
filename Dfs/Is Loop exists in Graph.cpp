

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


const int N = 1e5 + 7;
vector<vector<int>> graph;
int vis[N];

bool dfs(int vartex, int parent) {
    vis[vartex] = 1;
    bool is_looop = 0;
    for(auto child : graph[vartex]) {
        if(vis[child] and child == parent) continue;
        if(vis[child]) return true;

        is_looop |= dfs(child, vartex);
    }
    return is_looop;
}
///------------------------------>>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    for(int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool is_loop = false;
    for(int i = 1; i <= n; i++ ) {
        if(vis[i]) continue;
        if(dfs(i, 0)) {
           is_loop = true;
           break;
        }
    }
    cout << is_loop << nn;
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

