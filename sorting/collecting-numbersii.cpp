#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, int> mp;

void solve(){
    int cnt = 0, val = 0;
    while(val < n){
        if(mp[val] < mp[val+1]) cnt++;
        val++;
    }
    cout << cnt << endl;
}

int main(){
    cin >> n >> m;
    map<int, int> idx;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x] = i;
        idx[i] = x;
    }


    while(m--){
        int a, b;
        cin >> a >> b;
        int temp = mp[idx[b]];
        mp[idx[b]] = mp[idx[a]];
        mp[idx[a]] = temp;
        temp = idx[b];
        idx[b] = idx[a];
        idx[a] = temp;

        for(auto u : mp){
            cout << "val: " << u.first << " idx: " << u.second << endl;
        }
        for(auto u : idx){
            cout << "idx: " << u.first << " val: " << u.second << endl;
        }
        solve();
    }
}