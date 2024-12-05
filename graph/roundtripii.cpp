#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
int p[MAXN], visited[MAXN];
int st = -1, ed = -1;

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u);
            p[u] = v;
        }
        if(visited[u]==1){
            st = u;
            ed = v;
        }
    }
    visited[v] = 2;
}

void print_cycle(int s, int d){
    vector<int> cycle;
    cycle.push_back(s);
    for(int i = d; i != s; i = p[i]){
        cycle.push_back(i);
    }
    cycle.push_back(s);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for(auto u : cycle){
        cout << u+1 << " ";
    }
    cout << endl;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        //graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        st = -1, ed = -1;
        dfs(i);
        if(st == -1) continue;
        print_cycle(st, ed);
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
}