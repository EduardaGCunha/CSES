#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e3+7;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    dp[0][0] = grid[0][0] == '*'? 0 : 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(grid[i][j] == '*') continue;
           if(i-1 >= 0  && grid[i-1][j] != '*') dp[i][j] += dp[i-1][j];
           if(j-1 >= 0 && grid[i][j-1] != '*') dp[i][j] += dp[i][j-1];

           dp[i][j] %= MOD;
        }
    }

    cout << dp[n-1][n-1] << endl;

}