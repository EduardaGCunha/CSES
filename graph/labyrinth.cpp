#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;

int grid[MAXN][MAXN];
int visited[MAXN][MAXN];

int n, m;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
bool path = false;

void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x+d1[i];
        int ny = y+d2[i];
        if(nx < 0 || nx > n) continue;
        if(ny < 0 || ny > m) continue;
        dfs()
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

        }
    }
}