

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

const int N = 1000;
char grid[N][N];

void dfs(int i, int j, int n, int m) {
    if(i < 0 or j < 0) return;
    if(i >= n or j >= m) return;
    if(grid[i][j] != '.') return;

    grid[i][j] = '#';  /// here visited are marked

    dfs(i, j + 1, n, m);
    dfs(i, j - 1, n, m);
    dfs(i + 1, j, n, m);
    dfs(i - 1, j, n, m);
}
///------------------------------>>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++ ) {
       for(int j = 0; j < m; j++ ) {
          cin >> grid[i][j];
       }
    }

    int ans = 0;
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++ ) {
            if(grid[i][j] == '.') {
                dfs(i, j, n, m);
                ans++;
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

