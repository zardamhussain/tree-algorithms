#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz 200005


int n, q, A[sz], trav[sz], s[sz], bit[sz];
vector<int> adj[sz];


void upd(int i, int x) {
    for(; i<=n; i += i&-i)  
        bit[i] += x;
}

int query(int i) {
    int sum=0;
    for(; i>0; i -= i&-i) {
        sum += bit[i];
    }
    
    return sum;
}




int timer=1;

void dfs(int u, int p=0) {
    s[u] = 1;
    trav[u] = timer++;
    upd(trav[u], A[u]);

    for(int v : adj[u]) {
        if(v ^ p)
            dfs(v, u), s[u] += s[v];
    }


}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> q;

    for(int i=0; i<n; ++i) cin >> A[i+1];

    for(int i=0; i<n-1; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);


    int type, i, x;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> i >> x;
            x -= A[i]; A[i] += x;
            upd(trav[i], x);

        } else {
            cin >> i;
            cout << query(trav[i] + s[i]-1) - query(trav[i]-1) << '\n';
        }
    }


}