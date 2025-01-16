#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6;
int join[MAXN], sep[MAXN];
const int MOD = 1e9+7;

signed main(){
    join[0] = 1;
    sep[0] = 1;

    for(int i = 1; i < MAXN; i++){
        join[i] = (1LL*join[i-1]*2 + sep[i-1])%MOD;
        sep[i] = (1LL*4*sep[i-1] + join[i-1])%MOD;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (1LL*join[n-1] + sep[n-1])%MOD << endl;
    }
}