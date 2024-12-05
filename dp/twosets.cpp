#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n; cin >> n;
    int tot = n*(n+1)/2;

    if(tot&1){
        cout << 0 << endl;
        return 0;
    }

    int sum = tot/2;
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int j = 1; j <= n; j++){
        for(int i = sum; i >= j; i--){
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[sum] * 1LL * ((MOD + 1) / 2) % MOD << endl;
}