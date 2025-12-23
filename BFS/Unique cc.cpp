#include <bits/stdc++.h>
using namespace std;

int n, m;
int const N = 1005;
char grid[N][N];
int visited[N][N];

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++ ) {
      for(int j = 0; j < m; j++ ) {
        cin >> grid[i][j];
      }
    }
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    vector<vector<pair<int, int>>> nodes;
    queue<pair<int, int>> q; 
    for(int i = 0; i < n; i++ ) {
      for(int j = 0; j < m; j++ ) {
         if(grid[i][j] == '1' and visited[i][j] == 0) {
            vector<pair<int, int>> cc;
            q.push({i, j});
            cc.push_back({i, j});
            while(!q.empty()) {
              auto [row, col] = q.front();
              q.pop();
              for(int k = 0; k < 4; k++ ) {
                int nrow = row + dx[k];
                int ncol = col + dy[k];
                if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and 
                  visited[nrow][ncol] == 0 and grid[nrow][ncol] == '1') {
                   cc.push_back({nrow, ncol});
                   visited[nrow][ncol] = 1;
                   q.push({nrow, ncol});
                }
              }
            }
            nodes.push_back(cc);
         } 
      }
    } 
    set<set<pair<int, int>>> ans;
    for(auto &it : nodes ) {
      auto v = it;
      auto [p, q] = v[0]; 
      set<pair<int, int>> st;
      for(auto &[u, v] : it ) { 
        st.insert({abs(u - p), abs(v - q)});
      } 
      ans.insert(st);
    }
    cout << ans.size() << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);                 
    cout.tie(0);
    
    memset(visited, 0, sizeof(visited));
    int test_case = 1; cin >> test_case; 
    int Case = 1;

    while(test_case--) {
        solve();
        Case++;
    }

    return 0;
}
