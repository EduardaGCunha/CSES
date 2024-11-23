#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<int> dp(k+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0 && dp[i-c[j]] != INT_MAX){
                dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
    }

    if(dp[k] == INT_MAX) cout << -1 << endl;
    else cout << dp[k] << endl;
}