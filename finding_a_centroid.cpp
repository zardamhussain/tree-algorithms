

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz 200005

int n;
vector<int> S, A;
vector<vector<int>> adj;

void dfs(int u, int p=-1) {
    S[u] = 1;

    for(int v : adj[u]) {
        if(v ^ p)
            dfs(v, u), S[u] += S[v];
    }
}


int dfs2(int u, int p=-1) {
    
    for(int v : adj[u]) {
        if(v ^ p) 
            if(S[v] * 2 > n) return dfs2(v, u);
    }


    return u;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n;
    
    adj.resize(n);
    S.resize(n);
    A.resize(n);

    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    
    }

    
    dfs(0);

    cout << dfs2(0)+1;

}