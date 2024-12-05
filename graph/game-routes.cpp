#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN];
int indeg[MAXN];
const int MOD = 1e9+7;

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    vector<int> dp(n, 0);

    for(int i = 0; i < n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    dp[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            dp[u] += dp[v];
            dp[u] %= MOD;
            if(--indeg[u] == 0) q.push(u);
        }
    }

    cout << dp[n-1] << endl;
}