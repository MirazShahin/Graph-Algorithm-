
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

const int x = 1005;
const int y = 1005;
int grid[x][y];
int vis[x][y];
int n, m;
///---------------------------------------->>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++ ) {
            cin >> grid[i][j];
        }
    }
    queue<pair<pair<int,int>, int >> q;

    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++ ) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else {
                vis[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int del_row[4] = {-1, 0, 1, 0};
    int del_col[4] = {0, 1, 0, -1};
    while(!q.empty()) {
        int row = q.front().first.first;
        int column = q.front().first.second;
        int tim = q.front().second;
        q.pop();
        ans = max(ans, tim);
        for(int i = 0; i < 4; i++ ) {
           int nrow = row + del_row[i];
           int ncolumn = column + del_col[i];
           if(nrow >= 0 and nrow < n and ncolumn >= 0 and ncolumn < m and vis[nrow][ncolumn] != 2 and grid[nrow][ncolumn] == 1) {
                q.push({{nrow, ncolumn}, tim + 1});
                vis[nrow][ncolumn] = 2;
           }
        }
    }
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++ ) {
            if(vis[i][j] != 2 and grid[i][j] == 1) {
                cout << -1 << nn;
                return;
            }
        }
    }
    cout << ans << nn;
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
