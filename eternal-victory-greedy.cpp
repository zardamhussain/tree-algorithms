
/*
    question-link : https://codeforces.com/contest/61/problem/D
    this solution is greedy based
    
    Greedy solution:
        You should stop at the city with maximum distance from the root (city number 1). 
        So all roads are traversed twice except for the roads between the root and this city.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;
using pii = pair<int, int>;

int n, maxpathsum, SUM;
vector<pii> adj[maxN];


void dfs(int u, int p, int sum=0) {
    
    for(auto[ v, w ] : adj[u]) {
        if(v == p) continue;
        dfs(v, u, sum + w);
        if(adj[v].size() == 1) 
            maxpathsum = max(maxpathsum, sum+w);
    }

  
}

signed main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i=0, u, v, w; i<n-1; ++i) {
        cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        SUM += 2*w;
    }

    dfs(0, -1);

    cout << SUM - maxpathsum << '\n';

}   