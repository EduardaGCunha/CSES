#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXN = 2*(1e5)+7;
const int MAXLOG = 30;
int dp[MAXLOG+1][MAXN];
int main(){
    fastio;
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> dp[0][i];
    }

    for(int i = 1; i <= MAXLOG; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        for(int i = 0; i <= MAXLOG; i++){
            if(b & (1 << i)) a = dp[i][a];
        }
        cout << a << endl;
    }

}