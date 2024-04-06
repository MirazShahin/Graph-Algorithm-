
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
int degree[100000];
///------------------------------>>>>>---Start---<<<<<---------------------------------------------
void solve()
{
    /*
     ~ bus topology -> 1st and last node er degree hobe 1 aar baki sobh node er degree 2 hobe
     ~ Star topolgy -> sobgula node er degree hobe 1 arr central node er degree hobe 1 er besi
     ~ Ring Topology -> sobgulo node er degree hobe 2
    */
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;;
        degree[u]++;
        degree[v]++;
    }

   int one_degree = 0;
   int two_degree = 0;
   bool star_detected = 0;
   for(int i = 0; i < n; i++ ) {
      if(degree[i] == 1) one_degree++;
      else if(degree[i] == 2) two_degree++;
      else if(degree[i] > 2) {
        star_detected = 1;
      }
   }
   if(one_degree == 2 and two_degree == n - 2) {
      cout << "bus topology" << nn;
   }
   else if(two_degree == n) {
      cout << "ring topology" << nn;
   }
   else if(star_detected and one_degree == n - 1) {
      cout << "star topology" << nn;
   }
   else {
      cout << "unknown topology" << nn;
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
