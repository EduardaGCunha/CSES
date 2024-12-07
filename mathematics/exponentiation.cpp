#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;

void fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b/=2;
    }

    cout << res << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        fastexpo(a, b);
    }
}