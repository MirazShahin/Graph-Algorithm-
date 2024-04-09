
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

const int N = 1e5 + 7;
vector<vector<int>> adj;
int vis[N];

///---------------------------------------->>>>>---Start---<<<<<---------------------------------------------
bool bfs(int node){
   queue<pair<int,int>> q;
   vis[node] = 1;
   q.push({node, -1});
   while(!q.empty()) {
     int node_ = q.front().first;
     int parent = q.front().second;
     q.pop();
     for(auto child : adj[node_]) {
        if(!vis[child]) {
            vis[child] = 1;
            q.push({child, node_});
        }
        else {
            if(child != parent) {
                return true;  /* Cycle found because there is a node 
                               which is previously visited but which 
                               is not came from parent.
                            */
            }
        }
     }
   }
   return false;  /// No cycle found

}
bool is_cycle(int node) {
    /// if there are multiple components
    vis[node] = 0;
    for(int i = 0; i < node; i++ ) {
        if(!vis[i]) {
            if(bfs(i)){
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(is_cycle(n)) {
        cout << "Cycle is present" << nn;
    }
    else {
        cout << "NO Cycle found" << nn;
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
