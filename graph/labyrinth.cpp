#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

char mat[MAXN][MAXN];

int endx, endy;
void dfs(){

}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'B') endx = i, endy= j;

        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){

    //     }
    // }
}