void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
 
    vector<int> which_cycle(n, -1); 
    vector<int> cycle_size;   
    int id = 0;
 
    for(int i = 0; i < n; i++) {
        if(which_cycle[i] == -1) {
            int x = i;
            int cnt = 0;
            vector<int> nodes;
            while(which_cycle[x] == -1) {
                which_cycle[x] = id;
                nodes.push_back(x);
                x = v[x] - 1;
                cnt++;
            }
            cycle_size.push_back(cnt);
            id++;
        }
    }
    int q = n;  
    int vis[n + 1] = {0};
    ll ans = 0;
    while (q--) {
        int x;
        cin >> x;
        x--;  
        int cc = which_cycle[x];
        if(!vis[cc]) {
          ans += cycle_size[cc];
          vis[cc] = 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
 
