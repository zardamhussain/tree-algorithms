#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;
using pii = pair<int, int>;

int n, ans, vals[maxN];
vector<pii> adj[maxN];
array<int, 2> dp[maxN]; 


void dfs(int u, int p) {
    
    for(auto[ v, w ] : adj[u]) {
        if(v == p) continue;
        dfs(v, u); 
        dp[u][0] += dp[v][0] + 2*w;   
    }

    int SUM = dp[u][1] = dp[u][0];

    for(auto[ v, w ] : adj[u]) {
        if(v == p) continue;
        dp[u][1] = min(dp[u][1], SUM + dp[v][1] - dp[v][0] - w); 
    }
}

signed main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i=0, u, v, w; i<n-1; ++i) {
        cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(0, -1);

    cout << dp[0][1] << '\n';

}   