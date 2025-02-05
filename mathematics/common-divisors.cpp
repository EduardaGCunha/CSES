#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
const int MAXN = 2*(1e6+1);
int divisors[MAXN]; 

int main(){
    fastio;
    int n; cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mx = max(mx, x);
        for(int j = 1; j*j <= x; j++){
            if(!(x%j)){
                divisors[j]++;
                if(j != x/j) divisors[x/j]++;

                //cout << j << " " << x/j << endl;
            }
        }
    }

    for(int i = mx; i >= 1; i--){
        //cout << i << " " << divisors[i] << endl;
        if(divisors[i] >= 2){
            cout << i << endl;
            return 0;
        }
    }
}