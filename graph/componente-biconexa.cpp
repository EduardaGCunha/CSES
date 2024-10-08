#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN];
int visited[MAXN], pre[MAXN], low[MAXN];
int t = 0;

void dfs(int v, int pai) {
    t++;
    pre[v] = t;
    low[v] = t;
    visited[v] = 1;
    int qtdFilhos = 0;

    for(auto )
}