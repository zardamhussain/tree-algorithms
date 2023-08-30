#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz 200005


int n, q, e, A[sz], anc[sz][20], L[sz]; 


int LCA(int u, int v) {
    if(L[u] < L[v]) swap(u, v);
    int diff = L[u] - L[v];
    
    for(int i=19; ~i; --i)
        if((diff>>i) & 1) u = anc[u][i];
    
    if(u == v) return u;

    for(int i=19; ~i; --i) 
        if(anc[u][i] ^ anc[v][i])
            u = anc[u][i], v = anc[v][i];

    return anc[u][0];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i=1; i<n; ++i) cin >> A[i+1];         



    for(int u=1; u<=n; ++u) {
        anc[u][0] = A[u];

        L[u] = L[A[u]] + 1;

        for(int j=1; j<20; ++j) 
            anc[u][j] = anc[ anc[u][j-1] ][j-1];
    }

    while(q--) {
        int x, k;
        cin >> x >> k;

        cout << LCA(x, k) << '\n';
    }


}