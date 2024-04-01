
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
vector<vector<int>> tree;
int vis[N];
int child_cnt[N];
void linear_dfs(int node, int par = -1) {
    for(auto child : tree[node]) {
      if(child != par) {
          child_cnt[node]++;
          linear_dfs(child, node);
      }
    }
}
bool dfs(int node, int par) {
    vis[node] = 1;
    for(auto child : tree[node]) {
        if(!vis[child]) {
            if(dfs(child, node) == true) {
               return true;
            }
        }
        else {
            if(child != par) {
                return true;
            }
        }
    }
    return false;
}
///------------------------------>>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    tree.resize(n + 1);
    for(int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
//        u--;
//        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

   if(dfs(1, -1)) {
     cout << "Ring Topology" << nn;
   }
   else {
      linear_dfs(1);
      bool detect = true;
      for(int i = 1; i <= n; i++ ) {
          if(child_cnt[i] > 1) {
             detect = false;
             break;
          }
      }
      if(detect) {
        cout << "Bus Topology" << nn;
      }
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
