#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz 200005

int n, A[sz];
vector<int> adj[sz], path;
vector<array<int, 3>> startend;

int timer=-1;


void dfs(int u, int p=0) {
    path.emplace_back(u);

    array<int, 3> tmp;
    tmp[0] = ++timer;

    for(int v : adj[u]) 
        if(v ^ p)
            dfs(v, u);
    
    tmp[1] = timer;
    tmp[2] = u;
    startend.emplace_back(tmp);
}

void create_mapping() {
    unordered_map<int, int> um;
    for(int i=1; i<=n; ++i) 
        if(!um.count(A[i])) 
            um[A[i]] = um.size();
    
    for(int i=1; i<=n; ++i) A[i] = um[A[i]];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n;

    for(int i=0; i<n; ++i) cin >> A[i+1];

    for(int i=0; i<n-1; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    create_mapping();


    dfs(1);

    int block = sqrt(startend.size());


    sort(begin(startend), end(startend), [&](auto& a, auto& b) {
        if(a[0]/block != b[0]/block) return a[0] < b[0];
        return a[1] < b[1];
    } );

    

    vector<int> ans(n+1);

    int freq[sz] = { 0 };
    
    int count = 0;

    auto add = [&](int x) {
        if(++freq[x] == 1) count++; 
    };

    auto remove = [&](int x) {
        if(--freq[x] == 0) count--; 
    };

    int ML = 0, MR = -1;
    for(auto [L, R, i] : startend) {

        while(ML > L) add( A[ path[--ML] ] );
        while(MR < R) add( A[ path[++MR] ] );
        while(ML < L) remove( A[ path[ML++] ] );
        while(MR > R) remove( A[ path[MR--] ] );
        
        ans[i] = count;
    }

    for(int x : ans | views::drop(1)) cout << x << ' ';

}