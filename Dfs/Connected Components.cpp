
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


///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----The End----<<<<<<<<<<<<<<<<<<<<<<<<<---------------
const int N = 1e5 + 7;
vector<vector<int>> graph;
vector<vector<int>> connected_component;
vector<int> current_connected_component;
int vis[N];
void dfs(int vartex) {
    vis[vartex] = 1;
    current_connected_component.push_back(vartex);
    for(auto child : graph[vartex]) {

        if(vis[child]) continue;
        dfs(child);

    }
}
///------------------------------>>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    graph.resize(m + 1);
    for(int i = 0; i < n; i++ ) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++ ) {
        if(vis[i]) continue;
        current_connected_component.clear();
        dfs(i);
        connected_component.push_back(current_connected_component);
        ans++;
    }
    cout << ans << nn;
//    cout << sz(current_connected_component) << nn;
    for(auto u : connected_component) {
        cout << sz(u) << sp;
//        for(auto s : u) {
//            cout << s << sp;
//        }
//        cout << nn;
    }

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
