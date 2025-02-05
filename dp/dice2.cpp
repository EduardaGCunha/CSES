#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int fast_expo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b = (b/2);
    }
    return res;
}

signed main(){
    int n; cin >> n;
    cout << fast_expo(2, n-1) << endl;
}