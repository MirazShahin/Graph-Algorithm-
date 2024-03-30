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


const int N = 1e5 + 9;
vector<vector<int>> g;
int color[N + 1];
int one_counter = 0;
int zero_counter = 0;
bool dfs(int node, int col) {
    color[node] = col;

    for (auto child : g[node]) {
        if (color[child] == -1) {
            if (!dfs(child, !col)) {
                return false;
            }
        }
        if (color[child] == color[node]) {
            return false;
        }
    }
    return true;
}

bool is_bipartite(int n) {
    for (int i = 0; i < n; i++ ) {
        color[i] = -1;
    }
    for (int i = 0; i < n; i++ ) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                return false;
            }
        }
    }
    for(int i = 0; i < n; i++ ) {
       if(color[i] == 1) one_counter++;
       else zero_counter++;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++ ) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (is_bipartite(n)) cout << "YES" << nn;
    else cout << "NO" << nn;
}
int32_t main()
{
    FastIO;
    int test_case = 1;
//    cin >> test_case;
    int Case = 1;
    while (test_case--) {
//    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
