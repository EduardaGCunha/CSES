#include <bits/stdc++.h>
using namespace std;

#define int long long

int fastexpo(int a, int b, int MOD){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b/=2;
    }

    return res;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int MOD = 1e9+7;
        int val = fastexpo(b, c, MOD-1);
        cout << fastexpo(a, val, MOD) << endl;
    }
}