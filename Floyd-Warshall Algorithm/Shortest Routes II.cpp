#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;
using ll = long long int;
 
const long long INF = 1e18;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dis(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++ ) {
            if(i == j) {
                dis[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++ ) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        dis[u][v] = min(dis[u][v], 1LL * c);
        dis[v][u] = min(dis[v][u], 1LL * c);
    }

    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++ ) {
            for(int k = 0; k < n; k++ ) {
               if(dis[j][i] < INF and dis[i][k] < INF) {
                  dis[j][k] = min(dis[j][k], 1LL * dis[i][j] + dis[i][k]);
               }
            }
        }
    }
    while(q-- ) {
        int u, v; cin >> u >> v;
        u--, v--;
        if(dis[u][v] == INF) cout << -1 << '\n';
        else cout << dis[u][v] << '\n';
    }
}
int32_t main() {
    FastIO; 
    int test_case = 1;
    // cin >> test_case;
    int Case = 1;
    while(test_case--) {
//    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
