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
#define sp         " "

#define sz(x)      (int)x.size()
#define all(x)     (x).begin(), (x).end()

using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long;

map<string, vector<string>>  adj;
map<string, int>  color;
bool dfs(string node ) {
    color[node] = 1;
    for(auto it : adj[node]) {
       if(color[it] == 0) {
         if(dfs(it))  return true;
       }
       else {
         if(color[it] == 1) return true;
       }
    }
    color[node] = 2;
    return false;
}
bool isCycle() {
    color.clear();
    for(auto it : adj ) {
        string node = it.first;
        if(color[node] == 0) {
            if(dfs(node)) return true;
        }
    }
    return false;
}
void solve() {
   adj.clear();
   int n;
   cin >> n;
   while(n-- ) {
      string a, b;
      cin >> a >> b; 
      adj[a].push_back(b); 
   } 
   if(isCycle()) {
      cout << "No" << nn;
   } 
   else {
    cout << "Yes" << nn;
   }
}
int32_t main() {
    FastIO;

    int test_case = 1;
     cin >> test_case;
    int Case = 1;
    while (test_case--) {
        cout << "Case " << Case << ": ";
        solve();
        Case++;
    }

    return 0;
}
