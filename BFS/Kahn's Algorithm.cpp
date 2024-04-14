
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
vector<vector<int>> graph;

vector<int> topoSort(int node)  {
    int inDegree[node] = {0};
    for (int i = 0; i < node; i++) {
        for (int it : graph[i]) {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < node; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int var = q.front();
        topo.push_back(var);
        q.pop();
        for (auto adjNode : graph[var]) {
            inDegree[adjNode]--;
            if (inDegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return topo;
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    auto ans = topoSort(n);
    for (auto it : ans) {
        cout << it << sp;
    }
    cout << nn;
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
