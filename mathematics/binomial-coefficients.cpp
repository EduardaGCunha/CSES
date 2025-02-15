#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6+1;
const int MOD = 1e9+7;

int fat[MAXN], inv[MAXN];

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void fact(){
    fat[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = (fat[i-1] * i) % MOD;
        inv[i] = fastexpo(fat[i], MOD-2);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    fact();

    while(t--){
        int a, b;
        cin >> a >> b;

        int ans = (fat[a] * inv[b]) % MOD;
        ans = (ans * inv[a-b]) % MOD;
        cout << ans << endl;
    }
}
