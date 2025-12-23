#include <bits/stdc++.h>
using namespace std;

int n, m;
int const N = 1005;
char grid[N][N];
bool visited[N][N];
pair<int, int> par[N][N];

void solve() {
    cin >> n >> m;
    int si = -1, sj = -1, di = -1, dj = -1;
    for(int i = 0; i < n; i++ ) {
      for(int j = 0; j < m; j++ ) {
        cin >> grid[i][j];
        if(grid[i][j] == 'A') {
            si = i, sj = j;
        }
        else if(grid[i][j] == 'B') {
            di = i, dj = j;
        }
      }
    } 
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    queue<pair<int, int>> q;
    visited[si][sj] = 1;
    q.push({si, sj});
    
    while(!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for(int i = 0; i < 4; i++ ) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and 
          grid[nrow][ncol] != '#' and visited[nrow][ncol] == 0) {
          visited[nrow][ncol] = 1;
          q.push({nrow, ncol});
          par[nrow][ncol] = {row, col};
          grid[nrow][ncol] = dir[i];
        }
      }
    }
    if(visited[di][dj] == 0) {
      cout << "NO\n";
      return;
    } 
    int x = di, y = dj;
    string ans;

    while(x != si or y != sj) {
       ans += grid[x][y];
       auto it = par[x][y];
       auto [u, v] = it;
       x = u, y = v;
    }
    reverse(begin(ans), end(ans));
    cout << "YES\n" << ans.size() << '\n';
    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);                 
    cout.tie(0); 
    int test_case = 1;//cin >> test_case; 
    int Case = 1;

    while(test_case--) {
        solve();
        Case++;
    }

    return 0;
}
