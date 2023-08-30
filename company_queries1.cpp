#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz 200005


int n, q, e, A[sz], anc[sz][20]; 


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i=1; i<n; ++i) cin >> A[i+1];         

    for(int u=1; u<=n; ++u) {
        anc[u][0] = A[u];

        for(int j=1; j<20; ++j) 
            anc[u][j] = anc[ anc[u][j-1] ][j-1];
    }

    while(q--) {
        int x, k;
        cin >> x >> k;

        for(int i=0; i<20; ++i) 
            if((k>>i) & 1) x = anc[x][i];

        cout << (x ? x : -1) << '\n'; 
    }


}