#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vll vector<ll>
#define vii vector<int>
#define nn '\n'
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b) / gcd(a,b)
#define sp " "
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long int;

int n, m;
const int N = 1000;
int grid[N][N];
int vis[N][N];
int dis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 0;
            dis[i][j] = 0;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) { 
            int new_row = row + dx[i];
            int new_col = col + dy[i];
            if (new_row >= 1 and new_row <= n and new_col >= 1 and new_col <= m and !vis[new_row][new_col]) {
                vis[new_row][new_col] = 1;
                dis[new_row][new_col] = steps + 1; 
                q.push({{new_row, new_col}, steps + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dis[i][j] << sp;
        }
        cout << nn;
    }
}

int main() {
    FastIO;
    int test_case = 1;
    // cin >> test_case;
    int Case = 1;
    while (test_case--) {
        // cout << "Case " << Case << ": ";
        solve();
        Case++;
    }
    return 0;
}
