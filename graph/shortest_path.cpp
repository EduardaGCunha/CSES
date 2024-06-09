#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 200005;
int n, m;
vector<pair<int, int>> graph[MAXN];
int dis[MAXN];
 
signed main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
 
    for(int i = 0; i <= n; i++) dis[i] = LLONG_MAX;
    
    priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > q;
    dis[1] = dis[0] = 0;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second, b = q.top().first;
        q.pop();
        if(dis[a] < b) continue;
        for (auto u : graph[a]) {
            int e = u.first, f = u.second;
            if (dis[e] > b + f) {
                dis[e] = b + f;
                q.push({dis[e],e});
            }
        }
    }

 
    for(int i = 1; i < n+1; i++){
        cout << dis[i] << " "; 
    }
    cout << endl;
 
}