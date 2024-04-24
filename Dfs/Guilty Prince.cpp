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

/// Direction_array......
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};;
const int N = 1007;
char grid[N][N];
int vis[N][N];
int ans = 0;
void dfs(int row, int col, int m, int n) {
    vis[row][col] = 1;
    ans++;
    for(int i = 0; i < 4; i++ ) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and !vis[nrow][ncol] and grid[nrow][ncol] != '#') {
            dfs(nrow, ncol, m, n);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++ ) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++ ) {
            vis[i][j] = 0;
        }
    }
    ans = 0;
    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++ ) {
            if(grid[i][j] == '@'){
              dfs(i, j, m, n);
              break;
            }
        }
    }
   cout << ans << nn;
}
int32_t main()
{
    FastIO;

    int test_case = 1;
    cin >> test_case;
    int Case = 1;
    while(test_case--) {
    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
