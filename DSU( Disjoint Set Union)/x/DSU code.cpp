#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0); 

using namespace std;
using ll = long long int;
 
const int N = 2e5 + 5;

int par[N];
int size[N]; 

void Make(int node) {
    par[node] = node;
    size[node]  = 1;
}

int Find(int node) {
    if(node == par[node]) {
        return node;
    }
    return par[node] = Find(par1[node]);
}
void Union(int u, int v) {
    int a = Find(u);
    int b = Find(v);
    if(a != b ) {
        if(size[a] > size[b]) {
            swap(size[a], size[b]);
        }
        par[b] = a;
        size[a] += size[b];
    }
} 
void solve() {
   
      
}

int32_t main() {
    FastIO;
 
    int test_case = 1;
    // cin >> test_case;
    int Case = 1;
    while (test_case--) {
        solve();
        Case++;
    }

    return 0;
}
