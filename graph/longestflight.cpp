#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
vector<int> graph[MAXN], reverso[MAXN];
int indeg[MAXN];
const int MOD = 1e9+7;

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        reverso[b].push_back(a);
        indeg[b]++;
    }

    queue<int> q;
    vector<int> dp(n, INT_MIN);
    vector<int> p(n, -1);

    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> toposort;
    while(!q.empty()){
        int v = q.front(); q.pop();
        toposort.push_back(v);
        for(auto u : graph[v]){
            if(--indeg[u] == 0) q.push(u);
        }
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int v = toposort[i];
        for(auto u : reverso[v]){
            if(dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                p[v] = u;
            }
        }
    }

    if(dp[n-1] < 0){
        cout << "IMPOSSIBLE\n"; 
    }else{
        cout << dp[n-1] << endl;
        vector<int> ans;
        ans.push_back(n);
        for(int i = p[n-1]; i != -1; i = p[i]){
           ans.push_back(i+1);
        }
        reverse(ans.begin(), ans.end());
        for(auto u : ans){
            cout << u << " ";
        }
        cout << endl;
    }
}