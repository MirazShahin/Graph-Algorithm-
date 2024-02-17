#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
 
#define vll        vector<ll>
#define nn         '\n'
 
#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define YES        cout << "YES\n"
#define NO         cout << "NO\n"
#define yes        cout << "Yes\n"
#define no         cout << "No\n"
#define sp         " "
 
#define sz(x)      (int)x.size()
#define pi         3.1415926535897932384626433832795
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
 
 
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long;

 
///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----The End----<<<<<<<<<<<<<<<<<<<<<<<<<---------------
const int N = 2 * 1e5 + 7;
vector<vector<int>>tree;
int sub_tree[N];
int visit[N];
///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----MiRaZ_HoSsAiN_ShAhIn----<<<<<<<<<<<<<<<<<<<<<-----------------
 
void dfs(int node) {
 
    visit[node] = 1;
    for(auto child : tree[node]) {
        if(visit[child]) continue;
        else {
            dfs(child);
            sub_tree[node] += sub_tree[child];
        }
    }
 
}
///---------------------------------------->>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    int n;
    cin >> n;
 
    tree.resize(n + 1);
    for(int i = 2; i <= n; i++ ) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    for(int i = 1; i <= n; i++ ) {
        sub_tree[i] = 1;
    }
    dfs(1);
    for(int i = 1; i <= n; i++ ) {
        cout << sub_tree[i] - 1 << " ";
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
